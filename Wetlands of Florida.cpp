//469
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
//#include <boost/algorithm/string/split.hpp>
using namespace std;

vector<vector<char>> matrix;
vector<vector<int>> checked;
char letter;
int area;

//Recursively checks and returns the area of the water (W) from the matrix
//requires row and column coordinates.
//returns area as integer
int check(int r, int c)
{
	if (matrix[r][c] != 'W' || checked[r][c])
		return 0;
	else{
		checked[r][c] = 1;
		return (1 + check(r + 1, c - 1) + check(r + 1, c) + check(r + 1, c + 1)
			+ check(r, c - 1) + check(r, c + 1) +
			check(r - 1, c - 1) + check(r - 1, c) + check(r - 1, c + 1));
	}
}


int main()
{
	int test, length, n, i, j;
	string line;
	cin >> test;
	cin.ignore(); getchar();
	getline(cin, line);
	while (test--)
	{
		n = 0;
		int length = line.size() + 2;
		matrix.clear();
		checked.clear();
		matrix.resize(1, vector<char>(length));
		
		//adds a top to the boundary box
		for (i = 0; i < length; i++)
		{
			matrix[n][i] = '0';
		}
		n++;
		//places the grid in a 2D vector called matrix
		//also adds 0 to front and back of each array to form
		//a boundary box to make checks easier
		while (line[0] == 'L' || line[0] == 'W')
		{
			matrix.resize(n+1, vector<char>(length, 0));
			matrix[n][0] = '0';
			for (i = 0; i < line.size(); i++)
				matrix[n][i + 1] = line[i];
			matrix[n][line.size()+1] = '0';
			n++;
			getline(cin, line);
		}
		//adds a bottom to the boundary box
		for (i = 0; i < length; i++)
		{
			matrix.resize(n + 1, vector<char>(length, 0));
			matrix[n][i] = '0';
		}

		//This checks the area given the row and col of the matrix
		while (line != "")
		{
			//reinitialize each check matrix values to zeros
			checked.resize(n+1, vector<int>(length));
			for (i = 0; i <= n; i++)
			{
				for (j = 0; j < length; j++)
					checked[i][j] = 0;
			}
			istringstream buf(line);
			istream_iterator<string> beg(buf), end;
			vector<string> splitted(beg, end);
			i = atoi(splitted[0].c_str());
			j = atoi(splitted[1].c_str());
			area = 0;
			area = check(i, j);
			cout << area << '\n';
			if (cin.eof())
				break;
			getline(cin, line);
		}
		if(!cin.eof())
			cout << '\n';
		getline(cin, line);
	}
	return 0;
}

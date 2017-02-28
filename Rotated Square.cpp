/*////////////////////////////////////////////////

Nathan Durst	:	nadurst0303
Project 7 - Rotated Square - UVa #10855
Programming Techiques - Simpson
February 3, 2017

*////////////////////////////////////////////////


#include <iostream>
#include <vector>
using namespace std;

//rotate90 function takes the smaller square of characters and shifts
// values so that it appears that the square has rotated 90 degrees to
// the right. it takes the 2x2 matrix and returns the rotated 2x2 matrix
vector<vector<char>> rotate90(vector<vector<char>> v);

//check function uses the rotate90 function by checking if the small matrix
// appears in the large matrix for 0, 90, 180, and 270 degree rotations. It
// also prints out the results from this function. It takes the size of the
// big matrix, the big matrix (vector) and the original small matrix (2x2 vector);
void check(int size, vector<vector<char>> b, vector<vector<char>> s);

int main()
{
	int a, b, i, j;
	vector<vector<char>> big(10, vector<char>(10));
	vector<vector<char>> small(10, vector<char>(10));
	cin >> a >> b;
	while (a != 0 && b != 0)
	{
		//reads in data for big square
		for (i = 0; i < a; i++)
		{
			for (j = 0; j < a; j++)
				cin >> big[i][j];
		}

		//reads in data for large square
		for (i = 0; i < b; i++)
		{
			for (j = 0; j < b; j++)
			{
				cin >> small[i][j];
			}
		}

		//checks the normal, unrotated square first
		check(a, big, small);

		//checks 3 times (90, 180, and 270)
		for (i = 0; i < 3; i++)
		{
			small = rotate90(small);
			check(a, big, small);
		}

		cout << '\n';
		cin >> a >> b;
	}

	return 0;
}

vector<vector<char>> rotate90(vector<vector<char>> v)
{
	char temp;
	temp = v[0][0];
	v[0][0] = v[1][0];
	v[1][0] = v[1][1];
	v[1][1] = v[0][1];
	v[0][1] = temp;

	return v;

}

void check(int size, vector<vector<char>> b, vector<vector<char>> s)
{

	int appearances = 0;
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (s[0][0] == b[j][i] && s[1][0] == b[j + 1][i] &&
				s[0][1] == b[j][i + 1] && s[1][1] == b[j + 1][i + 1])
			{
				appearances++;
			}
		}
	}

	cout << appearances << " ";

}
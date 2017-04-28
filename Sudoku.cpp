/*////////////////////////////////////////////////

Nathan Durst	:	nadurst0303
Project 28 - Sudoku - UVa 13115
Programming Techiques - Simpson
April 28, 2017

*////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;

int main()
{
	int T, N, col, row, i, j, num, sum, temp, sqrtN;
	bool correct;
	vector<vector<int>> Grid;
	cin >> T;
	while (T--)
	{
		cin >> N;
		vector<vector<int>> Grid(N, vector<int> (N));
		sum = 0; sqrtN = sqrt(N); correct = true;

		for (i = 1; i <= N; i++)
			sum = sum + i;

		//read in and put in grid
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
			{
				cin >> Grid[i][j];
			}
		}

		//checks by each row and by each column
		temp = 0;
		for (i = 0; i < N; i++)
		{
			temp = 0;
			for (j = 0; j < N; j++)
			{
				temp = temp + Grid[i][j] + Grid[j][i];
			}
			if (temp != sum * 2)
				correct = false;
		}

		//check by each square
		//	there are N squares and each square
		//	has N numbers with sqrtN by sqrtN dimensions
		for (row = 0; row < N; row += sqrtN){
			for (col = 0; col < N; col += sqrtN){
				temp = 0;
				for (i = row; i < row + sqrtN; i++){
					for (j = col; j < col + sqrtN; j++){
						temp = temp + Grid[i][j];
					}
				}
				if (temp != sum)
					correct = false;
			}
		}

		//output results
		if (correct == false)
			cout << "no\n";
		else
			cout << "yes\n";
	}



	return 0;
}
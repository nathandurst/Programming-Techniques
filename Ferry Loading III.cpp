/*////////////////////////////////////////////////

Nathan Durst	:	nadurst0303
Project 12 - Ferry Loading III - UVa #10901
Programming Techiques - Simpson
February 26, 2017

*////////////////////////////////////////////////

#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

const int LEFT = 0;
const int RIGHT = 1;
struct data
{
	int index;
	int minute;
};

int main()
{
	//N: cars on ferry, T: crosstime, M: cars to be loaded
	int test, N, T, M, minute, time, onferry, loc;
	string side;

	cin >> test;
	while (test--)
	{
		cin >> N >> T >> M;
		vector<queue<data>> Bank(2);	//LEFT & RIGHT Banks
		vector<int> Ferry(M);			//Holds values to be printed

		//load cars on LEFT or RIGHT sides of the bank
		for (int i = 0; i < M; i++)
		{
			cin >> minute >> side;
			data temp; temp.index = i; temp.minute = minute;
			if (side == "left")
				Bank[LEFT].push(temp);
			else
				Bank[RIGHT].push(temp);
		}

		//Ferry starts on left bank
		time = 0; loc = LEFT;
		while (! (Bank[LEFT].empty() && Bank[RIGHT].empty()))
		{
			//ferry waits for next car to arrive on either bank
			int nextcar = 0;
			if (!Bank[LEFT].empty())
				nextcar = Bank[LEFT].front().minute;
			if (!Bank[RIGHT].empty() && Bank[RIGHT].front().minute < nextcar)
				nextcar = Bank[RIGHT].front().minute;

			//time moves to be same as next car if neccessary
			if (time < nextcar)
				time = nextcar;

			//moves cars back and forth as long as ferry is not empty, not full
			// and there are still cars to be moved on bank
			onferry = 0;
			while (!Bank[loc].empty() && onferry < N
				&& Bank[loc].front().minute <= time)
			{
				//remove car from Bank and place on Ferry
				Ferry[Bank[loc].front().index] = time + T;
				Bank[loc].pop();
				onferry++;
			}
			time += T; loc ^= 1;
		}

		//print out times for each car after ferry ride
		for (int i = 0; i < M; i++)
			cout << Ferry[i] << '\n';
		cout << '\n';
	}

	return 0;
}
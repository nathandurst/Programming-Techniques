//***********************************
//Nathan Durst	:	nadurst0303
//Cacho	:	inclass	:	uva 13130
//May 2, 2017
//***********************************

#include <vector>
#include <iostream>
#include <string>
using namespace std;

//iterates through the vector and retruns true if
//and escala defined by the problem and falst if not
bool check(vector<int> v)
{
	int temp = v[0];
	for (int i = 1; i < 5; i++)
	{
		if (v[i] != temp + 1)
			return false;
		temp++;
	}
	return true;
}

int main()
{
	int T, temp;
	string line;
	bool escala;

	//read in with cin or getline
	//cin >> T;
	getline(cin, line);

	//convert character to integer with the getline
	//solution
	T = stoi(line);
	//*********************************************

	for (int i = 0; i < T; i++)
	{
		vector<int> E(5);
		escala = true;
		
		//read in with cin or with getline
		//cin >> E[0] >> E[1] >> E[2] >> E[3] >> E[4];
		getline(cin, line);
		int j = 0;

		//this is used only in the getline solution to convert
		//the string to a vector
		for (int i = 0; i < 5; i++)
		{
			E[i] = line[j] - '0';
			j += 2;
		}
		//****************************************************

		//checks vector to see if it is an escala
		//returns boolean
		escala = check(E);

		if (escala == false)
			cout << "N\n";
		else
			cout << "Y\n";

	}
	return 0;
}

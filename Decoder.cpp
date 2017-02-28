/*////////////////////////////////////////////////

Nathan Durst	:	nadurst0303
Project 4 - The Decoder - UVa 458
Programming Techiques - Simpson
January 26, 2017

*////////////////////////////////////////////////

#include <iostream>
using namespace std;

int main()
{
	char message[255], c;
	while (cin >> message)
	{
		for (int i = 0; message[i] != '\0'; i++)
			cout << char(message[i] - 7);
		cout << '\n';
	}
	return 0;
}
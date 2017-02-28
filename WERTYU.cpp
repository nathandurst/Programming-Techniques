/*////////////////////////////////////////////////

Nathan Durst	:	nadurst0303
Project 3 - WERTYU - UVa # 10082
Programming Techiques - Simpson
January 26, 2017

*////////////////////////////////////////////////

#include <iostream>
#include <string>
using namespace std;

int main()
{
	char KEY[] =  "`1234567890-=QWERTYUIOP[]\ASDFGHJKL;'ZXCVBNM,./";
	string message;
	int i, j, k;

	while (getline(cin, message))
	{
		for (i = 0; i < message.size(); i++)
		{
			if (message[i] == ' ') cout << ' ';
			else
			{
				for (j = 0; j < 47; j++)
				{
					if (message[i] == KEY[j])
					{
						cout << KEY[j-1];
					}
				}

			}
		}
		cout << '\n';

	}

	return 0;
}


//13131
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
	int T, N, K, sroot, sum;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		vector<int> divisors;
		sum = 0;
		cin >> N >> K;
		sroot = (int)sqrt(N);
		for (int j = 1; j <= sroot; j++)
		{
			if (N % j == 0 && j*j != N)
			{
				divisors.push_back(j);
				divisors.push_back(N / j);
			}
			if (j*j == N)
				divisors.push_back(j);

		}
		
		for (int j = 0; j < divisors.size(); j++)
		{
			if (divisors[j] % K != 0)
				sum += divisors[j];
		}
		cout << sum << '\n';
	}


	return 0;
}
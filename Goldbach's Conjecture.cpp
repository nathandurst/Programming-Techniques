/*////////////////////////////////////////////////

Nathan Durst	:	nadurst0303
Project 17 - Goldbach's Conjecture - UVa #543
Programming Techiques - Simpson
March 1, 2017

*////////////////////////////////////////////////

#include <iostream>
#include <bitset>
#include <vector>
#include <cstdint>
using namespace std;

typedef uint32_t ll;
ll _sieve_size;
bitset<10000010> bs;
vector<int> primes;

void sieve(ll upperbound)
{
	_sieve_size = upperbound + 1;
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i = 2; i <= _sieve_size; i++)
	{
		if (bs[i])
		{
			for (ll j = i*i; j <= _sieve_size; j += i)
				bs[j] = 0;
			primes.push_back((int)i);
		}
	}
}

bool isPrime(int n)
{
	for (int i = 0; i < primes.size() && primes[i] <= n; i++)
	{
		if (n == primes[i])
			return true;
	}
	return false;
}

int main()
{
	sieve(10000000);
	int n, a, b;
	cin >> n;
	while (n != 0)
	{
		for (int i = 1; i < primes.size(); i++)
		{
			a = primes[i];
			b = n - a;
			if (isPrime(b))
			{
				cout << n << " = " << a << " + " << b << '\n';
				break;
			}
		}
		cin >> n;
	}

	return 0;
}
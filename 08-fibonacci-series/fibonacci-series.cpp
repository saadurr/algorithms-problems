#include <iostream>
#include <map>
using namespace std;

namespace recursive
{
	long long FibonacciNumber(long long n)
	{
		if (n <= 2)
			return 1;

		return FibonacciNumber(n - 1) + FibonacciNumber(n - 2);
		//Time complexity is 2^n
	}
}

namespace loop
{
	long long FibonacciNumber(long long n)
	{
		if (n <= 2)
			return 1;

		long long sumTot = 0, sumCurr = 1, sumPrev = 0;

		for (int i = 2; i <= n; ++i)
		{
			sumTot = sumCurr + sumPrev;
			
			sumPrev = sumCurr;
			sumCurr = sumTot;
		}

		return sumTot;
	}
}

namespace recursivememo
{
	static map<long long, long long> fibMap;

	long long FibonacciNumber(long long n)
	{
		if (fibMap.count(n))
			return fibMap[n];

		if (n <= 2)
			return 1;

		fibMap[n] = FibonacciNumber(n - 1) + FibonacciNumber(n - 2);
		return fibMap[n];
	}
}

int main()
{
	long long x = recursive::FibonacciNumber(5);
	cout << x << endl;

	long long y = loop::FibonacciNumber(100);
	cout << y << endl;

	long long z = recursivememo::FibonacciNumber(100);
	cout << z << endl;

	return 0;
}
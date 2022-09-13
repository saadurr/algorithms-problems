#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<long int> FindDigits(long int n)
{
	vector<long int> digits;
	while (n != 0)
	{
		digits.push_back(n%10);
		n = n / 10;
	}

	return digits;
}

bool ValidateNumber(vector<long int> nDigits, vector<long int> iDigits)
{
	sort(nDigits.begin(), nDigits.end());
	sort(iDigits.begin(), iDigits.end());

	for (int i = 0; i < nDigits.size(); ++i)
		if (find(iDigits.begin(), iDigits.end(), nDigits[i]) != iDigits.end())
			return false;
	
	return true;
}

long next(int n)
{
	long long max = pow(2, 31);
	if (n > max)
		return -1; // greater than max
	if (n <= 0)
		return 1;

	vector<long int> nDigits = FindDigits(n);

	for (long int i = n; i < max; ++i)
	{
		vector<long int> iDigits = FindDigits(i);
		if (i > n && ValidateNumber(nDigits,iDigits))
			return i;
	}

	return -1;
}


int main()
{
	int n = -1;
	cin >> n;
	std::cout << "Next number for " << n << " which does not have any repeating digits is " <<  next(n) << std::endl;
	return 0;
}
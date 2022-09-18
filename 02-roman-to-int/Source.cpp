#include <iostream>
#include <string>
#include <map>
using namespace std;

map<char, int> valMap =
{
	{'I',1},
	{'V',5},
	{'X',10},
	{'L',50},
	{'C',100},
	{'D',500},
	{'M',1000}
};

bool IsSubtractionCase(char c1, char c2, int& val)  //can add value as reference too
{
	if ((c1 == 'I') && (c2 == 'V' || c2 == 'X'))
	{
		val += (valMap[c2] - 1);
		return true;
	}

	if ((c1 == 'X') && (c2 == 'L' || c2 == 'C'))
	{
		val += (valMap[c2] - 10);
		return true;
	}

	if ((c1 == 'C') && (c2 == 'D' || c2 == 'M'))
	{
		val += (valMap[c2] - 100);
		return true;
	}

	return false;
}



int RomanToInt(string s)
{
	int number = 0;
	bool skipNext = false;

	for (int i = 0; i < s.length(); ++i)
	{
		if (skipNext)
		{
			skipNext = false;
			continue;
		}

		if ((i < s.length() - 1) && IsSubtractionCase(s[i], s[i + 1], number))
		{
			skipNext = true;
		}
		else
			number += valMap[s[i]];
	}

	return number;
}

int main()
{
	string s = "MCMXCIV";
	cout << RomanToInt(s) << endl;
	return 0;
}
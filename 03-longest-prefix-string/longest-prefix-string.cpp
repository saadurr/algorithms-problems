#include <iostream>
#include <string>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string>& strs) 
{
	if (strs.size() <= 1)
		return strs[0];

	string prefix = "";
	bool add = false, finish = false;

	for (int i = 0; i < strs[0].size(); ++i)
	{
		if (finish)
			return prefix;

		for (const auto& s : strs)
		{
			if (s[i] == strs[0][i])
				add = true;
			else
			{
				add = false;
				finish = true;
				break;
			}
		}

		if(add) prefix += strs[0][i];
	}

	return prefix;
}

string longestCommonSubstring(vector<string>& strs)
{
	if (strs.size() <= 1)
		return strs[0];

	string prefix = "";
	string tPrefix = "";
	unsigned int count = 0, tCount = 0;
	bool add = false;

	for (int i = 0; i < strs[0].size(); ++i)
	{
		for (const auto& s : strs)
		{
			if (s.find(strs[0][i]) != string::npos)
				add = true;
			else
			{
				add = false;
				break;
			}
		}
		if (add)
		{
			tPrefix += strs[0][i];
			++tCount;
		}
		else
		{
			if (tCount > count)
			{
				prefix = tPrefix;
				tPrefix = "";
				count = tCount;
				tCount = 0;
			}
		}
	}
	return prefix;
}

int main()
{
	vector<string> strs = { "flower", "flow", "flight" };
	//vector<string> strs = { "cir", "car" };
	//vector<string> strs = { "a"};
	//vector<string> strs = { "aa", "ab" };
	cout << longestCommonPrefix(strs) << endl;
	return 0;
}
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

map<char, char> m =
{
	{')','('},
	{'}','{'},
	{']','['}
};

bool isValid(string s) 
{
	string openParantheses = "[{(";
	string closedParantheses = "]})";
	int count = 0;

	vector<char> parantheses;

	for (int i = 0; i < s.size(); ++i)
	{
		if (openParantheses.find(s[i]) != string::npos) //exists in openparantheses
		{
			parantheses.push_back(s[i]);
			++count;
		}
		else if (closedParantheses.find(s[i]) != string::npos)
		{
			if (!parantheses.empty())
			if (m[s[i]] == parantheses.back())
				parantheses.pop_back();
			--count;
		}
	}

	if (parantheses.empty() && count == 0)
		return true;
	else
		return false;
}

int main()
{
	string s = "({})";
	cout << isValid(s) << endl;
	return 0;
}
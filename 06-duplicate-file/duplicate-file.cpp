#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct file
{
	string mName;
	string mPath;
	string mContents;

	file(string name, string path, string contents) : mName(name), mPath(path), mContents(contents) {}

	friend bool operator==(const file& f1, const file& f2)
	{
		return f1.mContents == f2.mContents;
	}
};

void ParseFiles(const vector<string>& paths, vector<file>& files)
{
	for (int i = 0; i < paths.size(); ++i) // iterate over paths vector
	{
		string path, fileName, fileContent;
		unsigned int tokenCount = 0;
		for (int j = 0; j < paths[i].size(); ++j) // iterate over path stirng
		{
			if (tokenCount == 0)
			{
				path += paths[i][j];
				if (paths[i][j] == ' ')
				{
					++tokenCount;
					continue;
				}
			}
			else
			{
				if (paths[i][j] == ' ')
				{
					tokenCount = 1; // read filename
					continue;
				}
				else if (paths[i][j] == '(')
				{
					tokenCount = 2; // start reading contents
					continue;
				}
				else if (paths[i][j] == ')')
				{
					tokenCount = 3; // end reading contents
				}

				if (tokenCount == 1)
				{
					fileName += paths[i][j];
				}
				else if (tokenCount == 2)
				{
					fileContent += paths[i][j];
				}
				else if (tokenCount == 3)
				{
					files.emplace_back(file(fileName, path, fileContent));
				}
			}

		}
	}
}

vector<vector<string>> findDuplicate(vector<string>& paths)
{
	vector<file> files;
	vector<vector<string>> duplicates;

	ParseFiles(paths, files);

	for (int i = 0; i < files.size(); ++i)
	{
		vector<string> singleDuplicate;
		int duplicateCount = 0;
		for (int j = 0; j < files.size(); ++j)
		{
			if (i == j)
				continue;
			if (files[i] == files[j])
			{
				if (duplicateCount == 0)
					singleDuplicate.emplace_back(files[i].mPath + files[i].mName);

				++duplicateCount;
				singleDuplicate.emplace_back(files[j].mPath + "/" + files[j].mName);
			}
				
		}

		if (duplicateCount > 0)
			duplicates.push_back(singleDuplicate);
	}

	return duplicates;
}

int main()
{
	vector<string> paths = { "root/a 1.txt(abcd) 2.txt(efgh)","root/c 3.txt(abcd)","root/c/d 4.txt(efgh)","root 4.txt(efgh)" };
	vector<vector<string>> duplicates = findDuplicate(paths);

	for (auto x : duplicates)
	{
		for (auto y : x)
			cout << y << " ";
		cout << "\n\n";
	}
	
	return 0;
}
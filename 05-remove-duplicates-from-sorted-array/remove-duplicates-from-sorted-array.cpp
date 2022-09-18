#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int removeDuplicates(vector<int>& nums) 
{
	auto it = unique(nums.begin(), nums.end());

	return distance(nums.begin(), it);
}

int main()
{
	vector<int> num = { 1,2,3,4,5,6,6,6,7,7,7 };
	removeDuplicates(num);
	return 0;
}
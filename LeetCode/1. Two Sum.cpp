#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		vector<int> result;

		int input_size = nums.size();
		for (size_t i = 0; i < input_size; i++)
		{
			for (size_t j = i + 1; j < input_size; j++)
			{
				if (nums[i] + nums[j] == target)
				{
					result.push_back(i);
					result.push_back(j);
					return result;
				}
			}
		}

		return result;
	}
};

int main()
{
	Solution p;
	vector<int> nums = { 2,7,11,15 };
	vector<int> result = p.twoSum(nums, 9);

	return 0;
}

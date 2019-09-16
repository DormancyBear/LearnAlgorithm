#include <iostream>
#include <vector>

using namespace std;

// 因为题目要求的是一个连续的子字符串, 所以可以用一个滑动窗口, 一步一步往后移
class Solution
{
public:
	int lengthOfLongestSubstring(string s)
	{
		int start_index = 0, end_index = 0, max_length = 0;

		for (; end_index < s.length(); ++end_index)
		{
			for (size_t j = start_index; j < end_index; j++)
			{
				if (s[j] == s[end_index])
				{
					// 碰到这个重复字符之前的最大长度
					int interval_length = end_index - start_index;
					if (interval_length > max_length)
					{
						max_length = interval_length;
					}
					start_index = j + 1;
					break;
				}
			}
		}

		// 需要考虑: 最后一段子字符串没有碰到重复字符的情况, 如 "ssabc"
		int interval_length = end_index - start_index;
		if (interval_length > max_length)
		{
			max_length = interval_length;
		}

		return max_length;
	}
};

int main()
{
	Solution p;
	int result = p.lengthOfLongestSubstring("cdd");

	return 0;
}

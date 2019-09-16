#include <iostream>
#include <vector>

using namespace std;

// 最长回文子串
class Solution {
public:
	bool CheckPalindromic(string const & s, size_t temp_start, size_t temp_end)
	{
		while (temp_end > temp_start)
		{
			if (s[temp_start] != s[temp_end])
			{
				return false;
			}

			++temp_start;
			--temp_end;
		}

		return true;
	}

	string longestPalindrome(string s)
	{
		size_t result_start_index = 0, result_end_index = 0;

		for (size_t temp_start = 0, temp_end = s.length() > 0 ? s.length() - 1 : 0; temp_end > temp_start; --temp_end)
		{
			for (size_t j = temp_start; j < temp_end; ++j)
			{
				if (CheckPalindromic(s, j, temp_end))
				{
					if ((result_end_index - result_start_index) < (temp_end - j))
					{
						result_start_index = j;
						result_end_index = temp_end;
					}
				}
			}
		}

		return s.substr(result_start_index, result_end_index - result_start_index + 1);
	}
};

int main()
{
	Solution p;
	string result = p.longestPalindrome("abadd");

	return 0;
}

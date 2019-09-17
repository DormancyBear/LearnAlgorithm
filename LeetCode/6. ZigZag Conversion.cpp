#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	string convert(string s, int numRows)
	{
		string result;

		int z_interval = 2 * numRows - 2;
		// 需要考虑 numRows == 1 or 2, 即无法凑成 Z 字的情况
		if (z_interval <= 0)
		{
			z_interval = 1;
		}

		for (size_t i = 0; i < numRows; i++)
		{
			int target_index = i;
			if (target_index >= s.length())
			{
				break;
			}
			result += s[target_index];	// 打印每行的第一个字符

			// 每一个 Z 字再打印两个字符
			int character_interval = z_interval - 2 * i;
			while (target_index < s.length())
			{
				// 第一行和最后一行, 每个 Z 字会少一个字符
				if (character_interval > 0)
				{
					target_index += character_interval;
					if (target_index >= s.length())
					{
						break;
					}
					result += s[target_index];
				}

				character_interval = z_interval - character_interval;
			}
		}

		return result;
	}
};

int main()
{
	Solution p;
	string result = p.convert("abcasdfsad", 1);

	return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
	bool isPalindrome(int x)
	{
		if (x < 0)
		{
			return false;
		}
		else
		{
			vector<int> number_array;

			do
			{
				number_array.push_back(x % 10);
				x = x / 10;
			} while (x > 0);

			int low = 0, high = number_array.size() - 1;
			while (low < high)
			{
				if (number_array[low] != number_array[high])
				{
					return false;
				}
				else
				{
					++low;
					--high;
				}
			}

			return true;
		}
	}
};

int main()
{
	Solution p;
	bool result = p.isPalindrome(10);

	return 0;
}

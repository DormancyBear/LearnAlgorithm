#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int reverse(int x)
	{
		int result = 0;

		if (x >= 0)
		{
			do
			{
				int temp = x % 10;
				if (INT_MAX / 10 >= result)
				{
					result = result * 10;
				}
				else
				{
					return 0;
				}

				if (INT_MAX - result >= temp)
				{
					result += temp;
				}
				else
				{
					return 0;
				}
				x /= 10;
			} while (x > 0);
		}
		else
		{
			do
			{
				int temp = x % 10;
				if (INT_MIN / 10 <= result)
				{
					result = result * 10;
				}
				else
				{
					return 0;
				}

				if (INT_MIN - result <= temp)
				{
					result += temp;
				}
				else
				{
					return 0;
				}
				x /= 10;
			} while (x < 0);
		}
		

		return result;
	}
};

int main()
{
	Solution p;
	int result = p.reverse(-123);

	return 0;
}

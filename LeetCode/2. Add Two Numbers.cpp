#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;

	ListNode(int x) : val(x), next(nullptr) {}
};

// 最开始做题的时候没发现难点其实是大数加减, 直接用了个 int 类型来存,
// 结果提交的时候 testcase 里包含了几个超大的数 (链表所表达的数超出了整型数据所能存储的最大范围)
// 这时候才发现这个问题的真正考点 Orz
class FailedSolution
{
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		int num1, num2, multiple_num;

		num1 = 0;
		multiple_num = 1;
		while (l1 != nullptr)
		{
			num1 += l1->val * multiple_num;
			l1 = l1->next;
			multiple_num *= 10;
		}

		num2 = 0;
		multiple_num = 1;
		while (l2 != nullptr)
		{
			num2 += l2->val * multiple_num;
			l2 = l2->next;
			multiple_num *= 10;
		}

		int result_num = num1 + num2;
		ListNode *first{ nullptr }, *last{ nullptr };
		do
		{
			ListNode *temp = new ListNode(result_num % 10);
			result_num /= 10;

			if (first == nullptr)
			{
				first = temp;
			}
			if (last != nullptr)
			{
				last->next = temp;
			}
			last = temp;
		} while (result_num >= 1);

		return first;
	}
};

class Solution
{
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		int overflow_num = 0;
		ListNode *first{ nullptr }, *last{ nullptr };
		while (l1 != nullptr || l2 != nullptr || overflow_num != 0)
		{
			int num1 = l1 != nullptr ? l1->val : 0;
			int num2 = l2 != nullptr ? l2->val : 0;
			int add_num = num1 + num2 + overflow_num;
			overflow_num = add_num / 10;
			ListNode *temp = new ListNode(add_num % 10);

			if (first == nullptr)
			{
				first = temp;
			}
			if (last != nullptr)
			{
				last->next = temp;
			}
			last = temp;
			
			if (l1 != nullptr)
			{
				l1 = l1->next;
			}
			if (l2 != nullptr)
			{
				l2 = l2->next;
			}
		}

		return first;
	}
};

int main()
{
	Solution p;
	ListNode l1(9), l2(1), n2(9), n3(9), n4(9), n5(9), n6(9), n7(9), n8(9), n9(9), n10(9);
	l2.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;
	n5.next = &n6;
	n6.next = &n7;
	n7.next = &n8;
	n8.next = &n9;
	n9.next = &n10;
	ListNode *result = p.addTwoNumbers(&l1, &l2);
	while (result != nullptr)
	{
		ListNode *last = result;
		result = result->next;
		delete last;
	}

	return 0;
}

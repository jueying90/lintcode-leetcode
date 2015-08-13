#include <iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int val) 
	{
		this->val = val;
		this->next = NULL;
	}
}

/**
 * @param head: The first node of linked list.
 * @param x: an integer
 * @return: a ListNode 
 */
//思路：4个指针，分别记录两部分链表的头和尾，之后再合并链表
ListNode *partition(ListNode *head, int x) 
{
	// write your code here
	if (head == NULL)
		return head;
	ListNode *less = NULL, *less_tail = NULL;
	ListNode *larger = NULL, *larger_tail = NULL;
	ListNode *next = head;
	while (next != NULL)
	{
		if (next->val < x)
		{
			if (less == NULL)
			{
				less = next; 
				less_tail = less;
			}
			else
			{
				less_tail->next = next;
				less_tail = next;
			}
			next = next->next;
			less_tail->next = NULL;
		}
		else
		{
			if (larger == NULL)
			{
				larger = next;   
				larger_tail = larger;
			}
			else
			{
				larger_tail->next = next;   
				larger_tail = next;
			}
			next = next->next;
			larger_tail->next = NULL; 
		}
	}
	if (less == NULL)
		return larger;
	else
		less_tail->next = larger;
	return less;
}

int main()
{
	ListNode *head = new ListNode(1);
	ListNode *next  = new ListNode(1);
	head->next = next;
	partition2(head,2);
	getchar();
}
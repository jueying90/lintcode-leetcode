#include <iostream>
using namespace std;
//删除排序数组中的重复数字
//给定一个排序数组，在原数组中删除重复出现的数字，
//使得每个元素只出现一次，并且返回新的数组的长度。
//不要使用额外的数组空间，必须在原地没有额外空间的条件下完成。
//样例：
//给出数组A =[1,1,2]，你的函数应该返回长度2，此时A=[1,2]。
/**
 * @param A: a list of integers
 * @return : return an integer
 */
int removeDuplicates(vector<int> &nums) {
	// write your code here
	int dup = 0;
	int i = 0;
	int n = nums.size();
	for (int j = 1; j < n; j++)
	{
		while (j < n && nums[j] == nums[i])
		{
			j++;
			dup++;
		}
		if ((i+1) < n)
			nums[i+1] = nums[j];
		i++;
	}
	nums.resize(n-dup);
	return (n - dup);
}
int removeDuplicates_1(vector<int> &nums) {
	// write your code here
	int i = 0;
	int n = nums.size();
	for (int j = 1; j < n; j++)
	{
		if (nums[i] != nums[j])
		{
			nums[i+1] = nums[j];
			i += 1;
		}
	}
	return n > 0 ? (i+1):n;   
}
//删除排序数组中的重复数字 II
//跟进“删除重复数字”：
//可以允许出现两次重复将如何处理？
//样例
//给出数组A =[1,1,1,2,2,3]，你的函数应该返回长度5，此时A=[1,1,2,2,3]
/**
 * @param A: a list of integers
 * @return : return an integer
 */
int removeDuplicatesII(vector<int> &nums) {
	// write your code here
	int n = nums.size();
	int tail = 0,d = n;
	for (int i = 1; i < n; i++)
	{
		int dup = 0;
		while (i < n && nums[i] == nums[tail])
		{
			dup++;
			i++;
		}
		if (dup >= 1)
		{
			nums[tail+1] = nums[tail];
			nums[tail+2] = nums[i];
			tail += 2;
			d = d - dup + 1;
		}
		else
		{
			nums[tail+1] = nums[i];
			tail += 1;
		}
	}
	return d;
}
//用一个变量标志每个数重复次数是否超过两次
int removeDuplicatesII_2(vector<int> &nums) {
	// write your code here
	int n = nums.size();
	int begin = 0, dup = 0;
	for (int i = 1; i < n; i++)
	{
		if (nums[begin] == nums[i])
		{
			if (dup == 0)
			{
				begin += 1;
				nums[begin] = nums[i];
				dup = 1;
			}
		}
		else
		{
			begin += 1;
			nums[begin] = nums[i];
			dup = 0;
		}
	}
	return n > 0 ? (begin+1):n;
}
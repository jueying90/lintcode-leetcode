#include<iostream>
#include<vector>
using namespace std;
//给定一个整数数组，找到一个和最接近于零的子数组。返回第一个和最有一个指数。
//你的代码应该返回满足要求的子数组的起始位置和结束位置
//样例
//给出[-3, 1, 1, -3, 5]，返回[0, 2]，[1, 3]， [1, 1]， [2, 2] 或者 [0, 4]
//挑战
//O(nlogn)的时间复杂度
//直接枚举法：O(n*n)
vector<int> subarraySumClosest(vector<int> &nums)
{
	int n = nums.size();
	int cur_dis = INT_MAX;
	vector<int> index(2,-1);
	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		for (int j = i; j < n; j++)
		{
			sum += nums[j];
			if (abs(sum) <= cur_dis)
			{
				cur_dis = abs(sum);
				index[0] = i;
				index[1] = j;
				cout << index[0] << " " << index[1] << endl;
			}
		}			
	}
	return index;
}
//连续数组的和是求前缀和之间的差，要求和最接近于零，
//即两个前缀和要最接近，所以思路是对前缀和进行排序，
//相邻两项比较得出结果
//注意保存前缀和时同时保存下标
vector<int> subarrayClosest(vector<int> &nums)
{
	int n = nums.size();
	int cur_dis = INT_MAX;
	vector<int> index(2, -1);
	vector<pair<int, int> > sums(n, make_pair(0,-1));
	int sum = 0;
	//保存前缀和
	for (int i = 0; i < n; i++)
	{
		sum += nums[i];
		sums[i] = make_pair(sum,i);
	}
	//前缀和排序
	sort(sums.begin(), sums.end());
	//排序后的前缀和相邻两项进行比较
	for (int i = 1; i < n; i++)
	{
		int dif = abs(sums[i].first - sums[i - 1].first);
		if (dif < cur_dis)
		{
			cur_dis = dif;
			index[0] = min(sums[i].second,sums[i-1].second)+1;
			index[1] = max(sums[i].second, sums[i - 1].second);
			cout << index[0] << " " << index[1] << endl;
		}
	}
	return index;
}
int main()
{
	vector<int> nums = { 101, 33, 44, 55, 67, 78, -101, 33, -44, 55, -67, 78, -100, 200, -1000, 22, 100, 200, 1000, 22 };
	//subarraySumClosest(nums);
	subarrayClosest(nums);
	return 0;
}
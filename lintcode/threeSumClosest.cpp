#include<iostream>
#include<vector>
using namespace std;
/**
 * @param numbers: Give an array numbers of n integer
 * @param target: An integer
 * @return: return the sum of the three integers, the sum closest target.
 */
//思路同three-sum问题，只是每次记录和与target之差的绝对值
int threeSumClosest(vector<int> nums, int target) {
	// write your code here
	int len = nums.size();
	if (len < 3)
		return 0;
	sort(nums.begin(),nums.end());
	int closet = INT_MAX;
	int res;
	for (int i = 0; i < len -2; i++)
	{
		if (i != 0 && nums[i] == nums[i-1])
			continue;
		int a = nums[i];
		int low = i + 1, high = len -1;
		while (low < high)
		{
			int sum = a+nums[low]+nums[high];
			int dis = abs(sum - target);
			if (sum == target)
			{
				return target;
			}
			else
			if(sum < target)
			{
				while (low < high && nums[low] == nums[low+1])
					low++;
				low++;
			}
			else
			{
				while (low < high && nums[high] == nums[high-1])
					high--;      
				high--;
			}
			if (closet > dis)
			{
				closet = dis;
				res = sum;
			}
		}
	}
	return res;
}
int main()
{
	vector<int> nums = { -2, 0, 1, 1, 2 };
	cout << threeSumCloset(nums, 1) << endl;
	return 0;
}
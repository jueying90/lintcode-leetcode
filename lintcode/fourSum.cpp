#include<iostream>
#include<vector>
using namespace std;
/**
 * @param numbers: Give an array numbersbers of n integer
 * @param target: you need to find four elements that's sum of target
 * @return: Find all unique quadruplets in the array which gives the sum of 
 *          zero.
 */
//外加两层循环，然后双索引法求twoSum
vector<vector<int> > fourSum(vector<int> nums, int target) {
	// write your code here
	sort(nums.begin(),nums.end());
	vector<vector<int> > res;
	vector<int> four(4,0);
	int n = nums.size();
	if (n < 4)
		return res;
	for (int i = 0; i < n-3; i++)
	{
		//去重
		if (i!= 0 && nums[i] == nums[i-1])
			continue;
		for (int j = i + 1; j < n-2; j++)
		{
			//去重
			if (j!= i+1 && nums[j] == nums[j-1])
			   continue;
			int a = nums[i], b = nums[j];
			int low = j+1, high = n - 1;
			while (low < high)
			{
				int sum = a + b + nums[low] + nums[high];
				if (sum == target)
				{
					four[0] = a;
					four[1] = b;
					four[2] = nums[low];
					four[3] = nums[high];
					res.push_back(four);
					//去重
					while (low < high && nums[low] == nums[low+1])
						low++;

					while (low < high && nums[high] == nums[high-1])
						high--;
					low++;
					high--;                        
				}
				else
				if (sum < target)
				{
					//去重
					while (low < high && nums[low] == nums[low+1])
						low++;
					low++;                            
				}
				else
				{
					//去重
					while (low < high && nums[high] == nums[high-1])
						high--;
					high--;                            
				}
			}
		}
	}
	return res;
}

int main()
{
	vector<int> nums = { -2, -3, 5, -1, -4, 5, -11, 7, 1, 2, 3, 4, -7, -1, -2, -3, -4, -5 };
	fourSum(nums, 2);
	return 0;
}
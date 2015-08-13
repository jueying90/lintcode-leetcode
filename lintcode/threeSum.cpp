#include<iostream>
#include<vector>
using namespace std;
/**
 * @param numbers : Give an array numbers of n integer
 * @return : Find all unique triplets in the array which gives the sum of zero.
 */
//外加一层循环，然后双索引法求twoSum
vector<vector<int> > threeSum(vector<int> &nums) {
	// write your code here
	int len = nums.size();
	vector<vector<int> > res;
	vector<int> three(3, -1);
	sort(nums.begin(), nums.end());
	for (int i = 0; i < len-1; i++)
	{	
		if (i != 0 && nums[i] == nums[i - 1])
			continue;
		int j = i+1, k = len - 1;
		int sub_sum = -nums[i];
		int sum;
		while (j < k)
		{
			sum = nums[j] + nums[k];
			if (sum == sub_sum)
			{
				three[0] = nums[i];
				three[1] = nums[j];
				three[2] = nums[k];
				res.push_back(three);
				while (j < k && nums[j] == nums[j + 1]) 
					j++;
				while (j < k && nums[k] == nums[k - 1])
					k--;
				j++;
				k--;
			}
			else
			if (sum < sub_sum)
			{				
				while (j < k && nums[j] == nums[j + 1]) 
					j++;
				j++;
			}
			else
			{				
				while (j < k && nums[k] == nums[k - 1])
					k--;				
				k--;
			}
		}
	}
	return res;
}

int main()
{
	vector<int> nums = { -2, 0, 1, 1, 2 };
	threeSum(nums);
	return 0;
}
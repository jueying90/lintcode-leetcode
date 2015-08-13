//原址操作:快排中的数组划分思想
int partitionArray(vector<int> &nums, int k) {
	// write your code here
	int n = nums.size();
	int left = 0;
	for (int i = 0; i < n; i++)
	{
		if (nums[i] < k)
		{
			if (left != i)
			{
				int tmp = nums[i];
				nums[i] = nums[left];
				nums[left] = tmp;
			}
			left += 1;
		}
		// for (int i = 0; i < n; i++)
		// {
			// cout << nums[i] << " ";
		// }
		// cout << endl;
	}
	return left;
}
        int n = nums.size();
        if (n < 1)
            return 0;
    	int left = 0, right = n - 1;
    	int res = 0;
    	while (left < right)
    	{
    		while (left < right && nums[left] < k)
    			left++;
    		while (left < right && nums[right] >= k)
    			right--;
    		if (left < right)
    		{
    			int tmp = nums[left];
    			nums[left] = nums[right];
    			nums[right] = tmp;
    		}
    	}
    	if (right == n - 1 && nums[left] < k)
    		res = right + 1;
    	else
            res = right;
    	return res;
}
int partitionArray1(vector<int> &nums, int k) {
	// write your code here
	int n = nums.size();
	if (n < 1)
		return 0;
	int left = 0, right = n - 1;
	int res = 0;
	while (left < right)
	{
		while (left < right && nums[left] < k)
			left++;
		while (left < right && nums[right] >= k)
			right--;
		if (left < right)
		{
			int tmp = nums[left];
			nums[left] = nums[right];
			nums[right] = tmp;
		}
	}
	if (right == n - 1 && nums[left] < k)
		res = right + 1;
	else
		res = right;
	return res;
}
int main()
{
	vector<int> nums = { 3,5,8,7,6,4 };
	cout << partitionArray(nums, 6) << endl;
	return 0;
}
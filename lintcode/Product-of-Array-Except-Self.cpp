//时间复杂度O(n*n)
vector<long long> productExceptItself(vector<int> &nums) {
	// write your code here
	int n = nums.size();
	vector<long long> B(n,1);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
			B[i] *= nums[j];
		for (int k = i+1; k < n; k++)
			B[i] *= nums[k];
	}
	return B;
}
vector<int> productExcludeItself(vector<int> &nums) {
	// write your code here
	int n = nums.size();
	vector<int> pros(n,1);
	for (int i = n - 1; i > 0; i--)
	{
		pros[i - 1] = pros[i] * nums[i];
	}
	for (int i = 0; i < n; i++)
	{
		cout << pros[i] << " ";
	}
	cout << endl;
	int left = 1;
	for (int j = 0; j < n; j++)
	{
		pros[j] *= left;
		left *= nums[j];
	}
	for (int i = 0; i < n; i++)
	{
		cout << pros[i] << " ";
	}
	cout << endl;
	return pros;
}

int main()
{
	vector<int> nums = { 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 4, 8, 1, 2, 3, 4, 0, 1, 1, 1, 1, 1, 1, 1, 9, 1, 8, 1, 1, 1, 1, 2, 2, 32, 8 };
	productExcludeItself(nums);
	getchar();
	return 0;
}
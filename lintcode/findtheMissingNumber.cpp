#include <iostream>
#include <vector>
using namespace std;

int findMissing(vector<int> &nums) {
	// write your code here
	int len = nums.size();
	int sum = 0;
	int miss_sum = 0;
	for (int i = 0; i < len; i++)
	{
		miss_sum += nums.at(i);
		sum += i;
	}
	sum = sum + len;
	return sum - miss_sum;
}
int main()
{
	vector<int> nums = {0, 1, 3};
	cout << findMissing(nums) << endl;
	return 0;
}
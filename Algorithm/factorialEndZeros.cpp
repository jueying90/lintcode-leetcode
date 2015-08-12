#include<iostream>
using namespace std;
//计算n的阶乘末尾零的个数
int factorialEndZeros1(int n)
{
	int nums = 0;
	for (int i = n; i > 1; i--)
	{
		int j = i;
		while (j % 5 == 0)
		{
			nums++;
			j /= 5;
		}
	}
	return nums;
}
int factorialEndZeros2(int n)
{
	int nums = 0;
	while (n)
	{
		nums += n / 5;
		n /= 5;
	}
	return nums;
}
int main()
{	
	cout << factorialEndZeros2(50) << endl;
	getchar();
	return 0;
}
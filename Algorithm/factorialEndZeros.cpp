#include<iostream>
using namespace std;
//计算n的阶乘末尾零的个数
//统计1~n数每个数的因式分解中5的指数，即该数一定是能被5整除的，然后求和即可
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
//Z={[N/5] + [N/5^2]+[N/5^3] + ...},5^k > N 时结束，[N/5^k] =0
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

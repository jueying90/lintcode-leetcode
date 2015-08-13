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
//给定n，那么先算能被5整除的数字有多少个。方法是计算n/5=a1，
//比如20/5=4,说明有4个被5整除的数字（5，10，15，20），
//然后计算n/25，统计一下被25整除的数字有多少个:
//方法是n/25=a2，由于他是25啊，有两个5，所以要算两次，
//被25整除的数字肯定被5整除，所以之前计算n/5的时候已经算过一次了。
//如此累计，n/125 = a3，需要算3次，减去重复计算的两次
//计算公式是N=a1 + a2*2-a2+a3*3-a3-a3...=a1+a2+a3+...就这样啦。给定n，
//需要循环[log5(n)+1]次，所以算法的复杂度是O(log n)的。
int factorialEndZeros2(int n)
{
	int nums = 0;
	while (n)
	{
		//nums += n / 5;
		//n /= 5;
		n /= 5;
		nums += n;//减少一次计算
	}
	return nums;
}
int main()
{	
	cout << factorialEndZeros2(50) << endl;
	getchar();
	return 0;
}

#include<iostream>
using namespace std;
//合并排序数组A、B到数组A
void mergeSortedArray(int A[], int m, int B[], int n) 
{
	// write your code here
	int i = 0;
	int j = m;
	while (j < m+n)
	{
		int pos = j, key = B[i];
		while (pos > 0 && A[pos-1] > key)
		{
			A[pos] = A[pos-1];
			pos--;
		}
		A[pos] = key;
		j++;
		i++;
	}
}

// 合并两个排序的整数数组A和B变成一个新的数组。
// 样例：
// 给出A=[1,2,3,4]，B=[2,4,5,6]，返回 [1,2,2,3,4,4,5,6]
// 挑战
// 你能否优化你的算法，如果其中一个数组很大而另一个数组很小？
vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
	// write your code here
	int m = A.size(), n = B.size();
	vector<int> merge(m + n, 0);
	int a = 0, b = 0;
	for (int i = 0; i < m + n; i++)
	{
		if (a < m && b < n)
		{
			if (A[a] < B[b])
				merge[i] = A[a++];
			else
				merge[i] = B[b++];
		}
		else
			if (a < m)
				merge[i] = A[a++];
			else
				if (b < n)
					merge[i] = B[b++];
	}
	return merge;
}
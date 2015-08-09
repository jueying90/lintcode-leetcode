#include <iostream>
using namespace std;
int binarySort(int nums[], int begin, int end, int n)
{
	int median = (begin + end) / 2;
	while (begin <= end)
	{
		if (nums[median] <= n)
			begin = median + 1;
		else
			end = median - 1;
		median = (begin + end) / 2;
	}
	return begin;
}
void mergeSortedArray(int A[], int m, int B[], int n) {
	// write your code here
	int move = 0;
	for (int i = 0; i < n; i++)
	{
		int pos = m + i;//插入位置
		for (int j = m - 1 + i; j >= move; j--)
		{
			if (A[j] <= B[i])
				break;
			else
				pos--;
		}
		for (int k = m + i; k > pos; k--)
			A[k] = A[k - 1];
		A[pos] = B[i];
		move = pos + 1;
	}
	for (int i = 0; i < m + n; i++)
		cout << A[i] << " ";
	cout << endl;
}
void mergeSorted(int A[], int m, int B[], int n) {
	// write your code here
	int move = 0;
	for (int i = 0; i < n; i++)
	{
		//int pos = m + i;//插入位置
		int pos = binarySort(A, move, m - 1 + i, B[i]);
		for (int k = m + i; k > pos; k--)
			A[k] = A[k - 1];
		A[pos] = B[i];
		move = pos + 1;
	}
	for (int i = 0; i < m + n; i++)
		cout << A[i] << " ";
	cout << endl;
}

int main()
{
	int A[10] = {9,10,11,12,13};
	int B[] = {4,5};
	mergeSortedArray(A,5,B,2);
	return 0;
}
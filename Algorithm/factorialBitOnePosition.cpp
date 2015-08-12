#include<iostream>
using namespace std;
int factorialBitOnePosition(int n)
{
	int pos = 0;
	while (n)
	{
		pos += n >> 1;
		n = n >> 1;
	}
	return pos+1;
}
int main()
{
	cout << factorialBitOnePosition(2) << endl;
	getchar();
	return 0;
}
//水仙花数
#include<iostream>
#include<vector>
using namespace std;
void narcissisticNumber(int m, int n)
{
	int flag = 0;
	for (int i = m; i <= n; i++)
	{
		int unit = i % 10;
		int decade = (i / 10) % 10;
		int hund = i / 100;
		if ((unit * unit * unit + decade * decade * decade + hund * hund * hund)
			== i)
		{
			if (flag == 1)
				cout << " ";
			cout << i;
			flag = 1;
		}
	}
	if (flag == 0)
		cout << "no";
	cout << endl;
}

int main()
{
	int m, n;
	vector< vector<int> > nums;
	vector<int> num(2,0);
	while (cin >> m, cin >> n)
	{	
		num[0] = m;
		num[1] = n;
		nums.push_back(num);		
	}
	for (int i = 0; i < nums.size(); i++)
	{
		narcissisticNumber(nums[i][0],nums[i][1]);
	}
	return 0;
}
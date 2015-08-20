#include<iostream>
#include<vector>
using namespace std;
int longestCommonString_1(string &A, string &B) {
	// write your code here
	int m = A.size(), n = B.size();
	int res = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n;)
		{
			int max = 0;
			int move = i;
			while (j < n && A[move] != B[j])
				j++;
			while (move < m && j < n && A[move++] == B[j++])
				max++;
			if (res < max)
				res = max;
		}
	}
	return res;
}
//DP思想
//如果xi == yj，则 c[i][j] = c[i-1][j-1]+1
//如果xi ! = yj，那么c[i][j] = 0
int longestCommonSubstring(string &A, string &B) {
	// write your code here
	int alen = A.size(), blen = B.size();
	vector<vector<int> > dp(alen+1, vector<int>(blen+1,0));
	int res = 0;
	for (int i = 0;i < alen; i++)
	{
		for (int j = blen-1; j >= 0; j--)
		{
			if (A[i] == B[j])
			{
				dp[i+1][j+1] = dp[i][j] + 1;
				if (res < dp[i+1][j+1])
					res = dp[i+1][j+1];
			}
			else
				dp[i+1][j+1] = 0;
		}
	}
	return res;
}
int main()
{
	string A = "www.lintcode.com code";
	string B = "www.ninechapter.com code";
	cout << longestCommonSubstr(A, B) << endl;
	return 0;
}
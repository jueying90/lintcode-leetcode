#include <iostream>
#include <vector>
using namespace std;
int selectTownChief(int n, int m, vector<pair<int, int> > &relation, vector<int> &res)
{
	vector<int> know(n, 0);
	vector<int> byknew(n, 0);
	int flag = 0;
	res.push_back(0);//合适的人选数
	for (int i = 0; i < m; i++)
	{
		if ((relation[i].first - 1) != (relation[i].second - 1))
		{
			know[relation[i].first - 1]++;
			byknew[relation[i].second - 1]++;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (know[i] == 0 && byknew[i] == n-1)
		{
			res[0]++;
			res.push_back(i + 1);
			//cout << i + 1 << endl;
			flag = 1;
		}
	}
	return flag;
}
int main(int argc, char* argv[])
{
	int T;
	while (cin >> T)
	{
		vector<vector<int> > res;
		while (T--)
		{
			int n, m;
			cin >> n;
			cin >> m;
			
			vector<pair<int, int> > relation;
			vector<int> line;
			pair<int, int> p;
			for (int k = 0; k < m; k++)
			{ 
				int i, j;
				cin >> i, cin >> j;
				p = make_pair(i, j);
				relation.push_back(p);
			}
			selectTownChief(n, m, relation,line);
			res.push_back(line);
		}
		for (int i = 0; i < res.size();i++)
		{ 
			vector<int> line = res[i];
			cout << line[0] << endl;
			if (line[0] == 0)
			{
				cout << endl;
				continue;
			}
			for (int j = 1; j < line.size(); j++)
				cout << line[j] << endl;
		}
	}
	getchar();
	return 0;
}
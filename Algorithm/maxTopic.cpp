#include <iostream>
#include <vector>
using namespace std;
int maxTopic(vector<int> &topics)
{
	int len = topics.size();
	int candidate;
	int flags = 0;
	for (int i = 0; i < topics.size(); i++)
	{
		if (flags == 0)
		{
			candidate = topics.at(i);
			flags = 1;
		}
		else
		{
			if (candidate == topics.at(i))
				flags++;
			else
				flags--;
		}

		cout << "flags = " << flags << endl;
	}
	//若恰好为发帖总数的1/2
	//int cTimes = 0;
	//int candidate2 = topics.at(len - 1);
	//for (int i = 0; i < len; i++)
	//{
	//	if (topics.at(i) == candidate)
	//	{
	//		cTimes++;
	//	}
	//}
	//return cTimes == len / 2 ? candidate : candidate2;
	return candidate;
}

int main()
{
	vector<int> topic_nums = {1,1,2,3,5,5,5,5,5,5,5,6,7};
	cout << maxTopic(topic_nums) << endl;
	return 0;
}
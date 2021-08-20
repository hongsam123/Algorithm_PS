//#include<iostream>
//#include<algorithm>
//#include<vector>
//#include<utility>
//using namespace std;
//
//bool comp(pair<int, int> a, pair<int, int> b)
//{
//	return a.first > b.first;
//}
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int n;
//	int c;
//	cin >> n >> c;
//
//	vector<pair<int, int>> v;
//	for (int i = 0; i < n; i++)
//	{
//		int x;
//		bool isused = false;
//		cin >> x;
//		if (v.empty()) 
//		{
//			v.push_back({ 1,x });
//			isused = true;
//		}
//		else
//		{
//			for (int j = 0; j < v.size(); j++)
//			{
//				if (v[j].second == x)
//				{
//					v[j].first++;
//					isused = true;
//					//break;
//				}
//			}
//		}
//		if (!isused)
//			v.push_back({ 1,x });
//	}
//
//	sort(v.begin(), v.end(), comp);
//
//	for (int i = 0; i < v.size(); i++)
//	{
//		for (int j = 0; j < v[i].first; j++)
//		{
//			cout << v[i].second << " ";
//		}
//	}
//
//	return 0;
//}
//위 풀이로 한시간을 헤멤 comp함수 인자로 넘기는 것이 문제인듯..

#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
using namespace std;

struct info
{
	int idx, num, cnt;
};

bool comp(info a, info b)
{
	if(a.cnt!=b.cnt) return a.cnt > b.cnt;
	return a.idx < b.idx;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int c;
	cin >> n >> c;

	vector<info> v;
	for (int i = 0; i < n; i++)
	{
		int x;
		bool isused = false;
		cin >> x;
		if (v.empty())
		{
			v.push_back({ i,x,1 });
			isused = true;
		}
		else
		{
			for (int j = 0; j < v.size(); j++)
			{
				if (v[j].num == x)
				{
					v[j].cnt++;
					isused = true;
					break;
				}
			}
		}
		if (!isused)
			v.push_back({ i,x,1 });
	}

	sort(v.begin(), v.end(), comp);

	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[i].cnt; j++)
		{
			cout << v[i].num << " ";
		}
	}

	return 0;
} 

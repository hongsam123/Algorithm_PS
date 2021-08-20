#include<iostream>
#include<utility>
#include<algorithm>
#include<vector>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		v.push_back({ x,i });
	}

	sort(v.begin(), v.end());

	vector<pair<int, int>> v1;
	int prev = v[0].first;
	
	v1.push_back({ v[0].second,0 });

	int val = 0;

	if (v.size() > 1)
	{
		for (int i = 1; i < n; i++)
		{
			if (v[i].first == prev)
			{
				v1.push_back({ v[i].second,val });
			}
			else
			{
				val++;
				v1.push_back({ v[i].second,val });
			}
			prev = v[i].first;
		}
	}
	sort(v1.begin(), v1.end());

	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1[i].second << " ";
	}

	return 0;
}

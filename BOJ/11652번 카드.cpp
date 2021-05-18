#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	
	vector<long long> v;
	for (int i = 0; i < n; i++)
	{
		long long x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());

	int max_cnt = 1;
	long long num = v[0];
	int cnt = 1;
	long long pre = v[0];

	if (v.size() > 1)
	{
		for (int i = 1; i < v.size(); i++)
		{
			if (v[i] == pre)
			{
				cnt++;
				if (cnt > max_cnt)
				{
					max_cnt = cnt;
					num = v[i];
				}
			}
			else
			{
				cnt = 1;
			}
			pre = v[i];
		}
	}

	cout << num;

	return 0;
}

//처음 풀이 : 다음날 주식이 오를땐 사다가 주식이 떨어지기 전날 판다.
//올바른 풀이 : 현재 주가를 현재일 이후 가장 비싸게 팔 수 있는 날 판다. 
#include<iostream>
#include<vector>
using namespace std;

int t, n;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	while (t--)
	{
		cin >> n;
		
		vector<int> v;
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			v.push_back(x);
		}

		int max_n = v.back();
		int pre = v.back();
		long long total = 0;
		for (int i = v.size() - 2; i >= 0; i--)	//뒤에서부터 봤을 때
		{
			if (v[i] > pre && max_n < v[i])	//증가하면 최대값이 갱신
			{
				max_n = v[i];
			}
			else
				//감소하면 현재 최대값이 주식을 팔아야하는 최대값
			{
				total += max_n - v[i];
			}
			pre = v[i];
		}

		cout << total << "\n";
	}

	return 0;
}

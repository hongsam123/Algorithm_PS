#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int test;
	cin >> test;

	while (test--)
	{
		int n, m;
		cin >> n >> m;

		vector<int> a;
		vector<int> b;

		int x;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			a.push_back(x);
		}
		for (int i = 0; i < m; i++)
		{
			cin >> x;
			b.push_back(x);
		}

		sort(a.rbegin(), a.rend());
		sort(b.begin(), b.end());

		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (a[i] > b[j]) cnt++;
				else break;
			}
		}
		cout << cnt << "\n";
	}

	return 0;
}


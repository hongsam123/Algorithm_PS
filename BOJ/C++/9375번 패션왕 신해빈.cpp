#include<iostream>
#include<map>
#include<vector>
using namespace std;

int t, n;
map<string, int> m;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			string type, name;
			cin >> name >> type;

			if (m.find(type) == m.end())
				m.insert({ type,1 });
			else
				m[type]++;
		}

		int ans = 1;
		for (auto e : m)
		{
			ans *= (e.second + 1);
		}

		cout << ans - 1 << "\n";

		m.clear();
	}

	return 0;
}

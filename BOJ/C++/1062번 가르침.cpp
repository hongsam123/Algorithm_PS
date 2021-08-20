#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, k;
vector<string> s;
int ans;
bool abc[26];

void check()
{
	int cnt = 0;
	for (auto str : s)
	{
		bool posi = true;
		for (auto e : str)
		{
			if (abc[e - 'a'] == 0)
			{
				posi = false;
				break;
			}
		}
		if (posi) cnt++;
	}
	ans = max(ans, cnt);
}

void func(int a, int x)
{
	if (x == k)
	{
		check();
		return;
	}

	for (int i = a; i < 26; i++)
	{
		if (abc[i]) continue;
		abc[i] = 1;
		func(i, x + 1);

		abc[i] = 0;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	abc['a' - 'a'] = 1;
	abc['n' - 'a'] = 1;
	abc['t' - 'a'] = 1;
	abc['i' - 'a'] = 1;
	abc['c' - 'a'] = 1;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		s.push_back(str);
	}

	if (k < 5)
	{
		cout << 0;
		return 0;
	}

	if (k == 5)
	{
		for (auto str : s)
		{
			bool posi = true;
			for (char e : str)
			{
				if (e != 'a' && e != 'n' && e != 't' && e != 'c' && e != 'i')
				{
					posi = false;
					break;
				}
			}
			if (posi) ans++;
		}

		cout << ans;
		return 0;
	}
	k -= 5;

	func(0, 0);

	cout << ans;

	return 0;
}

#include<iostream>
#include<algorithm>
using namespace std;

int t, n;
bool door[102];	//false : close, true : open

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	while (t--)
	{
		cin >> n;
		fill(door, door + n + 1, 1);	//전부 열려있다(1라운드)

		for (int i = 2; i <= n; i++)
		{
			int x = i;
			while (x <= n)
			{
				if (door[x])
					door[x] = false;
				else
					door[x] = true;
				x += i;
			}
		}

		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			if (door[i]) ans++;
		}
		cout << ans << "\n";
	}

	return 0;
}

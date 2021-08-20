#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int INF = 987654321;
int n, m;
int dp[102][102];
int nxt[102][102];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i <= n; i++)
		fill(dp[i], dp[i] + n + 10, INF);

	for (int i = 0; i <= n; i++)
		dp[i][i] = 0;

	for (int i = 0; i < m; i++)
	{
		int u, v, e;
		cin >> u >> v >> e;
		dp[u][v] = min(e, dp[u][v]);
		nxt[u][v] = v;
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (dp[i][j] > dp[i][k] + dp[k][j])
				{
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
					nxt[i][j] = nxt[i][k];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (dp[i][j] == INF) cout << 0 << " ";
			else cout << dp[i][j] << " ";
		}
		cout << "\n";
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j || dp[i][j] == INF)
			{
				cout << 0 << "\n";
				continue;
			}
			vector<int> v;
			int cur = i;
			while (cur != j)
			{
				v.push_back(cur);
				cur = nxt[cur][j];
			}
			v.push_back(cur);

			cout << v.size() << " ";
			for (int e : v)
				cout << e << " ";
			cout << "\n";
		}
	}

	return 0;
}

#include<iostream>
#include<algorithm>
using namespace std;

const int INF = 100000000;
int n, m;
int dp[102][102];

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
		dp[u][v] = min(e,dp[u][v]);
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
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

	return 0;
}

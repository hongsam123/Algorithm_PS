#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
const int INF = 1e9 + 10;
int dp[102][102];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		fill(dp[i], dp[i] + n + 2, INF);

	for (int i = 1; i <= n; i++)
		dp[i][i] = 0;

	while (m--)
	{
		int u, v;
		cin >> u >> v;
		dp[u][v] = 1;
		dp[v][u] = 1;
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

	int ans = 0;
	int min_kevin = INF;
	for (int i = 1; i <= n; i++)
	{
		int kevin = 0;
		for (int j = 1; j <= n; j++)
		{
			if (i == j) continue;
			kevin += dp[i][j];
		}
		if (min_kevin > kevin)
		{
			min_kevin = kevin;
			ans = i;
		}
	}

	cout << ans;

	return 0;
}

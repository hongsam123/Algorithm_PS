#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
int dp[502][502];
const int INF = 1e9 + 10;
//const int INF = 99;
int ans;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i <= n; i++)
		fill(dp[i], dp[i] + n + 2, INF);

	for (int i = 0; i <= n; i++)
		dp[i][i] = 0;

	//단방향 그래프
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		dp[u][v] = 1;
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				dp[i][j] = min(dp[i][k] + dp[k][j], dp[i][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		bool posi = true;
		for (int j = 1; j <= n; j++)
			if (dp[i][j] == INF)	//INF가 아니면 i기준 j보다 키가 작다
				if (dp[j][i] == INF)	//INF가 아니면 j기준 i보다 키가 작다
				{
					posi = false;		//dp[i][j], dp[j][i]가 모두 INF라면 키 순서 비교가 불가능
					break;

				}
		if (posi) ans++;
	}

	cout << ans;

	return 0;
}

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n,q;
int dp[302][302];
const int INF = 1e9 + 10;
vector<pair<int, int>> line;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	line.push_back({ 0,0 });
	
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		line.push_back({ a,b });
	}

	for (int i = 1; i <= n; i++)
		fill(dp[i], dp[i] + n + 2,INF);

	for (int i = 1; i <= n; i++)
		dp[i][i] = 0;

	for (int i = 1; i <= n; i++)
	{
		int a1 = line[i].first;
		int a2 = line[i].second;
		for (int j = 1; j <= n; j++)
		{
			if (i == j) continue;
			int b1 = line[j].first;
			int b2 = line[j].second;

			if (a1 <= b1)
			{
				if (b1 <= a2)	//i와 j가 1만큼의 친구다
				{
					dp[i][j] = 1;
					dp[j][i] = 1;
				}
			}
			else
			{
				if (a1 <= b2)
				{
					dp[i][j] = 1;
					dp[j][i] = 1;
				}
			}
		}
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

	cin >> q;

	while (q--)
	{
		int u, v;
		cin >> u >> v;
		
		if (dp[u][v] == INF)
		{
			if(dp[v][u]==INF)
				cout << -1 << "\n";
			else
				cout<< dp[v][u] << "\n";
		}
		else
			cout << dp[u][v] << "\n";
	}


	return 0;
}

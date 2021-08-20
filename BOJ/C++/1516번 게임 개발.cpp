#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int n;
vector<int> adj[502];
vector<int> inadj[502];
int build[502];		// 해당 건물을 짓는데 걸리는 시간
long long dp[502];	// 건물이 완성되기까지 걸리는 최소 시간
queue<int> q;
int indeg[502];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> build[i];
		while (1)
		{
			int x;
			cin >> x;
			if (x == -1) break;
			adj[x].push_back(i);
			inadj[i].push_back(x);
			indeg[i]++;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (indeg[i] == 0)
		{
			q.push(i);
			dp[i] = build[i];
		}
	}

	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		
		for (auto nxt : adj[cur])
		{
			indeg[nxt]--;
			if (indeg[nxt] == 0)
			{
				long long max_build = 0;
				for (int u : inadj[nxt])
				{
					max_build = max(max_build, dp[u]);
				}
				dp[nxt] = max_build + build[nxt];
				q.push(nxt);
			}
		}
	}

	for (int i = 1; i <= n; i++)
		cout << dp[i] << "\n";

	return 0;
}

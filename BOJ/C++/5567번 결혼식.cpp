#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

vector<int> adj[502];
int n, m;
queue<int> q;
int dist[502];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	fill(dist, dist + n + 1, -1);

	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dist[1] = 0;
	q.push(1);

	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		if (!adj[cur].empty())
		{
			for (auto nxt : adj[cur])
			{
				if (dist[nxt] != -1) continue;
				dist[nxt] = dist[cur] + 1;
				q.push(nxt);
			}
		}
	}

	int ans = 0;
	for (int i = 2; i <= n; i++)
	{
		if (dist[i] > 0 && dist[i] <= 2)
			ans++;
	}

	cout << ans;

	return 0;
}

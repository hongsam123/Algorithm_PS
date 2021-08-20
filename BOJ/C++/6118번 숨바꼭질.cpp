#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int n, m;
vector<int> adj[20002];
queue<int> q;
int dist[20002];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int v, u;
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}

	fill(dist, dist + n + 1, -1);
	dist[1] = 0;
	q.push(1);

	int max_dist = 0;
	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		for (auto nx : adj[cur])
		{
			if (dist[nx] != -1) continue;
			dist[nx] = dist[cur] + 1;
			max_dist = max(max_dist, dist[nx]);
			q.push(nx);
		}
	}

	int num = 0;
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (dist[i] == max_dist)
		{
			cnt++;
			if (num == 0)
				num = i;
		}
	}

	cout << num << " " << max_dist << " " << cnt;

	return 0;
}

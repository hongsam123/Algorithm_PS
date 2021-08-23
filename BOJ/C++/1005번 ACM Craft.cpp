#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

int t;
int n, k, w;
int cost[1002];
int indegree[1002];
vector<int> adj[1002];
int dist[1002];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	while (t--) {
		queue<int> q;

		cin >> n >> k;

		for (int i = 1; i <= n; i++)
			cin >> cost[i];

		fill(dist, dist + n + 1, 0);
		fill(indegree, indegree + n + 1, 0);

		while (k--) {
			int u, v;
			cin >> u >> v;
			indegree[v]++;
			adj[u].push_back(v);
		}

		cin >> w;

		for (int i = 1; i <= n; i++)
			if (indegree[i] == 0)
			{
				q.push(i);
				dist[i] = cost[i];
			}

		while (!q.empty()) {
			int cur = q.front(); q.pop();
			if (cur == w) break;

			for (auto nxt : adj[cur])
			{
				indegree[nxt]--;
				dist[nxt] = max(dist[nxt], dist[cur] + cost[nxt]);

				if (indegree[nxt] == 0)
					q.push(nxt);
			}
		}
		cout << dist[w] << "\n";

		for (int i = 1; i <= n; i++)
			adj[i].clear();
	}

	return 0;
}

#include<iostream>
#include<utility>
#include<queue>
#include<vector>
using namespace std;

int V, e, st;
const int INF = 1e9+10;
vector<pair<int, int>> adj[20005];
int d[20005];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> V >> e >> st;
	for (int i = 0; i < e; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ w,v });
	}

	fill(d, d + V + 1, INF);

	d[st] = 0;
	pq.push({ d[st],st });

	while (!pq.empty())
	{
		auto cur = pq.top(); pq.pop();
		int dist = cur.first, idx = cur.second;
		if (d[idx] != dist) continue;
		for (auto nxt : adj[idx])
		{
			int cost = nxt.first, nidx = nxt.second;
			if (d[nidx] > cost + dist)
			{
				d[nidx] = cost + dist;
				pq.push({ d[nidx],nidx });
			}
		}
	}

	for (int i = 1; i <= V; i++)
	{
		if (d[i] == INF)
			cout << "INF" << "\n";
		else
			cout << d[i] << "\n";
	}

	return 0;
}

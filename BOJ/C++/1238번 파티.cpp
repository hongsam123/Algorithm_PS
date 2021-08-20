#include<iostream>
#include<queue>
#include<utility>
#include<algorithm>
#include<vector>
#define pii pair<int,int>
using namespace std;

int n, m,x;
vector<pii> adj[1002];
int dist[1002];
int totdist[1002];
const int INF = 1e9 + 10;
priority_queue<pii, vector<pii>, greater<pii>> pq;

void dijkstra()
{
	while (!pq.empty())
	{
		auto cur = pq.top(); pq.pop();
		int cost = cur.first;
		int idx = cur.second;

		if (dist[idx] != cost) continue;
		for (auto nxt : adj[idx])
		{
			int nidx = nxt.first;
			int ncost = nxt.second;
			if (dist[nidx] > cost + ncost)
			{
				dist[nidx] = cost + ncost;
				pq.push({dist[nidx], nidx});
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> x;

	while (m--)
	{
		int u, v, cost;
		cin >> u >> v >> cost;

		adj[u].push_back({ v,cost });
	}

	//x에서 각 집으로 가는 최단 거리
	fill(totdist, totdist + n + 1, INF);
	totdist[x] = 0;
	pq.push({ totdist[x],x });
	while (!pq.empty())
	{
		auto cur = pq.top(); pq.pop();
		int cost = cur.first;
		int idx = cur.second;

		if (totdist[idx] != cost) continue;
		for (auto nxt : adj[idx])
		{
			int nidx = nxt.first;
			int ncost = nxt.second;
			if (totdist[nidx] > cost + ncost)
			{
				totdist[nidx] = cost + ncost;
				pq.push({ totdist[nidx], nidx });
			}
		}
	}

	//각 집에서 x로 가는 최단 거리 구하기
	for (int i = 1; i <= n; i++)
	{
		if (i == x) continue;
		fill(dist, dist + n + 1, INF);

		dist[i] = 0;
		pq.push({ dist[i],i });
		dijkstra();


		totdist[i] += dist[x];
	}

	int max_dist = 0;
	for (int i = 1; i <= n; i++)
	{
		if (i == x) continue;
		max_dist = max(max_dist, totdist[i]);
	}

	cout << max_dist;

	return 0;
}

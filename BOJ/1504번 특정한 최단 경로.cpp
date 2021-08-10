#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

int n, e;
int v1, v2;
int d[802];
priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<pair<int, int>> adj[802];
const int INF = 1e9 + 10;
int ans;

void dijkstra(int st)
{
	fill(d, d + 801, INF);
	d[st] = 0;
	pq.push({ 0,st });

	while (!pq.empty())
	{
		auto cur = pq.top(); pq.pop();
		int dist = cur.first;
		int idx = cur.second;

		if (dist != d[idx]) continue;
		for (auto nxt : adj[idx])
		{
			int cost = nxt.first;
			int nidx = nxt.second;
			if (d[nidx] > cost + dist)
			{
				d[nidx] = cost + dist;
				pq.push({ d[nidx],nidx });
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> e;

	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ c,b });
		adj[b].push_back({ c,a });
	}

	cin >> v1 >> v2;

	//v1->v2 최단 거리
	dijkstra(v1);
	
	//v1->v2로 못가면 -1
	if (d[v2] == INF)
	{
		cout << -1;
		return 0;
	}
	ans += d[v2];

	//st->v1 + v2->n(tmp1) 와 st->v2 + v1->n(tmp2) 중 최소값 찾기
	int tmp1 = 0;
	int tmp2 = 0;

	dijkstra(1);

	//st->v1
	tmp1 += d[v1];
	//st->v2
	tmp2 += d[v2];

	dijkstra(n);

	//v2->n
	tmp1 += d[v2];
	//v1->n
	tmp2 += d[v1];

	if (tmp1 >= INF && tmp2 >= INF)
	{
		cout << -1;
		return 0;
	}

	cout << ans + min(tmp1, tmp2);

	return 0;
}

#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
vector<pair<int, int>> adj[5002];
int v, e, p;
int d[5002];
const int INF = 1e9 + 10;

void dijkstra(int st)
{
	fill(d, d + 5001, INF);
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
			if (d[nidx] > dist + cost)
			{
				d[nidx] = dist + cost;
				pq.push({ d[nidx],nidx });
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> v >> e >> p;

	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		adj[a].push_back({ c,b });
		adj[b].push_back({ c,a });
	}

	//출발지에서의 최단거리
	dijkstra(1);

	int ans = d[v];
	int frd = d[p];

	//건우가 있는곳에서 마산까지의 최단거리
	dijkstra(p);

	frd += d[v];

	if (frd <= ans)
		cout << "SAVE HIM";
	else
		cout << "GOOD BYE";

	return 0;
}

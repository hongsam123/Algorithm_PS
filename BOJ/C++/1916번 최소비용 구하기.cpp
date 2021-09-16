#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define pii pair<int,int>
using namespace std;

const int INF = 1e9 + 10;
int d[1002];
vector<pii> adj[1002];	//<idx,cost>
queue<pii> q;			//<cost,idx>
int n, m;
int u, v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({b,c});
	}

	fill(d, d + n + 1, INF);

	cin >> u >> v;
	d[u] = 0;
	q.push({ 0,u });

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		int idx = cur.second;
		int dist = cur.first;
		if (d[idx] < dist) continue;

		for (auto nxt : adj[idx]) {
			int nidx = nxt.first;
			int cost = dist + nxt.second;
			if (d[nidx] > cost) {
				d[nidx] = cost;
				q.push({ cost,nidx });
			}
		}
	}

	cout << d[v];

	return 0;
}

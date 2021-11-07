#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<utility>
#define pii pair<int,int>
using namespace std;

priority_queue<pii> pq;
int n;
vector<pii> adj[10002];
int dist[10002];
int ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int v, u, cost;
		cin >> v >> u >> cost;

		adj[v].push_back({ u,cost });
		adj[u].push_back({ v,cost });
	}

	//루트노드로부터 가장 먼 정점 구하기
	fill(dist, dist + n + 1, -1);

	dist[1] = 0;
	for (auto cur : adj[1])
	{
		pq.push({ cur.second, cur.first });
		dist[cur.first] = cur.second;
	}
	
	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		int d = cur.first;
		int node = cur.second;

		for (auto nxt : adj[node]) {
			if (dist[nxt.first] != -1) continue;
			dist[nxt.first] = d + nxt.second;
			pq.push({ dist[nxt.first],nxt.first });
		}
	}

	int x = 0;
	int max_dist = 0;
	for (int i = 1; i <= n; i++) {
		if (max_dist < dist[i]) {
			max_dist = dist[i];
			x = i;
		}
	}

	//구한 정점으로부터 가장 먼 정점 구하기(트리의 지름 구하기)
	fill(dist, dist + n + 1, -1);

	dist[x] = 0;
	for (auto cur : adj[x]) {
		pq.push({ cur.second, cur.first });
		dist[cur.first] = cur.second;
	}

	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		int d = cur.first;
		int node = cur.second;

		for (auto nxt : adj[node]) {
			if (dist[nxt.first] != -1) continue;
			dist[nxt.first] = d + nxt.second;
			pq.push({ dist[nxt.first],nxt.first });
		}
	}

	for (int i = 1; i <= n; i++) {
		ans = max(dist[i], ans);
	}
	cout << ans;

	return 0;
}

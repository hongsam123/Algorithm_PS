#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define pii pair<int,int>
using namespace std;

int n, m, k;
//const int INF = 1e9 + 10;
vector<pii> adj[1002];	//<cost,idx>
priority_queue<pii, vector<pii>, greater<pii>> pq;
//int d[102][1002];	//출발지에서 i까지 가는 k개의 최단 거리를 저장할 배열
					//dist[1][i] = 출발지에서 i까지 가는 1번째 최단 거리
//but 이차원 배열은 정렬이 어렵다==> pq사용
//모든 경우의 수로 출발지에서 i까지 가는 최종 비용을 pq배열에 저장 => 자동으로 비용이 정렬된다
priority_queue<int> pq_k[1002];	//최대힙 : top이 제일 큰 값

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });
	}

	pq.push({ 0,1 });
	pq_k[1].push(0);

	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		int dist = cur.first;
		int idx = cur.second;

		for (auto nxt : adj[idx]) {
			int nidx = nxt.first;
			int cost = nxt.second;
			
			if (pq_k[nidx].size() < k) {
				pq_k[nidx].push({ cost + dist });
				pq.push({ cost + dist,nidx });
			}
			else {
				if (pq_k[nidx].top() > cost + dist) {
					pq_k[nidx].pop();
					pq_k[nidx].push(cost+dist);
					pq.push({ cost + dist,nidx });
				}
			}
		}
	}
	//1->1
	//cout << -1 << "\n";
	for (int i = 1; i <= n; i++) {
		if (pq_k[i].size() < k)
			cout << -1 << "\n";
		else
		{
			cout << pq_k[i].top() << "\n";
		}
	}

	return 0;
}

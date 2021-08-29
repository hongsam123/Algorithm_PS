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
//int d[102][1002];	//��������� i���� ���� k���� �ִ� �Ÿ��� ������ �迭
					//dist[1][i] = ��������� i���� ���� 1��° �ִ� �Ÿ�
//but ������ �迭�� ������ ��ƴ�==> pq���
//��� ����� ���� ��������� i���� ���� ���� ����� pq�迭�� ���� => �ڵ����� ����� ���ĵȴ�
priority_queue<int> pq_k[1002];	//�ִ��� : top�� ���� ū ��

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

#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
#include<queue>
#define pii pair<int,int>
using namespace std;

int t, n, d, c;
vector<pii> adj[10002];			//<i��° ��ǻ�͸� �����ϴ� ��ǻ�� ��ȣ, �����Ǵ� �ð�>
priority_queue<pii, vector<pii>, greater<pii>> pq;	//<�ɸ� �ð�,������ ��ǻ��>
int visited[10002];	//��������

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	while (t--) {
		cin >> n >> d >> c;

		while (!pq.empty()) pq.pop();
		
		int ans = 0;
		int cnt = 0;

		fill(visited, visited + n + 1, -1);

		for (int i = 0; i <= n; i++)
			adj[i].clear();

		for (int i = 0; i < d; i++) {
			int a, b, s;
			cin >> a >> b >> s;

			adj[b].push_back({ a,s });
		}

		pq.push({ 0,c });
		visited[c] = 0;

		while (!pq.empty()) {
			auto cur = pq.top(); pq.pop();
			int sec = cur.first;
			int v = cur.second;

			for (auto nxt : adj[v]) {
				int nsec = sec + nxt.second;
				int nv = nxt.first;
				if (visited[nv]!=-1 && nsec >= visited[nv]) continue;
				
				visited[nv] = nsec;
				pq.push({ nsec,nv });
			}
		}

		for (int i = 0; i <= n; i++) {
			if (visited[i] != -1)
			{
				cnt++;
				ans = max(ans, visited[i]);
			}
		}

		cout << cnt << " " << ans << "\n";
	}

	return 0;
}

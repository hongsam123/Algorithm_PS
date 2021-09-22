#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<tuple>
#define tii tuple<int,int,int>
using namespace std;

int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int board[102][102];
int dist[102][102];
priority_queue<tii, vector<tii>, greater<tii>> pq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		string line;
		cin >> line;
		for (int j = 0; j < m; j++) {
			board[i][j] = line[j] - '0';
		}
	}

	for (int i = 0; i < n; i++) {
		fill(dist[i], dist[i] + m + 1, -1);
	}

	dist[0][0] = 0;
	pq.push({ 0,0,0 });

	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		int cost = get<0>(cur);
		int x = get<1>(cur);
		int y = get<2>(cur);

		if (dist[x][y] != cost) continue;

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (dist[nx][ny] != -1) continue;
			dist[nx][ny] = cost + board[nx][ny];
			pq.push({ dist[nx][ny],nx,ny });
		}
	}

	cout << dist[n - 1][m - 1];

	return 0;
}

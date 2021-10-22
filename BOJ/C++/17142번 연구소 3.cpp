#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define pii pair<int,int>
#define X first
#define Y second
using namespace std;

const int INF = 987654321;
int n, m,virusNum;
bool isActive[2501];
int board[52][52];
vector<pii> virus;
int ans = INF;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int dist[52][52];

void bfs() {
	for (int i = 0; i < n; i++) {
		fill(dist[i], dist[i] + n, 0);
	}
	
	int time = 0;

	queue<pii> q;

	for (int i = 0; i < virusNum; i++) {
		if (isActive[i]) {
			auto cur = virus[i];
			q.push(cur);
			board[cur.X][cur.Y] = -1;
		}
	}

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (board[nx][ny] ==1||board[nx][ny]==-1) continue;
			if (dist[nx][ny]) continue;
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			if (board[nx][ny] != 2) {
				time = max(time, dist[nx][ny]);
				if(time>ans) break;
			}
			q.push({ nx,ny });
		}
	}
	
	for (int i = 0; i < virusNum; i++) {
		if (isActive[i]) {
			auto cur = virus[i];
			board[cur.X][cur.Y] = 2;
		}
	}

	bool posi = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 0 && dist[i][j] == 0) posi = false;
		}
	}
	
	if(posi) ans = min(time, ans);
}

void func(int x,int k) {
	if (k == m) {

		bfs();
		return;
	}
	for (int i = x; i < virusNum; i++) {
		if (isActive[i]) continue;
		isActive[i] = 1;
		auto cur = virus[i];

		func(i + 1, k + 1);

		isActive[i] = 0;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 2) {
				virusNum++;
				virus.push_back({ i,j });
			}
		}
	}

	func(0, 0);

	if (ans == INF) cout << -1;
	else cout << ans;

	return 0;
}

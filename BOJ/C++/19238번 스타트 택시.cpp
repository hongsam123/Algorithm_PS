#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<tuple>
#define tii tuple<int,int,int>
#define pii pair<int,int>
#define X first
#define Y second
using namespace std;

int n, m;
int board[21][21];
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1, 0 };
int fuel;
int x, y;
vector<pii> dest;
int dist[21][21];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> fuel;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> board[i][j];
			if (board[i][j]) board[i][j] = -1;
		}
	}

	cin >> x >> y;
	dest.push_back({ 0,0 });
	for (int i = 1; i <= m; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		board[a][b] = i;
		dest.push_back({ c,d });
	}

	while (m--) {
		//태울 승객 고르기(현재 위치에서 최단 거리가 가장 짧은 승객
		int guest = 0;
		priority_queue<tii, vector<tii>, greater<tii>> q;
		
		for (int i = 0; i <= n; i++)
			fill(dist[i], dist[i] + n+1, -1);

		dist[x][y] = 0;
		q.push({ 0,x,y });

		while (!q.empty()) {
			auto cur = q.top(); q.pop();
			int curX = get<1>(cur);
			int curY = get<2>(cur);
			if (board[curX][curY]>0) {
				guest = board[curX][curY];
				board[curX][curY] = 0;
				fuel -= dist[curX][curY];
				x = curX;
				y = curY;
				break;
			}

			for (int dir = 0; dir < 4; dir++) {
				int nx = curX + dx[dir];
				int ny = curY + dy[dir];
				if (nx <= 0 || nx > n || ny <= 0 || ny > n) continue;
				if (board[nx][ny] == -1) continue;
				if (dist[nx][ny] != -1) continue;
				dist[nx][ny] = get<0>(cur) + 1;
				q.push({ dist[nx][ny], nx,ny });
			}
		}
		
		if (fuel <= 0 || guest==0) {
			cout << -1;
			return 0;
		}
		
		//손님 데려다 주기
		int dest_x = dest[guest].X;
		int dest_y = dest[guest].Y;

		queue<pii> q2;
		int tax = -1;

		for (int i = 0; i <= n; i++)
			fill(dist[i], dist[i] + n+1, -1);

		dist[x][y] = 0;
		q2.push({ x,y });

		while (!q2.empty()) {
			auto cur = q2.front(); q2.pop();
			if (cur.X==dest_x && cur.Y==dest_y) {
				tax = 2 * dist[cur.X][cur.Y];
				fuel -= dist[cur.X][cur.Y];
				x = cur.X;
				y = cur.Y;
				break;
			}

			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if (nx <= 0 || nx > n || ny <= 0 || ny > n) continue;
				if (board[nx][ny] == -1) continue;
				if (dist[nx][ny] != -1) continue;
				dist[nx][ny] = dist[cur.X][cur.Y] + 1;
				q2.push({ nx,ny });
			}
		}
		if (fuel < 0||tax==-1) {
			cout << -1;
			return 0;
		}

		fuel += tax;
	}

	cout << fuel;

	return 0;
}

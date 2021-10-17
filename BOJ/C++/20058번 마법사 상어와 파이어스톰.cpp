#include<iostream>
#include<queue>
#include<algorithm>
#include<utility>
#include<vector>
#define X first
#define Y second
using namespace std;

int n, q;
int l;
int m;
int board[70][70];
bool visited[70][70];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int total, bigIce;
queue<pair<int, int>> que;

void getAns() {
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			if (visited[i][j]) continue;
			if (board[i][j] <= 0) continue;

			//얼음이 있는 경우만 bfs
			int cnt = 1;
			que.push({ i,j });
			visited[i][j] = 1;
			total += board[i][j];

			while (!que.empty()) {
				auto cur = que.front(); que.pop();

				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if (nx <= 0 || nx > m || ny <= 0 || ny > m) continue;
					if (visited[nx][ny]) continue;
					if (board[nx][ny]>0) {
						visited[nx][ny] = 1;
						total += board[nx][ny];
						cnt++;
						que.push({ nx,ny });
					}
				}
			}
			bigIce = max(bigIce, cnt);
		}
	}
}

void reduceIce() {
	int tmp[70][70];
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			tmp[i][j] = board[i][j];
		}
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			if (board[i][j] <= 0) tmp[i][j] = 0;
			else {
				int cnt = 0;
				for (int dir = 0; dir < 4; dir++) {
					int nx = i + dx[dir];
					int ny = j + dy[dir];
					if (nx <= 0 || nx > m || ny <= 0 || ny > m) continue;
					if (board[nx][ny]>0) cnt++;
				}
				if (cnt <= 2) tmp[i][j]--;
			}
		}
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			board[i][j] = tmp[i][j];
		}
	}
}

void rotate(int x,int y,int num) {
	int tmp[70][70];
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			tmp[i][j] = board[x + num - 1 - j][y + i];
		}
	}
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			board[x + i][y + j] = tmp[i][j];
		}
	}

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q;

	m = 1;
	for (int i = 1; i <= n; i++) {
		m *= 2;
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> board[i][j];
		}
	}


	while (q--) {
		cin >> l;

		int k = (1 << l);
		for (int i = 1; i <= m; i+=k) {
			for (int j = 1; j <= m; j+=k) {
				rotate(i, j, k);
			}
		}

		reduceIce();
	}

	getAns();

	cout << total << "\n" << bigIce;

	return 0;
}

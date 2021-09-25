#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int board[22][22];
int n;
map<int,int> conn[402];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int ans;

void setSeat(int p) {
	int x = 0;
	int y = 0;
	int max_f = -1;
	int max_em = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (board[i][j]) continue;
			int cnt_f = 0;
			int cnt_em = 0;

			for (int dir = 0; dir < 4; dir++) {
				int nx = i + dx[dir];
				int ny = j + dy[dir];
				if (nx<1 || ny<1 || nx>n || ny>n) continue;
				if (!board[nx][ny]) {
					//빈자리라면
					cnt_em++;
					continue;
				}
				int f = board[nx][ny];
				if (conn[p][f] == 1) {
					//친구라면
					cnt_f++;
				}
			}

			if (cnt_f > max_f) {
				//친구가 최대값이라면
				max_f = cnt_f;
				x = i;
				y = j;
				max_em = cnt_em;
			}
			else if (cnt_f == max_f && cnt_em>max_em) {
				//친구 수가 같고 빈자리가 더 많다면
				x = i;
				y = j;
				max_em = cnt_em;
			}
		}
	}
	board[x][y] = p;
}

void getAns() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int p = board[i][j];
			int cnt_f = 0;
			for (int dir = 0; dir < 4; dir++) {
				int nx = i + dx[dir];
				int ny = j + dy[dir];
				if (nx<1 || ny<1 || nx>n || ny>n) continue;
				int f = board[nx][ny];
				if (conn[p][f]) cnt_f++;
			}
			if (cnt_f == 1) ans += 1;
			else if (cnt_f == 2) ans += 10;
			else if (cnt_f == 3) ans += 100;
			else if (cnt_f == 4) ans += 1000;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int k = 0; k < n * n; k++) {
		int x, f1, f2, f3, f4;
		cin >> x >> f1 >> f2 >> f3 >> f4;
		conn[x].insert({ f1,1 });
		conn[x].insert({ f2,1 });
		conn[x].insert({ f3,1 });
		conn[x].insert({ f4,1 });

		setSeat(x);
	}

	getAns();

	cout << ans;

	return 0;
}

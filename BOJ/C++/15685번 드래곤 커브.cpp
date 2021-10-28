#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n;
int x, y, d, g;
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { 1, 0, -1, 0 };	//우,상, 좌 하
int board[102][102];
int ans;
vector<int> dir_info;

void getAns() {
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (board[i][j] && board[i + 1][j] && board[i][j + 1] && board[i + 1][j + 1])
				ans++;
		}
	}
}

void dragonCurve() {
	int s = dir_info.size();
	for (int i = s - 1; i >= 0; i--) {
		int ndir = (dir_info[i] + 1) % 4;
		x = x + dx[ndir];
		y = y + dy[ndir];
		board[x][y] = 1;
		dir_info.push_back(ndir);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> y >> x >> d >> g;
		dir_info.clear();

		//0세대 진행
		board[x][y] = 1;
		x = x + dx[d];
		y = y + dy[d];
		board[x][y] = 1;

		dir_info.push_back(d);
		for (int j = 0; j < g; j++) {
			dragonCurve();
		}
	}
	getAns();

	cout << ans;

	return 0;
}

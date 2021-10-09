#include<iostream>
#include<algorithm>
using namespace std;

int r, c;
char board[22][22];
int ans;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int sum;
bool isused[30];

void dfs(int x, int y) {
	ans = max(ans, sum);

	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
		if (isused[board[nx][ny] - 'A']) continue;
		isused[board[nx][ny] - 'A'] = 1;
		sum += 1;
		dfs(nx, ny);
		sum -= 1;
		isused[board[nx][ny] - 'A'] = 0;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c;
	
	for (int i = 0; i < r; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < c; j++) {
			board[i][j] = str[j];
		}
	}

	sum += 1;
	isused[board[0][0] - 'A'] = 1;
	dfs(0, 0);


	cout << ans;

	return 0;
}

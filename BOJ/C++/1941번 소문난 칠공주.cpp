#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define X first
#define Y second
#define pii pair<int,int>
using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
char board[7][7];
bool isused[27];
bool visited[7][7];
int ans;

bool check() {
	queue<pii> q;
	
	for (int i = 0; i < 5; i++)
		fill(visited[i], visited[i] + 5, 0);

	for (int i = 0; i < 25; i++) {
		if (isused[i]) {
			q.push({ i / 5,i % 5 });
			visited[i / 5][i % 5] = 1;
			break;
		}
	}

	int cnt = 0;
	int cnt_s = 0;
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		cnt++;
		if (board[cur.X][cur.Y] == 'S') cnt_s++;
		
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
			if (visited[nx][ny] || isused[nx*5 + ny]==0) continue;
			visited[nx][ny] = 1;
;			q.push({ nx,ny });
		}
	}

	if (cnt != 7 || cnt_s < 4) return false;
	return true;
}

void func(int k, int x) {
	if (k == 7) {
		if (check()) {
			//가로/세로로 인접해 있는지, 이다솜 파가 우위에 있는지 확인
			ans++;
		}
		return;
	}

	for (int i = x; i < 25; i++) {
		if (isused[i]) continue;
		isused[i] = 1;
		func(k + 1, i);
		isused[i] = 0;
	}
	
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 5; i++) {
		string line;
		cin >> line;
		for (int j = 0; j < 5; j++) {
			board[i][j] = line[j];
		}
	}

	func(0,0);

	cout << ans;

	return 0;
}

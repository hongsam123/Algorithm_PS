#include<iostream>
#include<algorithm>
#include<vector>
#define pii pair<int,int>
#define X first
#define Y second
using namespace std;

int n, m;
int board[52][52];
int tmp[52][52];
vector<pii> cloud;
int dx[9] = {0,0,-1,-1,-1,0,1,1,1};	//1번부터 ←, ↖, ↑, ↗, →, ↘, ↓, ↙
int dy[9] = {0,-1,-1,0,1,1,1,0,-1};

void move(int d, int s) {
	for (int i = 0; i < cloud.size(); i++) {
		auto cur = cloud[i];
		int nx = cur.X;
		int ny = cur.Y;
		for (int j = 0; j < s; j++) {
			nx += dx[d];
			ny += dy[d];
			if (nx < 0) nx = n - 1;
			if (nx >= n) nx = 0;
			if (ny < 0) ny = n - 1;
			if (ny >= n) ny = 0;
		}
		cloud[i] = { nx,ny };
	}
}

void rain() {
	for (auto e : cloud) {
		board[e.X][e.Y]++;
	}
}

void copy() {
	for (auto e : cloud) {
		int cnt = 0;
		for (int dir = 2; dir < 9; dir += 2) {
			//↖, ↗, ↘, ↙
			int nx = e.X + dx[dir];
			int ny = e.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (board[nx][ny]) cnt++;
		}
		board[e.X][e.Y] += cnt;
	}
}

void newCloud() {
	//tmp 초기화
	for (int i = 0; i < n; i++)
		fill(tmp[i], tmp[i] + n + 1, 0);

	//cloud를 비우면서 tmp에 표시
	for (int i = 0; i < cloud.size(); i++) {
		auto cur = cloud[i];
		tmp[cur.X][cur.Y] = 1;
	}

	//cloud 초기화
	cloud.clear();

	//새 cloud 추가
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] >= 2 && !tmp[i][j]) {
				cloud.push_back({ i,j });
				board[i][j] -= 2;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	cloud.push_back({ n - 1,0 });
	cloud.push_back({ n - 1,1 });
	cloud.push_back({ n - 2,0 });
	cloud.push_back({ n - 2,1 });

	while (m--) {
		int d, s;
		cin >> d >> s;

		//1. 모든 구름이 di 방향으로 si칸 이동한다.
		move(d, s);

		//2. 각 구름에서 비가 내려 구름이 있는 칸의 바구니에 저장된 물의 양이 1 증가한다.
		rain();

		//3. 구름이 모두 사라진다.

		//4. 2에서 물이 증가한 칸 (r, c)에 물복사버그 마법을 시전한다.
		copy();

		//5. 바구니에 저장된 물의 양이 2 이상인 모든 칸에 구름이 생기고, 물의 양이 2 줄어든다.
		newCloud();
	}

	int ans = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans += board[i][j];
		}
	}

	cout << ans;

	return 0;
}

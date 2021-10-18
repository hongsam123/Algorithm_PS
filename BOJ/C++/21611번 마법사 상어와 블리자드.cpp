#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define X first
#define Y second
#define pii pair<int,int>
using namespace std;

int n, m;
int board[52][52];
vector<pii> magic;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int dx_[5] = { 0,-1,1,0,0 };
int dy_[5] = { 0,0,0,-1,1 };
int ans[4];
vector<pii> group;	//<그룹의 구슬 갯수, 구슬 번호>

void remakeMap() {
	for (int i = 0; i <= n; i++)
		fill(board[i], board[i] + n+1, 0);

	queue<int> tmp;
	for (int i = 0; i < group.size(); i++) {
		auto cur = group[i];
		tmp.push(cur.X);
		tmp.push(cur.Y);
	}
	if (tmp.empty()) return;

	int x = (n + 1) / 2;
	int y = (n + 1) / 2;
	int dir = 0;
	int cnt = 1;

	while (1) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < cnt; j++) {
				x += dx[dir];
				y += dy[dir];

				int num = tmp.front(); tmp.pop();
				board[x][y] = num;

				//채울 수가 비었거나 1,1이면 탈출
				if ((x == 1 && y == 1) || tmp.empty()) {
					group.clear();
					return;
				}
			}

			dir++;
			if (dir > 3) dir = 0;
		}
		cnt++;
	}
}

void change() {
	int x = (n + 1) / 2;
	int y = (n + 1) / 2;
	int dir = 0;
	int cnt = 1;

	while (1) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < cnt; j++) {
				x += dx[dir];
				y += dy[dir];

				int num = board[x][y];
				if (num != 0) {
					//0일땐 패스
					if (group.empty() || group.back().second != num)
						group.push_back({ 1,num });
					else group[group.size() - 1].first += 1;
				}

				//1,1이면 탈출
				if (x == 1 && y == 1) {
					remakeMap();
					return;
				}
			}

			dir++;
			if (dir > 3) dir = 0;
		}
		cnt++;
	}
}

bool explosion() {
	//반시계 방향으로 돌면서 4개 이상으로 연속하는 구슬 폭발
	int x = (n + 1) / 2;
	int y = (n + 1) / 2;

	int dir = 0;
	int cnt = 1;
	int prev = 0;
	queue<pii> q;
	bool isChange = false;

	while (1) {
		for (int i = 0; i < 2; i++) {
			//두번씩 정해진 수만큼 직진
			for (int j = 0; j < cnt; j++) {
				//이동
				x += dx[dir];
				y += dy[dir];

				//폭발
				int num = board[x][y];

				if (num != 0) {
					//0일때는 패스
					if (prev == num) {
						q.push({ x,y });
					}
					else {
						if (q.size() >= 4) {
							while (!q.empty()) {
								auto cur = q.front(); q.pop();
								ans[board[cur.X][cur.Y]]++;
								board[cur.X][cur.Y] = 0;
								if (!isChange) isChange = true;
							}
						}
						while (!q.empty()) q.pop();
						prev = num;
						q.push({ x,y });
					}
				}

				//1,1이면 탈출
				if (x == 1 && y == 1) {
					if (q.size() >= 4) {
						while (!q.empty()) {
							auto cur = q.front(); q.pop();
							ans[board[cur.X][cur.Y]]++;
							board[cur.X][cur.Y] = 0;
							if (!isChange) isChange = true;
						}
					}
					if (isChange) return true;
					else return false;
				}
			}

			//방향 전환
			dir++;
			if (dir > 3) dir = 0;
		}
		cnt++;
	}
}

void blizzard(int d,int s) {
	int x = (n + 1) / 2;
	int y = (n + 1) / 2;

	for (int i = 0; i < s; i++) {
		x += dx_[d];
		y += dy_[d];
		board[x][y] = 0;
		if (x <= 0 || y <= 0 || x > n || y > n) break;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> board[i][j];
		}
	}

	for(int i=0;i<m;i++) {
		int d, s;
		cin >> d >> s;
		magic.push_back({ d,s });
	}

	for(int i=0;i<m;i++)
	{
		int d = magic[i].first;
		int s = magic[i].second;

		blizzard(d,s);

		//더이상 폭발하지 않을 때까지
		while (1) {
			if (!explosion()) break;
		}

		change();

	}

	cout << (1 * ans[1]) + (2 * ans[2]) + (3 * ans[3]);

	return 0;
}

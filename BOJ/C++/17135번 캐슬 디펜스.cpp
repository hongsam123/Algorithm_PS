#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define X first
#define Y second
#define pii pair<int,int>
using namespace std;

int n, m, d;
int b[17][17];
int board[17][17];
int tmp[17][17];
bool isused[17];	//궁수 배치의 백트래킹을 위한 배열
vector<pii> archer;	//궁수 위치
int eneymy_num;
int ans;
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };
bool visited[17][17];

int getDist(pii a, pii b) {
	return abs(a.X - b.X) + abs(a.Y - b.Y);
}

void solution() {
	int cnt = 0;
	int enNum = eneymy_num;
	vector<pii> e;	//각각의 궁수가 공격할 적의 위치 저장

	while (enNum) {
		//bfs : 궁수의 적 공격

		//각 궁수의 공격할 적 선택
		for (int p = 0; p < 3; p++) {
			queue<pii> q;
			for (int i = 0; i < n; i++)
				fill(visited[i], visited[i] + m, false);

			auto cur = archer[p];
			visited[cur.X][cur.Y] = 1;
			q.push({ cur.X,cur.Y });
			while (!q.empty()) {
				auto cur = q.front(); q.pop();
				if (board[cur.X][cur.Y]) {
					//가장 가까운 적 발견
					//거리 검사 후 가능하면 break; 
					if (getDist(archer[p], cur) <= d) {
						e.push_back({ cur.X,cur.Y });
						break;
					}
				}
				if (getDist(cur, archer[p]) > d) continue;

				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (visited[nx][ny]) continue;
					visited[nx][ny] = 1;
					q.push({ nx,ny });
				}
			}
		}

		//적 공격
		for (auto x : e) {
			if (board[x.X][x.Y]) {
				board[x.X][x.Y] = 0;
				enNum--;
				cnt++;
			}
			//겹칠 수 있다
		}
		e.clear();

		if (enNum == 0) break;

		//적이 아래로 한칸 이동, 적 위치 변경
		for (int i = 0; i < n; i++)
			fill(tmp[i], tmp[i] + m, 0);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 1) {
					if (i + 1 >= n) {
						enNum--;
						continue;
					}
					else tmp[i + 1][j] = 1;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				board[i][j] = tmp[i][j];
		}
	}
	
	ans = max(ans, cnt);

	return;
}

//궁수 배치의 경우의 수
void func(int x, int k) {
	//k번째 궁수 배치
	if (k == 3) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				board[i][j] = b[i][j];
			}
		}
		solution();
		return;
	}

	for (int i = x; i < m; i++) {
		if (isused[i]) continue;
		isused[i] = true;
		archer.push_back({ n,i });
		func(i + 1, k + 1);

		isused[i] = false;
		archer.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> d;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> b[i][j];
			if(b[i][j])
				eneymy_num++;
		}
	}

	func(0,0);

	cout << ans;

	return 0;
}

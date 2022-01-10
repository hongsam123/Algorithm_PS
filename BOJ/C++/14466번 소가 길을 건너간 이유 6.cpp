#include<iostream>
#include<map>
#include<tuple>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>
#define tii tuple<int,int,int,int>
#define X first
#define Y second
using namespace std;

int n,k,r;
int board[102][102];	//0:ºóÄ­, 1:¼Ò
int ans;
map<tii,int> m;
vector<pair<int, int>> cow;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int visited[102][102];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k >> r;

	for (int i = 0; i < r; i++) {
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;
		m[{r1, c1, r2, c2}] = 1;
		m[{r2, c2, r1, c1}] = 1;
	}

	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		board[a][b] = 1;
		cow.push_back({ a,b });
	}

	for (auto cur : cow) {
		for (int i = 0; i <= n; i++) {
			fill(visited[i], visited[i] + n + 1, 0);
		}

		int x = cur.X;
		int y = cur.Y;
		visited[x][y] = 1;
		queue<pair<int, int>> q;
		q.push({ x,y });
			
		int cnt = 0;

		while (!q.empty()) {
			auto cur_cow = q.front(); q.pop();

			for (int dir = 0; dir < 4; dir++) {
				int nx = cur_cow.X + dx[dir];
				int ny = cur_cow.Y + dy[dir];
				if (nx <= 0 || nx > n || ny <= 0 || ny > n) continue;
				if (visited[nx][ny]) continue;
				if ( m[{ cur_cow.X,cur_cow.Y,nx,ny}]) continue;
				
				if (board[nx][ny]) cnt++;

				visited[nx][ny] = 1;
				q.push({ nx,ny });
			}
		}
		ans += k - 1 - cnt;
	}

	cout << ans / 2;

	return 0;
}

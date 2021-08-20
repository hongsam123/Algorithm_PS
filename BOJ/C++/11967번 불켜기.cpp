#include<iostream>
#include<vector>
#include<utility>
#include<queue>
#include<algorithm>
#define X first
#define Y second
using namespace std;

int n, m;
vector<pair<int, int>> map[102][102];
bool turnOn[102][102];
int ans;
queue<pair<int, int>> q;
bool visited[102][102];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int x, y, nx, ny;
		cin >> x >> y >> nx >> ny;
		map[x][y].push_back({ nx,ny });
	}

	q.push({ 1,1 });
	turnOn[1][1] = true;
	ans++;
	visited[1][1] = true;

	while (!q.empty())
	{
		auto cur = q.front(); q.pop();

		//불켜기
		if (!map[cur.X][cur.Y].empty())
		{
			for (int dir = 0; dir < map[cur.X][cur.Y].size(); dir++)
			{
				int nx = map[cur.X][cur.Y][dir].X;
				int ny = map[cur.X][cur.Y][dir].Y;
				if (turnOn[nx][ny]) continue;
				turnOn[nx][ny] = true;
				ans++;
			}
			//새롭게 이동할 수 있는 곳이 생겼으니 visited배열 초기화
			for (int i = 0; i <= n; i++)
				fill(visited[i], visited[i] + n + 1, 0);
			visited[cur.X][cur.Y] = true;
			
			map[cur.X][cur.Y].clear();	//불을 처음 키고나면 더 세지 않게 지우기
		}

		//이동
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx <= 0 || nx > n || ny <= 0 || ny > n) continue;
			if (!turnOn[nx][ny] || visited[nx][ny]) continue;
			visited[nx][ny] = true;
			q.push({ nx,ny });
		}
	}

	cout << ans;

	return 0;
}

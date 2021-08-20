#include<iostream>
#include<queue>
#include<utility>
#define X first
#define Y second
using namespace std;

int board[1002][1002];
int dist[1002][1002];
int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
queue<pair<int, int>> q;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n;
	int ans = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];

	for (int i = 0; i < n; i++)
		fill(dist[i], dist[i] + m, -1);


	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (board[i][j] == 1)
				//익은 토마토
			{
				q.push({ i,j });
				dist[i][j] = 0;
			}
	//시작점인 여러개인 BFS를 위해 모든 시작점을 큐에 넣고 BFS

	while (!q.empty())
	{
		pair<int, int> cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board[nx][ny] != 0 || dist[nx][ny] >= 0) continue;
			board[nx][ny] = 1;
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			q.push({ nx,ny });
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 0)
			{
				cout << -1;
				return 0;
			}
			ans = max(ans, dist[i][j]);
		}
	}
	
	cout << ans;

	return 0;
}
//3차원인 문제 3차원 토마토 => STL Tuple사용해보기 7576번

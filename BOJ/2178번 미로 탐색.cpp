#include<iostream>
#include<queue>
#include<utility>
#define X first
#define Y second
using namespace std;

string board[101];
int dist[101][101];
int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
queue<pair<int, int>> q;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
		cin >> board[i];

	for (int i = 0; i < n; i++)
		fill(dist[i], dist[i] + m, -1);
	// dist 배열을 -1로 초기화

	q.push({ 0,0 });
	dist[0][0] = 0;

	//int cnt = 0;

	while (!q.empty())
	{
		pair<int, int> cur = q.front(); q.pop();
		//cnt++;
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (dist[nx][ny] >= 0 || board[nx][ny] != '1') continue;
			//dist[nx][ny] = cnt;
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			q.push({ nx,ny });
		}
	}
	cout << dist[n - 1][m - 1] + 1;

	return 0;
}

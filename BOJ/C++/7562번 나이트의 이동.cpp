#include<iostream>
#include<queue>
#include<utility>
#include<algorithm>
#define X first
#define Y second
using namespace std;

int board[302][302];
int dist[302][302];
int dx[8] = { -2,-2,-1,-1,1,1,2,2 };
int dy[8] = { 1,-1,2,-2,2,-2,1,-1 };
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int test;
	cin >> test;
	while (test--)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
			fill(board[i], board[i] + n, 0);
		for (int i = 0; i < n; i++)
			fill(dist[i], dist[i] + n, 0);

		queue<pair<int, int>>q;
		int a, b;
		cin >> a >> b;
		q.push({ a,b });
		
		int x, y;
		cin >> x >> y;

		int cnt = 0;

		while (!q.empty())
		{

			pair<int, int> cur = q.front(); q.pop();
			if (cur.X == x && cur.Y == y)
			{
				cout << dist[x][y] << "\n";
				break;
			}

			for (int dir = 0; dir < 8; dir++)
			{
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
				if (dist[nx][ny] != 0) continue;
				dist[nx][ny] = dist[cur.X][cur.Y]+1;
				q.push({ nx,ny });
			}
			cnt++;
		}
	}
	return 0;
}


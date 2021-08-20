#include<iostream>
#include<queue>
#include<utility>
#define X first
#define Y second
using namespace std;

char board[1002][1002];
int firedist[1002][1002];
int dist[1002][1002];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int test;
	cin >> test;

	while (test--)
	{
		cin >> m >> n;

		for (int i = 0; i < n; i++)
		{
			fill(firedist[i], firedist[i] + m, -1);
			fill(dist[i], dist[i] + m, -1);
		}

		queue<pair<int, int>> fireq;
		queue<pair<int, int>> q;

		string str;

		bool impo = true;
		int ans = 0;

		for (int i = 0; i < n; i++)
		{
			cin >> str;
			for (int j = 0; j < m; j++)
			{
				board[i][j] = str[j];
				if (board[i][j] == '*')
				{
					fireq.push({ i,j });
					firedist[i][j] = 1;
				}
				if (board[i][j] == '@')
				{
					if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
						impo = false;
					q.push({ i,j });
					dist[i][j] = 1;
				}
			}
		}
		if (!impo)
		{
			cout << 1 << "\n";
			continue;
		}

		//불의 도착 시간 구하기
		while (!fireq.empty())
		{
			pair<int, int> cur = fireq.front(); fireq.pop();
			for (int dir = 0; dir < 4; dir++)
			{
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if (board[nx][ny] == '#' || firedist[nx][ny] != -1) continue;
				firedist[nx][ny] = firedist[cur.X][cur.Y] + 1;
				fireq.push({ nx,ny });
			}
		}

		//상근이의 도착 시간 구하기
		while (!q.empty())
		{
			pair<int, int> cur = q.front(); q.pop();
			for (int dir = 0; dir < 4; dir++)
			{
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if (board[nx][ny] == '#' || dist[nx][ny] != -1) continue;
				dist[nx][ny] = dist[cur.X][cur.Y] + 1;
				if (nx == 0 || ny == 0 || nx == n - 1 || ny == m - 1)
				{
					if (firedist[nx][ny] > dist[nx][ny] || firedist[nx][ny]==-1)
					{
						impo = false;
						cout << dist[nx][ny]<<"\n";
						break;
					} 
				}
				if (!impo) break;
				q.push({ nx,ny });
			}
			if (!impo) break;
		}

		if (impo)
			cout << "IMPOSSIBLE" << "\n";
	}

	return 0;
}

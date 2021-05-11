#include<iostream>
#include<queue>
#include<utility>
#define X first
#define Y second
using namespace std;

int board[51][51];
int visit[51][51];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int m, n;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--)
	{
		int k;
		int count = 0;
		queue<pair<int, int>> q;
		cin >> m >> n >> k;
		for (int i = 0; i < m; i++)
		{
			fill(board[i], board[i] + n, 0);
			fill(visit[i], visit[i] + n, -1);
		}
		for (int i = 0; i < k; i++)
		{
			int a, b;
			cin >> a >> b;
			board[a][b] = 1;
		}

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (board[i][j] == 1 && visit[i][j] == -1)
				{
					q.push({ i,j });
					count++;
				}

				while (!q.empty())
				{
					pair<int, int> cur = q.front(); q.pop();
					for (int dir = 0; dir < 4; dir++)
					{
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
						if (board[nx][ny] != 1 || visit[nx][ny] > 0) continue;
						visit[nx][ny] = 1;
						q.push({ nx,ny });
					}
				}
			}
		}
		cout << count << " ";
	}
	return 0;
}

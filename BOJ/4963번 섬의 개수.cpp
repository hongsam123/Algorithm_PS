#include<iostream>
#include<queue>
#include<utility>
#include<algorithm>
#define X first
#define Y second
using namespace std;

int board[52][52];
bool visited[52][52];
int dx[8] = { 1,1,0,-1,-1,-1,0,1 };
int dy[8] = { 0,1,1,1,0,-1,-1,-1};
int n, m;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (1)
	{
		cin >> m >> n;
		if (n == 0 && m == 0) break;
		
		for (int i = 0; i < n; i++)
		{
			fill(board[i], board[i] + m, 0);
			fill(visited[i], visited[i] + m, 0);
		}

		for(int i=0;i<n;i++)
			for (int j = 0; j < m; j++)
			{
				cin >> board[i][j];
			}
		queue<pair<int, int>> q;
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (board[i][j] == 0 || visited[i][j]) continue;
				q.push({ i,j });
				cnt++;

				while (!q.empty())
				{
					pair<int, int> cur = q.front(); q.pop();
					for (int dir = 0; dir < 8; dir++)
					{
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if (board[nx][ny] != 1 || visited[nx][ny]) continue;
						visited[nx][ny] = 1;
						q.push({ nx,ny });
					}
				}
			}
		}
		cout << cnt << "\n";
	}

	return 0;
}

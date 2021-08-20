#include<iostream>
#include<queue>
#include<utility>
#include<algorithm>
#define x first
#define y second
using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m;
int board[302][302];
int tmp[302][302];
bool visited[302][302];
queue<pair<int, int>> q;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}

	int year = 0;
	while (1)
	{
		int iceisland = 0;
		queue<pair<int, int>> island;
		for (int i = 0; i < n; i++)
		{
			fill(visited[i], visited[i] + m, 0);
			fill(tmp[i], tmp[i] + m, 0);
		}

		//섬의 개수 구하는 bfs 
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (board[i][j]!=0) island.push({ i,j });

				if (board[i][j]!=0 && !visited[i][j])
				{
					q.push({ i,j });
					visited[i][j] = 1;
					iceisland++;
					
					while (!q.empty())
					{
						pair<int, int> cur = q.front(); q.pop();
						for (int dir = 0; dir < 4; dir++)
						{
							int nx = dx[dir] + cur.x;
							int ny = dy[dir] + cur.y;
							if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
							if (!board[nx][ny] || visited[nx][ny]) continue;
							visited[nx][ny] = 1;
							q.push({ nx,ny });
						}
					}
				}
			}
		}
		if (iceisland >= 2) break;

		if (island.empty()||island.size()==(n*m))		//수정(size부분 추가)
		{
			cout << 0;
			return 0;
		}
		else	//빙산 녹이기 
		{
			while (!island.empty())
			{
				pair<int, int> cur = island.front(); island.pop();
				for (int dir = 0; dir < 4; dir++)
				{
					int nx = cur.x + dx[dir];
					int ny = cur.y + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (!board[cur.x][cur.y]) continue;
					if (board[nx][ny] == 0)
						tmp[cur.x][cur.y]++;	//수정(board[cur.x][cur.y]--;)에서
				}
			}
			for (int i = 0; i < n; i++)	//수정
			{
				for (int j = 0; j < m; j++)
				{
					if (tmp[i][j])
					{
						board[i][j] -= tmp[i][j];
						if (board[i][j] < 0) board[i][j] = 0;

					}
				}
			}
		}
		year++;
	}

	cout << year;

	return 0;
}


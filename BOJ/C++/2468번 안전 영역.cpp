#include<iostream>
#include<queue>
#include<utility>
#include<algorithm>
#define X first 
#define Y second 
using namespace std;

int n;
int board[102][102];
int visited[102][102];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	int max_num = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
			if (max_num < board[i][j]) max_num = board[i][j];
		}
	}

	int rain = 0;
	int max_area = 0;
	while (1)
	{
		if (rain >= max_num) break;

		int cnt_area = 0;
		for (int i = 0; i < n; i++)
			fill(visited[i], visited[i] + n, 0);
		queue<pair<int, int>> q;
		

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (board[i][j] > rain && visited[i][j] == 0)
				{
					q.push({ i,j });
					cnt_area++;
				}
				while (!q.empty())
				{
					pair<int, int> cur = q.front(); q.pop();
					for (int dir = 0; dir < 4; dir++)
					{
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
						if (visited[nx][ny] || board[nx][ny] <= rain) continue;
						visited[nx][ny] = 1;
						q.push({ nx,ny });
					}
				}
			}
		}

		max_area = max(max_area, cnt_area);
		rain++;
	}

	cout << max_area;

	return 0;
}

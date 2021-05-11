#include<iostream>
#include<queue>
#include<algorithm>
#include<utility>
#define X first
#define Y second
using namespace std;

int board[102][102];
int visited[102][102];
int dist[102][102];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n;
queue<pair<int, int>> q;
queue<pair<int, int>> bridge;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}

	//¼¶ ±¸ºÐÇÏ±â 
	int num = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] && !visited[i][j])
			{
				num++;
				q.push({ i,j });
				visited[i][j] = num;
			}

			while (!q.empty())
			{
				pair<int, int> cur = q.front(); q.pop();
				for (int dir = 0; dir < 4; dir++)
				{
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (!board[nx][ny] || visited[nx][ny]) continue;
					visited[nx][ny] = num;
					q.push({ nx,ny });
				}
			}
		}
	}

	int min_length = 987654321;

	//¼¶À» ±¸º°ÇØ ´Ù¸®Áþ±â 
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int x;
			for (int i = 0; i < n; i++)
				fill(dist[i], dist[i] + n, 0);

			if (board[i][j])
			{
				bridge.push({ i,j });
				x = visited[i][j];
			}

			while (!bridge.empty())
			{
				pair<int, int> cur = bridge.front(); bridge.pop();
				for (int dir = 0; dir < 4; dir++)
				{
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (visited[nx][ny] == x) continue;
					if (dist[nx][ny]) continue;
					dist[nx][ny] = dist[cur.X][cur.Y] + 1;

					if (visited[nx][ny] != x && visited[nx][ny] != 0)
					{
						min_length = min(min_length, dist[cur.X][cur.Y]);
						continue;
					}
					bridge.push({ nx,ny });
				}
			}
		}
	}

	cout << min_length;

	return 0;
}

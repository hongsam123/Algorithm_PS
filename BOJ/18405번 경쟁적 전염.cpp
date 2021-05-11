#include<iostream>
#include<queue>
#include<utility>
#define X first
#define Y second
using namespace std;

int n;
int k;
int board[202][202];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
queue<pair<int, int>> q;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}

	int s, x, y;
	cin >> s >> x >> y;
	
	while (s--)
	{
		if (board[x - 1][y - 1] != 0)
		{
			cout << board[x - 1][y - 1];
			return 0;
		}

		int virus = 1;
		while (1)
		{
			if (virus > k) break;

			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (board[i][j] == virus)
					{
						q.push({ i,j });
					}
				}
			}

			while (!q.empty())
			{
				pair<int, int> cur = q.front(); q.pop();
				for (int dir = 0; dir < 4; dir++)
				{
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (board[nx][ny]) continue;
					board[nx][ny] = virus;
				}
			}
			virus++;
		}
	}

	cout << board[x - 1][y - 1];

	return 0;
}

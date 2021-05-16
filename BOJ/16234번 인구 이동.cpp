#include<iostream>
#include<utility>
#include<queue>
#define X first
#define Y second
using namespace std;

int n, l, r;
int board[52][52];
int tmp[52][52];
int visited[52][52];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
queue <pair<int, int>> q;

void copy()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (visited[i][j]!=0 )
				board[i][j] = tmp[i][j];
	return;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> l >> r;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];

	int total_cnt = 0;
	while (1)
	{
		bool change = false;	//바뀌지 않을때까지 계속

		for (int k = 0; k < n; k++)
			fill(visited[k], visited[k] + n, 0);

		int stage = 1;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (visited[i][j] != 0) continue;	//이미 검사 했으면 통과
				q.push({ i,j });

				int cnt = 1;
				int total = board[i][j];
				while (!q.empty())
				{
					pair<int, int> cur = q.front(); q.pop();
					for (int dir = 0; dir < 4; dir++)
					{
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
						if (visited[nx][ny] !=0) continue;
						int x = abs(board[nx][ny] - board[cur.X][cur.Y]);
						if (x >= l && x <= r)	//국경을 열어야 하면
						{
							q.push({ nx,ny });
							visited[nx][ny] = stage;	//국경을 여는 나라
							if (visited[cur.X][cur.Y] != stage) visited[cur.X][cur.Y] = stage;
							cnt++;
							total += board[nx][ny];
						}
					}
				}

				if (cnt >= 2)
				{
					if (!change) change = true;
					int x = total / cnt;
					for (int a = 0; a < n; a++)
					{
						for (int b = 0; b < n; b++)
						{
							if (visited[a][b] == stage)
							{
								tmp[a][b] = x;
							}
						}
					}
				}
				stage++;
			}
		}

		copy();

		if (!change)
			break;
		else
			total_cnt++;
	}

	cout << total_cnt;

	return 0;
}

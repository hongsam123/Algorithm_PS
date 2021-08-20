#include<iostream>
#include<utility>
#include<queue>
#define X first
#define Y second
using namespace std;

int board[502][502];
int visit[502][502];
int n, m;

queue<pair<int, int>> q;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];

	int cnt=0;
	int mxsize = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (visit[i][j] != 1 && board[i][j] == 1)
			{
				q.push({ i,j });
				visit[i][j] = 1;
				cnt++;
				int tmpsize = 0;
				while (!q.empty())
				{
					pair<int, int> cur = q.front(); q.pop();
					tmpsize++;
					for (int dir = 0; dir < 4; dir++)
					{
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if (visit[nx][ny] || board[nx][ny] != 1) continue;
						visit[nx][ny] = 1;
						q.push({ nx,ny });
					}
				}
				//if (mxsize < tmpsize) mxsize = tmpsize;
				mxsize = max(mxsize, tmpsize);
			}
		}
	}

	cout << cnt << '\n' << mxsize;

	return 0;
}

#include<iostream>
#include<queue>
#include<utility>
#define X first
#define Y second
using namespace std;

char board[102][102];	//적록색약이 아닌 사람이 보는 맵
char board_rg[102][102];//적록색약인 사람이 보는 맵
bool visited[102][102];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int n;
int cnt, rg_cnt;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < n; j++)
		{
			board[i][j] = str[j];
			if (str[j] == 'G')
				board_rg[i][j] = 'R';
			else
				board_rg[i][j] = str[j];
		}
	}

	//cnt
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visited[i][j]) continue;
			q.push({ i,j });

			while (!q.empty())
			{
				pair<int, int> cur = q.front(); q.pop();
				for (int dir = 0; dir < 4; dir++)
				{
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (visited[nx][ny] || board[cur.X][cur.Y] != board[nx][ny]) continue;
					visited[nx][ny] = 1;
					q.push({ nx,ny });
				}
			}
			cnt++;
		}
	}

	for (int i = 0; i < n; i++)
	{
		fill(visited[i], visited[i] + n, 0);
	}

	//rg_cnt
	queue<pair<int, int>> q1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visited[i][j]) continue;
			q1.push({ i,j });

			while (!q1.empty())
			{
				pair<int, int> cur = q1.front(); q1.pop();
				for (int dir = 0; dir < 4; dir++)
				{
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (visited[nx][ny] || board_rg[cur.X][cur.Y] != board_rg[nx][ny]) continue;
					visited[nx][ny] = 1;
					q1.push({ nx,ny });
				}
			}
			rg_cnt++;
		}
	}

	cout << cnt << " " << rg_cnt;


	return 0;
}

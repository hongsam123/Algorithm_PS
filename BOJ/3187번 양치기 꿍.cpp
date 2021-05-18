#include<iostream>
#include<queue>
#include<utility>
#define X first
#define Y second
using namespace std;

int r, c;
char board[252][252];
int visited[252][252];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
queue<pair<int, int>> q;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < c; j++)
		{
			board[i][j] = str[j];
		}
	}

	int wolf = 0;
	int sheep = 0;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			int wnum = 0;
			int snum = 0;
			if (board[i][j] != '#' && visited[i][j] == 0)
			{
				q.push({ i,j });
				visited[i][j] = 1;
				if (board[i][j] == 'v')
					wnum++;
				if (board[i][j] == 'k')
					snum++;
			}

			while (!q.empty())
			{
				pair<int, int> cur = q.front(); q.pop();
				for (int dir = 0; dir < 4; dir++)
				{
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
					if (board[nx][ny] == '#' || visited[nx][ny]) continue;
					if (board[nx][ny] == 'v') wnum++;
					if (board[nx][ny] == 'k') snum++;
					visited[nx][ny] = 1;
					q.push({ nx,ny });
				}
			}

			if (snum > wnum)
				sheep += snum;
			else
				wolf += wnum;
		}
	}

	cout << sheep << " " << wolf;

	return 0;
}

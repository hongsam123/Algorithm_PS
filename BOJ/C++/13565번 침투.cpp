#include<iostream>
#include<queue>
#include<utility>
#define X first
#define Y second
using namespace std;

int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
queue<pair<int, int>> q;
int board[1002][1002];
int visited[1002][1002];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < m; j++)
		{
			board[i][j] = str[j] - '0';
			if (i == 0 && board[i][j] == 0)
			{
				q.push({ i,j });
				visited[i][j] = 1;
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
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board[nx][ny] == 1 || visited[nx][ny] == 1) continue;
			visited[nx][ny] = 1;
			q.push({ nx,ny });
		}
	}

	bool yes = false;
	for (int j = 0; j < m; j++)
	{
		if (visited[n - 1][j] == 1)
		{
			yes = true;
			break;
		}
	}

	if (yes)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}

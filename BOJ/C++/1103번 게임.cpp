#include<iostream>
#include<utility>
#include<algorithm>
#define X first
#define Y second
using namespace std;

int n, m;
int board[52][52];	//0은 구멍
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int visited[52][52];
int dp[52][52];	//해당 칸에 도착했을 경우 최대 갈수 있는 거리
int ans;

int dfs(int x, int y)
{
	//갈수 있는 경우 없음
	if (x < 0 || x >= n || y < 0 || y >= m) return 0;
	if (!board[x][y]) return 0;

	//예외(loop)
	if (visited[x][y])
	{
		cout << -1;
		exit(0);
	}

	int& ret = dp[x][y];	//?
	if (ret > 0) return ret;
	visited[x][y] = 1;

	ret = 1;
	for (int dir = 0; dir < 4; dir++)
	{
		int nx = x + (board[x][y] * dx[dir]);
		int ny = y + (board[x][y] * dy[dir]);
		ret = max(ret, dfs(nx, ny) + 1);
	}

	visited[x][y] = false;
	return ret;
}

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
			if (str[j] == 'H')
			{
				board[i][j] = 0;
			}
			else board[i][j] = str[j] - '0';
		}
	}

	cout<<dfs(0,0);

	return 0;
}

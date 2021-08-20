#include<iostream>
#include<queue>
#include<utility>
#include<algorithm>
#define X first
#define Y second
using namespace std;

int n, m;
int board[10][10];
int tmp[10][10];
bool visited[10][10];
bool isused[10][10];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int maxsize;
queue<pair<int, int>> q;

void count_max()
{
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (tmp[i][j] == 0)
				cnt++;
		}
	}
	if (maxsize < cnt)
	{
		maxsize = cnt;
	}
	return;
}

void bfs()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			tmp[i][j] = board[i][j];

	for (int i = 0; i < n; i++)
		fill(visited[i], visited[i] + m, 0);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (tmp[i][j] == 2 && !visited[i][j])
			{
				q.push({ i,j });
			}
				
			while (!q.empty())
			{
				pair<int, int> cur = q.front(); q.pop();
				for (int dir = 0; dir < 4; dir++)
				{
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (tmp[nx][ny] == 1 || visited[nx][ny]) continue;
					visited[nx][ny] = 1;
					tmp[nx][ny] = 2;
					q.push({ nx,ny });
				}
			}
		}
	}
}

void func(int k)	//브루트포스로 벽을 세울 수 있는 모든 경우의 수 시뮬레이션 
{
	if (k == 3)
	{
		bfs();			//바이러스 퍼트리기 
		count_max();	//최대값인지 확인 
		return;
	}

	for(int i=0;i<n;i++)	//백트래킹으로 벽 세우기 
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 0 && !isused[i][j])
			{
				board[i][j] = 1;
				isused[i][j] = 1;
				func(k + 1);

				board[i][j] = 0;
				isused[i][j] = 0;
			}
		}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for(int i=0;i<n;i++)
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}

	func(0);

	cout << maxsize;

	return 0;
}

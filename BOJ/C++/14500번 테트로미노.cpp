#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#define X first
#define Y second
using namespace std;

int n, m;
int board[502][502];
int isused[502][502];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
vector<pair<int, int>> tet;
int ans;

void tetromino(int x, int y, int k);

void dfs(int x, int y, int k)
{
	for (int dir = 0; dir < 4; dir++)
	{
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		if (isused[nx][ny]) continue;

		tet.push_back({ nx,ny });
		isused[nx][ny] = 1;

		tetromino(nx, ny, k + 1);

		tet.pop_back();
		isused[nx][ny] = 0;
	}
}


void tetromino(int x,int y,int k)
{
	if (k == 4)
	{
		int sum = 0;
		for (auto cur : tet)
			sum += board[cur.X][cur.Y];

		ans = max(ans, sum);

		return;
	}

	if (k == 3)	// ㅗ모양 예외처리
	{
		auto cur = tet[1];
		dfs(cur.X, cur.Y, k);
	}

	if (k == 0)
	{
		for (int i = x; i < n; i++)
		{
			for (int j = y; j < m; j++)
			{
				tet.push_back({ i,j });
				isused[i][j] = 1;

				dfs(i, j, k + 1);

				tet.pop_back();
				isused[i][j] = 0;
			}
		}
	}
	else
		dfs(x, y, k);

}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];


	tetromino(0,0,0);

	cout << ans;

	return 0;
}

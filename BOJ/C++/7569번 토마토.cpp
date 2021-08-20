#include<iostream>
#include<queue>
#include<tuple>
#include<utility>
using namespace std;

int board[101][101][101];
int dist[101][101][101];
int dz[6] = { 1,-1,0,0,0,0 };
int dx[6] = { 0,0,1,0,-1,0 };
int dy[6] = { 0,0,0,1,0,-1 };
int n, m, h;
queue<tuple<int, int, int>> q;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int ans = 0;
	cin >> m >> n >> h;

	for (int i = 0; i < h; i++)
		for (int j = 0; j < n; j++)
			fill(dist[i][j], dist[i][j] + m, -1);

	for (int i = 0; i < h; i++)
		for (int j = 0; j < n; j++)
			for (int z = 0; z < m; z++)
			{
				cin >> board[i][j][z];
				if (board[i][j][z] == 1)
				{
					q.push({ i,j,z });
					dist[i][j][z] = 0;
				}
			}

	while (!q.empty())
	{
		tuple<int, int, int> cur = q.front(); q.pop();
		for (int dir = 0; dir < 6; dir++)
		{
			int nh = get<0>(cur) + dz[dir];
			int nx = get<1>(cur) + dx[dir];
			int ny = get<2>(cur) + dy[dir];
			if (nh < 0 || nh >= h || nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board[nh][nx][ny] != 0 || dist[nh][nx][ny] >= 0) continue;
			dist[nh][nx][ny] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
			board[nh][nx][ny] = 1;
			q.push({ nh,nx,ny });
		}
	}

	for(int i=0;i<h;i++)
		for(int j=0;j<n;j++)
			for (int z = 0; z < m; z++)
			{
				if (board[i][j][z] == 0)
				{
					cout << -1;
					return 0;
				}
				ans = max(dist[i][j][z], ans);
			}

	cout << ans;

	return 0;
}


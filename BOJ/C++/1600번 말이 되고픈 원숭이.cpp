#include<iostream>
#include<queue>
#include<tuple>
#include<algorithm>
using namespace std;

int k;
int n,m;
int board[202][202];
bool visited[202][202][32];	//�ش� ��ġ�� �� �̵��� ���°�ߴ���
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int horse_dx[8] = {-2,-1,1,2,2,1,-1,-2};
int horse_dy[8] = {1,2,2,1,-1,-2,-2,-1};
queue<tuple<int, int, int,int>> q;	//<x,y,�� �̵��� Ƚ��, �� �Ÿ�>
int ans=-1;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> k >> m >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];

	visited[0][0][0] = 1;
	q.push({ 0,0,0,0 });

	while (!q.empty())
	{
		auto cur = q.front(); q.pop();

		int x = get<0>(cur);
		int y = get<1>(cur);
		int horse = get<2>(cur);
		int cnt = get<3>(cur);

		if (x == n - 1 && y == m - 1)
		{
			ans = cnt;
			break;
		}

		if (horse < k)
		{
			for (int dir = 0; dir < 8; dir++)
			{
				int nx = x + horse_dx[dir];
				int ny = y + horse_dy[dir];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
				if (board[nx][ny] || visited[nx][ny][horse+1]) continue;	//�̵��� �� ���ų� �湮�ߴ� ��
				visited[nx][ny][horse + 1] = 1;
				
				q.push({ nx,ny,horse + 1,cnt + 1 });
			}
		}

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (board[nx][ny] || visited[nx][ny][horse]) continue;
			visited[nx][ny][horse] = 1;	//�湮�� ���ߴٸ� �������� �̵��� �� �ڿ��� ť�� �ִ´�

			q.push({ nx,ny,horse,cnt+1 });
		}
	}

	if (ans == -1)
		cout << -1;
	else
		cout << ans;

	return 0;
}

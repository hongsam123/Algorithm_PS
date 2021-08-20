#include<iostream>
using namespace std;

int r, c;
int x, y, dir;	//현재 청소기 위치, 보는 방향(0:상, 1:우, 2:하, 3:좌)
int board[52][52];	// (0:청소x, 1:벽, 2:청소o)
int ans;
int dx[4] = { -1,0,1,0 };	//상, 우, 하, 좌 순서
int dy[4] = { 0,1,0,-1 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c;

	cin >> x >> y >> dir;

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			cin >> board[i][j];

	while (1)
	{
		// 1
		if (board[x][y] == 0)
		{
			board[x][y] = 2;
			ans++;
		}
		if (board[x][y] == 1)	//2-d
			break;

		//2-b
		bool impo = true;
		for (int i = 0; i < 4; i++)
		{
			dir = (dir+3)%4;
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			//2-a
			if (board[nx][ny] == 0)
			{
				x = nx;
				y = ny;
				impo = false;
				break;
			}
		}

		//2-c
		if (impo)
		{
			int ndir = (dir + 2) % 4;
			x = x + dx[ndir];
			y = y + dy[ndir];
		}
	}

	cout << ans;

	return 0;
}

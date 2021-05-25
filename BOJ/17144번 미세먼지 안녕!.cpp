#include<iostream>
#include<utility>
#include<queue>
#include<vector>
#define X first
#define Y second
using namespace std;

int r, c, t;
int map[52][52];
int tmp[52][52];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
queue<pair<int, int>> dust;
vector<pair<int, int>> cleaner;

void plusDust()
{
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if(map[i][j]!=-1)
				map[i][j] = tmp[i][j];
}

void spreadDust()
{
	for (int i = 0; i < r; i++)
		fill(tmp[i], tmp[i] + c+1, 0);

	while (!dust.empty())
	{
		pair<int, int> cur = dust.front(); dust.pop();
		int num = 0;
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= r || ny<0 || ny>=c) continue;
			if (map[nx][ny] == -1) continue;
			tmp[nx][ny] += map[cur.X][cur.Y] / 5;
			num++;
		}
		tmp[cur.X][cur.Y] += map[cur.X][cur.Y]-((map[cur.X][cur.Y] / 5) * num);
	}

	plusDust();
}

void operation()
{
	//반시계방향
	int x = cleaner[0].X;
	int y = cleaner[0].Y;
	y++;
	int pre = map[x][y];
	map[x][y] = 0;
	y++;
	while (y < c)	//우로 이동
	{
		int n = map[x][y];
		map[x][y] = pre;
		pre = n;
		y++;
	}
	y--; x--;
	while (x >= 0)	//위로 이동
	{
		int n = map[x][y];
		map[x][y] = pre;
		pre = n;
		x--;
	}
	x++; y--;
	while (y >= 0)	//좌로 이동
	{
		int n = map[x][y];
		map[x][y] = pre;
		pre = n;
		y--;
	}
	y++; x++;
	while (x != cleaner[0].X)	//아래로 이동
	{
		int n = map[x][y];
		map[x][y] = pre;
		pre = n;
		x++;
	}

	//시계방향
	x = cleaner[1].X;
	y = cleaner[1].Y;
	y++;
	pre = map[x][y];
	map[x][y] = 0;
	y++;
	while (y < c)	//우로 이동
	{
		int n = map[x][y];
		map[x][y] = pre;
		pre = n;
		y++;
	}
	y--; x++;
	while (x < r)	//아래로 이동
	{
		int n = map[x][y];
		map[x][y] = pre;
		pre = n;
		x++;
	}
	x--; y--;
	while (y >= 0)	//좌로 이동
	{
		int n = map[x][y];
		map[x][y] = pre;
		pre = n;
		y--;
	}
	y++; x--;
	while (x != cleaner[1].X)	//위로 이동
	{
		int n = map[x][y];
		map[x][y] = pre;
		pre = n;
		x--;
	}
}

void countDust()
{
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (map[i][j] > 0)
				dust.push({ i,j });
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c >> t;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == -1) cleaner.push_back({ i,j });
			if (map[i][j] > 0) dust.push({ i,j });
		}
	}

	while (t--)
	{
		spreadDust();	//먼지 확산

		operation();	//공기청정기 작동

		countDust();	//먼지 큐 채우기
	}

	int ans = 0;
	for(int i=0;i<r;i++)
		for (int j = 0; j < c; j++)
			if (map[i][j] > 0)
				ans += map[i][j];

	cout << ans;

	return 0;
}
//먼지 큐를 채우는 것을 확산 후 시도 했다가 헤맸다
//먼지 위치를 저장하는 것이므로 공청으로  먼지가 이동한 후 먼지 큐를 채워야함

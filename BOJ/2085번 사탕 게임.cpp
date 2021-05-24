#include<iostream>
using namespace std;

int n;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
char map[52][52];
char tmp[52][52];
int ans;

void bomboni(int x, int y)
{
	for (int dir = 0; dir < 4; dir++)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				tmp[i][j] = map[i][j];

		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

		//change
		char temp = tmp[x][y];
		tmp[x][y] = tmp[nx][ny];
		tmp[nx][ny] = temp;

		//count1 - 위아래로 count
		char candy = tmp[x][y];
		int cnt = 1;
		int tx = x - 1;
		while (tx >= 0 && tmp[tx][y] == candy)
		{
			tx -= 1;
			cnt++;
		}
		tx = x + 1;
		while (tx < n && tmp[tx][y] == candy)
		{
			tx += 1;
			cnt++;
		}
		ans = max(ans, cnt);

		//count2 - 좌우로 count
		cnt = 1;
		int ty = y - 1;
		while (ty >= 0 && tmp[x][ty] == candy)
		{
			ty -= 1;
			cnt++;
		}
		ty = y + 1;
		while (ty < n && tmp[x][ty] == candy)
		{
			ty += 1;
			cnt++;
		}
		ans = max(ans, cnt);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < n; j++)
			map[i][j] = str[j];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			bomboni(i, j);
	}

	cout << ans;

	return 0;
}

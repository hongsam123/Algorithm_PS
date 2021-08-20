#include<iostream>
#include<queue>
#include<utility>
#include<algorithm>
#define X first
#define Y second
using namespace std;

int r, c;
char board[52][52];
int gosmdist[52][52];
int flodist[52][52];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

queue<pair<int, int>> gosm;
queue<pair<int, int>> flood;
pair<int, int> home;

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
			if (board[i][j] == 'D')
				home = { i,j };
		}
	}

	for (int i = 0; i < r; i++)
	{
		fill(gosmdist[i], gosmdist[i] + c, -1);
		fill(flodist[i], flodist[i] + c, -1);
	}

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (board[i][j] == 'S')
				gosm.push({ i,j });

			if (board[i][j] == '*')
				flood.push({ i,j });
		}
	}

	//È«¼ö bfs
	while (!flood.empty())
	{
		auto cur = flood.front(); flood.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
			if (flodist[nx][ny]>=0 || board[nx][ny] == 'D'||board[nx][ny]=='X') continue;
			flodist[nx][ny] = flodist[cur.X][cur.Y] + 1;
			flood.push({ nx,ny });
		}
	}

	//°í½¿µµÄ¡ bfs
	while (!gosm.empty())
	{
		auto cur = gosm.front(); gosm.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
			if (gosmdist[nx][ny]>=0 || board[nx][ny] == '*'||board[nx][ny]=='X') continue;
			if (gosmdist[cur.X][cur.Y] + 1 >= flodist[nx][ny] && flodist[nx][ny]!=-1) continue;
			gosmdist[nx][ny] = gosmdist[cur.X][cur.Y] + 1;
			gosm.push({ nx,ny });
		}
	}

	if (gosmdist[home.X][home.Y]<0)
		cout << "KAKTUS";
	else
		cout << gosmdist[home.X][home.Y]+1;


	return 0;
}

//ºÒ!ÀÌ¶û °ÅÀÇ µ¿ÀÏ 

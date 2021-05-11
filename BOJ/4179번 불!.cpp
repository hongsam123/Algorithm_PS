#include<iostream>
#include<queue>
#include<utility>
#define X first
#define Y second
using namespace std;

char board[1002][1002];
int fireDist[1002][1002];
int mazeEscape[1002][1002];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

queue<pair<int, int>> fireQueue;
queue<pair<int, int>> mazeQueue;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int r, c;
	cin >> r >> c;

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			cin >> board[i][j];
	
	for (int i = 0; i < r; i++)
	{
		fill(fireDist[i], fireDist[i] + c, -1);
		fill(mazeEscape[i], mazeEscape[i] + c, -1);
	}

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (board[i][j] == 'F')
			{
				fireDist[i][j] = 0;
				fireQueue.push({ i,j });
			}
			if (board[i][j] == 'J')
			{
				mazeEscape[i][j] = 0;
				mazeQueue.push({ i,j });
			}
		}
	}

	//불에 대한 BFS
	while (!fireQueue.empty())
	{
		pair<int, int> cur = fireQueue.front(); fireQueue.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
			if (fireDist[nx][ny] >= 0 || board[nx][ny] == '#') continue;
			fireDist[nx][ny] = fireDist[cur.X][cur.Y] + 1;
			fireQueue.push({ nx,ny });
		}
	}
	//수행하고 나면 해당 지점에 불이 언제 붙는지 저장된다

	//지훈이에 대한 BFS
	while (!mazeQueue.empty())
	{
		pair<int, int> cur = mazeQueue.front(); mazeQueue.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
			if (mazeEscape[nx][ny] >= 0 || board[nx][ny] == '#') continue;
			if (mazeEscape[cur.X][cur.Y] + 1 >= fireDist[nx][ny] && fireDist[nx][ny]!=-1)continue;
			mazeEscape[nx][ny] = mazeEscape[cur.X][cur.Y] + 1;
			mazeQueue.push({ nx,ny });
		}
	}

	int ans = 987654321;
	bool impo = true;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (i == 0 || i == r - 1 || j == 0 || j == c - 1)
			{
				if (mazeEscape[i][j] >= 0)
				{
					impo = false;
					ans = min(ans, mazeEscape[i][j]);
				}
			}
		}
	}

	if (impo)
		cout << "IMPOSSIBLE";
	else
		cout << ans+1;

	return 0;
}
//지훈이에 대한 BFS에서 중간에 가장자리에 도달한 경우에는(범위를 벗어난 경우에는)
//탈출에 성공했다는 의미. (큐에 거리순으로 들어가기 때문에 최초에 탈출한 시간 출력이 가능하다)
//다시말해 큐가 비어서 탈출한 경우에는 미로탈출에 실패했다는 의미.( 바로 IMPOSSIBLE을 출력해도 된다)
//==>> 다시 풀어보기

//이 문제는 하나의 BFS를 전부 돌고 다른 BFS를 돈 문제
//만약 각 BFS가 다른 BFS에 영향을 미친다면 이런 방법으로 풀 수 없음 => 시간 순으로 BFS를 동시에 돌려야 함 

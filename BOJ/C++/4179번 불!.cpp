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

	//�ҿ� ���� BFS
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
	//�����ϰ� ���� �ش� ������ ���� ���� �ٴ��� ����ȴ�

	//�����̿� ���� BFS
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
//�����̿� ���� BFS���� �߰��� �����ڸ��� ������ ��쿡��(������ ��� ��쿡��)
//Ż�⿡ �����ߴٴ� �ǹ�. (ť�� �Ÿ������� ���� ������ ���ʿ� Ż���� �ð� ����� �����ϴ�)
//�ٽø��� ť�� �� Ż���� ��쿡�� �̷�Ż�⿡ �����ߴٴ� �ǹ�.( �ٷ� IMPOSSIBLE�� ����ص� �ȴ�)
//==>> �ٽ� Ǯ���

//�� ������ �ϳ��� BFS�� ���� ���� �ٸ� BFS�� �� ����
//���� �� BFS�� �ٸ� BFS�� ������ ��ģ�ٸ� �̷� ������� Ǯ �� ���� => �ð� ������ BFS�� ���ÿ� ������ �� 

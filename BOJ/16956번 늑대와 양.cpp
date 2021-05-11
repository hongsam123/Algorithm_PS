#include<iostream>
#include<queue>
#include<utility>
#define X first
#define Y second
using namespace std;

int r, c;
char board[502][502];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void print()
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << board[i][j];
		}
		cout << "\n";
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c;

	char ch;
	bool posi = true;
	queue<pair<int, int>> q;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> ch;
			board[i][j] = ch;
			if (ch == 'S')
			{
				q.push({ i,j });
			}
		}
	}

	while (!q.empty())
	{
		pair<int, int> cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
			if (board[nx][ny] == 'W')
			{
				posi = false;
				break;
			}
			if (board[nx][ny] == '.')	//상하좌우가 비어있으면 울타리 세우기 
				board[nx][ny] = 'D';
		}
		if (!posi)
			break;
	}

	
	if (posi)
	{
		cout << 1 << "\n";
		print();
	}
	else
	{
		cout << 0;
	}

	return 0;
}

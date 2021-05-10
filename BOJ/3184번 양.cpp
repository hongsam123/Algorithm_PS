#include<iostream>
#include<queue>
#include<utility>
#define X first
#define Y second
using namespace std;

int n, m;
char board[252][252];
bool visited[252][252];
queue < pair<int, int> > q;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	int wolf = 0;		//��Ƴ��� v(����) ��
	int sheep = 0;		//��Ƴ��� o(��) ��

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		
		for (int j = 0; j < m; j++)
		{
			board[i][j] = str[j];
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int wolf_tmp = 0;
			int sheep_tmp = 0;

			if (board[i][j] != '#' && visited[i][j] == false)
			{
				if (board[i][j] == 'o')
					sheep_tmp++;
				if (board[i][j] == 'v')
					wolf_tmp++;
				visited[i][j] = true;
				q.push({ i,j });
			}

			while (!q.empty())
			{
				pair<int, int> cur = q.front(); q.pop();
				for (int dir = 0; dir < 4; dir++)
				{
					int nx = dx[dir] + cur.X;
					int ny = dy[dir] + cur.Y;
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (board[nx][ny] == '#' || visited[nx][ny]) continue;
					if (board[nx][ny] == 'o') sheep_tmp++;
					if (board[nx][ny] == 'v') wolf_tmp++;
					visited[nx][ny] = true;
					q.push({ nx,ny });
				}
			}

			if (wolf_tmp < sheep_tmp)	//���� ������ �� ���� �� ������ ���븦 �i�Ƴ���
										//�ƴ϶�� ��Ƹ�����
				sheep += sheep_tmp;
			else
				wolf += wolf_tmp;
		}
	}

	cout << sheep << " " << wolf;

	return 0;
}

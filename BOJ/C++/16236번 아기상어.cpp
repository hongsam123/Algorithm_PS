#include<iostream>
#include<queue>
#include<utility>
#include<algorithm>
#define X first
#define Y second
#define max_int 22
#define max_dist 401
using namespace std;

int board[22][22];
int visited[22][22];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { -1,1,0,0 };
int n;
int min_x, min_y,min_dist;
int shark_size,cnt,result;

void init()
{
	min_x = max_int;
	min_y = max_int;
	min_dist = max_dist;
	for (int i = 0; i < n; i++)
		fill(visited[i], visited[i] + n + 1, -1);
}

void bfs(int x, int y)		//������ �ִ� ������� ��ġ�� ����
{
	queue<pair<int, int>> q;
	visited[x][y] = 0;
	q.push({ x,y });

	while (!q.empty())
	{
		pair<int, int> cur = q.front(); q.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			//���� ���� ���
			if (board[nx][ny] > shark_size || visited[nx][ny] != -1) continue;
			//�̹� �湮 �߰ų� ��� ũ�⺸�� ū���
			visited[nx][ny] = visited[cur.X][cur.Y] + 1;
			if (board[nx][ny] < shark_size && board[nx][ny] > 0)
				//���� �� �ִ� ���
			{
				if (min_dist > visited[nx][ny])	
				//������� �ּ� �̵��Ÿ����� ª�����
				{
					min_x = nx;
					min_y = ny;
					min_dist = visited[nx][ny];
				}
				else if (min_dist == visited[nx][ny])
				//�̵� �Ÿ��� ��������� �ּ� �̵��Ÿ��� ���� ���
				{
					if (min_x == nx)
					{
						if (min_y > ny){
							min_x = nx;
							min_y = ny;
						}
					}
					else if(min_x > nx)
					{
						min_x = nx;
						min_y = ny;
					}
				}
			}
			q.push({ nx,ny });
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int shark_x, shark_y;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 9)
			{
				board[i][j] = 0;
				shark_x = i;
				shark_y = j;
			}
		}

	shark_size = 2;
	cnt = 0;

	while (1)
	{
		init();

		bfs(shark_x, shark_y);

		if (min_x != max_int && min_y != max_int)	//������ �ִ� ����Ⱑ �ִ� ���
		{
			board[min_x][min_y] = 0;
			cnt++;
			if (cnt == shark_size)
			{
				shark_size++;
				cnt = 0;
			}
			result += visited[min_x][min_y];
			shark_x = min_x;
			shark_y = min_y;
		}
		else
			break;
	}	

	cout << result;

	return 0;
}


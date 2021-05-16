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

void bfs(int x, int y)		//먹을수 있는 물고기의 위치를 결정
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
			//범위 밖인 경우
			if (board[nx][ny] > shark_size || visited[nx][ny] != -1) continue;
			//이미 방문 했거나 상어 크기보다 큰경우
			visited[nx][ny] = visited[cur.X][cur.Y] + 1;
			if (board[nx][ny] < shark_size && board[nx][ny] > 0)
				//먹을 수 있는 경우
			{
				if (min_dist > visited[nx][ny])	
				//현재까지 최소 이동거리보다 짧은경우
				{
					min_x = nx;
					min_y = ny;
					min_dist = visited[nx][ny];
				}
				else if (min_dist == visited[nx][ny])
				//이동 거리가 현재까지의 최소 이동거리와 같은 경우
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

		if (min_x != max_int && min_y != max_int)	//먹을수 있는 물고기가 있는 경우
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


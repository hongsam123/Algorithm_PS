#include<iostream>
using namespace std;

struct info
{
	int x, y, dir;
};
info fish[17];
int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0,-1,-1,-1,0,1,1,1 };
int result;
int arr[4][4];	//물고기 배열
				//1~16 : 물고기, 0 : 상어, -1: 죽은 물고기

void fish_move()
{
	for (int i = 1; i <= 16; i++)
	{
		int x = fish[i].x;
		int y = fish[i].y;
		int dir = fish[i].dir;

		if (dir == -1) continue;	//죽은 물고기
		
		int nx, ny;
		int ndir = dir;
		for (int j = 0; j < 8; j++)
		{
			nx = x + dx[ndir];
			ny = y + dy[ndir];
			if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4)
				ndir = (ndir + 1) % 8;
			else
			{
				int idx = arr[nx][ny];
				if (idx == 0)	//상어라면
				{
					ndir = (ndir + 1) % 8;
					continue;
				}
				//물고기 자리 교환
				arr[nx][ny] = i;
				fish[i].x = nx;
				fish[i].y = ny;
				fish[i].dir = ndir;

				arr[x][y] = idx;
				fish[idx].x = x;
				fish[idx].y = y;
				break;
			}
		}
	}
}


void dfs(int x, int y, int dir, int sum)
{
	info dup_fish[17];
	int dup_arr[4][4];

	for (int i = 1; i < 17; i++)
		dup_fish[i] = fish[i];

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			dup_arr[i][j] = arr[i][j];
	//물고기 정보와 위치 정보 복사

	fish_move();
	//물고기 이동

	//상어 이동
	int nx = x;
	int ny = y;
	while (1)
	{
		nx += dx[dir];
		ny += dy[dir];
		if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) break;
		else
		{
			int idx = arr[nx][ny];
			if (idx == -1) continue;	//이동한 자리에 물고기가 없는 경우
			
			int new_dir = fish[idx].dir;
			fish[idx].dir = -1;		//물고기 죽음
			arr[x][y] = -1;			//물고기 없음
			arr[nx][ny] = 0;		//상어 이동
			dfs(nx, ny, new_dir, sum + idx);

			//원래대로 복구
			fish[idx].dir = new_dir;
			arr[x][y] = 0;
			arr[nx][ny] = idx;
		}
	}
	result = max(result, sum);

	//원래대로 복구
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			arr[i][j] = dup_arr[i][j];

	for (int i = 0; i < 17; i++)
		fish[i] = dup_fish[i];

	return;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b, val;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			cin >> a >> b;
			arr[i][j] = a;
			fish[a].x = i;
			fish[a].y = j;
			fish[a].dir = b-1;
		}
	val = arr[0][0];
	int start_dir = fish[val].dir;
	arr[0][0] = 0;
	fish[val].dir = -1;

	dfs(0, 0, start_dir, val);

	cout << result;

	return 0;
}

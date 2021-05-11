#include<iostream>
#include<utility>
#include<deque>
#include<queue>
#define X first
#define Y second
using namespace std;

int board[102][102];	//0 : 비어있음, 1 : 뱀, 2 : 사과
int n, k, l;
int dx[4] = { 0,1,0,-1 };	
int dy[4] = { 1,0,-1,0 };
//우, 하, 좌, 상 방향 표시

int turn(int dir,char op)
{
	if (op == 'D')	//오른쪽 90도 회전
	{
		dir++;
		if (dir == 4) dir = 0;
	}
	else
		//왼쪽으로 90도 회전
	{
		dir--;
		if (dir < 0) dir = 3;
	}

	return dir;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < k; i++)
	{
		int x, y;
		cin >> x >> y;
		board[x-1][y-1] = 2;
	}
	
	queue<pair<int, char>> dir_change;
	cin >> l;
	for (int i = 0; i < l; i++)
	{
		int t;
		char d;
		cin >> t >> d;
		dir_change.push({ t,d });
	}

	deque<pair<int, int>> snake;
	snake.push_back({ 0,0 });
	board[0][0] = 1;

	int time = 0;
	int dir = 0;	//처음 보고 있는 방향은 오른쪽
	while (1)
	{
		time++;

		pair<int, int> pre_head = snake.front();
		pair<int, int> new_head = { pre_head.X + dx[dir],pre_head.Y + dy[dir] };
		if (new_head.X < 0 || new_head.X >= n || new_head.Y < 0 || new_head.Y >= n) break;	//벽에 부딪히면 게임 끝
		if (board[new_head.X][new_head.Y] == 1) break;	//자기 몸에 부딪히면 게임 끝
		if (board[new_head.X][new_head.Y] != 2)	//사과가 없다면
		{
			pair<int, int> tail = snake.back();
			snake.pop_back();
			board[tail.X][tail.Y] = 0;
			//꼬리를 줄이고 board에 빈칸으로 표시
		}	//사과가 있다면 꼬리는 그대로 두고 머리만 추가
		snake.push_front({ new_head.X,new_head.Y });
		board[new_head.X][new_head.Y] = 1;

		//time초의 게임이 지나고
		if (!dir_change.empty())
		{
			pair<int, char> dc = dir_change.front();
			if (time == dc.X)	//방향을 바꿀 시간이면
			{
				dir_change.pop();
				dir = turn(dir, dc.Y);	//새로운 방향 정보
			}
		}
	}

	cout << time;

	return 0;
}

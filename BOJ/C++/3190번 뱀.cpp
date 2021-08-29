#include<iostream>
#include<utility>
#include<deque>
#include<queue>
#define X first
#define Y second
using namespace std;

int board[102][102];	//0 : �������, 1 : ��, 2 : ���
int n, k, l;
int dx[4] = { 0,1,0,-1 };	
int dy[4] = { 1,0,-1,0 };
//��, ��, ��, �� ���� ǥ��

int turn(int dir,char op)
{
	if (op == 'D')	//������ 90�� ȸ��
	{
		dir++;
		if (dir == 4) dir = 0;
	}
	else
		//�������� 90�� ȸ��
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
	int dir = 0;	//ó�� ���� �ִ� ������ ������
	while (1)
	{
		time++;

		pair<int, int> pre_head = snake.front();
		pair<int, int> new_head = { pre_head.X + dx[dir],pre_head.Y + dy[dir] };
		if (new_head.X < 0 || new_head.X >= n || new_head.Y < 0 || new_head.Y >= n) break;	//���� �ε����� ���� ��
		if (board[new_head.X][new_head.Y] == 1) break;	//�ڱ� ���� �ε����� ���� ��
		if (board[new_head.X][new_head.Y] != 2)	//����� ���ٸ�
		{
			pair<int, int> tail = snake.back();
			snake.pop_back();
			board[tail.X][tail.Y] = 0;
			//������ ���̰� board�� ��ĭ���� ǥ��
		}	//����� �ִٸ� ������ �״�� �ΰ� �Ӹ��� �߰�
		snake.push_front({ new_head.X,new_head.Y });
		board[new_head.X][new_head.Y] = 1;

		//time���� ������ ������
		if (!dir_change.empty())
		{
			pair<int, char> dc = dir_change.front();
			if (time == dc.X)	//������ �ٲ� �ð��̸�
			{
				dir_change.pop();
				dir = turn(dir, dc.Y);	//���ο� ���� ����
			}
		}
	}

	cout << time;

	return 0;
}

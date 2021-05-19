#include<iostream>
#include<queue>
#include<utility>
#define X first
#define Y second
using namespace std;

int n;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
char board[8][8];
queue < pair<int, int>> teacher;
bool ans;

bool check(int x, int y, int dir)
//���� ���� ����dir���� �л��� ã���� true
//��ֹ��� �����ų� ������ �Ѿ�� false
{
	int nx = x + dx[dir];
	int ny = y + dy[dir];
	if (board[nx][ny] == 'S') return true;
	if (nx < 0 || nx>=n||ny < 0 || ny >= n) return false;
	if (board[nx][ny] == 'O')	return false;
	return check(nx, ny, dir);	//X�� T�� ��� ��� ����
}

void dfs()	//������ ��ֹ� ������ �˻�
{
	queue<pair<int, int>> tmp = teacher;

	bool notfind = true;
	while (!tmp.empty())
	{
		pair<int, int> cur = tmp.front(); tmp.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			if (check(cur.X, cur.Y, dir) == true)	//ã����
				if (notfind) notfind = false;
		}
	}
	if (notfind) ans = true;	//��ã������(���縦 �������� ǥ��
	return;
}

void func(int num)	//n+1��° ��ֹ��� ����� �Լ�
{
	if (num == 3)	//��ֹ��� 3�� ���� ä���� ��
	{
		dfs();		//�˻�
		if (ans)	//���ø� ���� �� �ִٸ� yes ����� �ٷ� ����
		{
			cout << "YES";
			exit(0);
		}
		return;
	}

	for (int i = 0; i < n; i++)	//��� �������� ��ֹ� �����
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] != 'X') continue;
			board[i][j] = 'O';
			func(num + 1);
			board[i][j] = 'X';
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 'T')
				teacher.push({ i,j });
		}
	}

	func(0);

	cout << "NO";

	return 0;
}
//���̾��� 0(����)�� O(�빮�� o)�� ������ �ȵż� 1�ð��� ��ɤ���;; 


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
//현재 보는 방향dir에서 학생을 찾으면 true
//장애물을 만나거나 범위를 넘어가면 false
{
	int nx = x + dx[dir];
	int ny = y + dy[dir];
	if (board[nx][ny] == 'S') return true;
	if (nx < 0 || nx>=n||ny < 0 || ny >= n) return false;
	if (board[nx][ny] == 'O')	return false;
	return check(nx, ny, dir);	//X나 T인 경우 계속 보기
}

void dfs()	//세워진 장애물 가지고 검사
{
	queue<pair<int, int>> tmp = teacher;

	bool notfind = true;
	while (!tmp.empty())
	{
		pair<int, int> cur = tmp.front(); tmp.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			if (check(cur.X, cur.Y, dir) == true)	//찾으면
				if (notfind) notfind = false;
		}
	}
	if (notfind) ans = true;	//못찾았으면(감사를 피했으면 표시
	return;
}

void func(int num)	//n+1번째 장애물을 세우는 함수
{
	if (num == 3)	//장애물을 3개 전부 채웠을 때
	{
		dfs();		//검사
		if (ans)	//감시를 피할 수 있다면 yes 출력후 바로 종료
		{
			cout << "YES";
			exit(0);
		}
		return;
	}

	for (int i = 0; i < n; i++)	//모든 조합으로 장애물 세우기
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
//어이없다 0(숫자)랑 O(대문자 o)랑 구별이 안돼서 1시간을 헤맴ㅋㅋ;; 


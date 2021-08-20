#include<iostream>
#include<utility>
#include<queue>
#define X first
#define Y second
using namespace std;

int n;
int dx[3] = {0,1,1};	//오른쪽, 대각선, 아래
int dy[3] = {1,1,0};
queue < pair< pair<int,int>, int>> q;	//<파이프의 새 위치, 현재 놓여있는 상태(1:가로, 2:세로, 3:대각선)>
int board[18][18];
int ans;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for(int i=1;i<=n;i++)
		for (int j = 1; j <= n; j++)
			cin >> board[i][j];
	
	q.push({ {1,2},1 });	//처음에 가로로 놓여있음 

	while (!q.empty())
	{
		pair<int, int> cur = q.front().first;
		int d = q.front().second;
		q.pop();
		if (cur.X == n && cur.Y == n)
		{
			ans++;
			continue;
		}

		for (int dir = 0; dir < 3; dir++)
		{
			if ((d == 1 && dir == 2) || (d == 2 && dir == 0)) continue;	//갈 수 없는 경우 
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx<1 || ny<1 || nx>n || ny>n) continue;
			if (board[nx][ny]) continue;
			if (dir == 1 && (board[nx - 1][ny] || board[nx][ny - 1])) continue;	//대각선일 때 빈칸인지 추가로 고려 
			if (dir == 0) q.push({ {nx,ny},1 });	//오른쪽(0)으로 가면 가로(1)
			if (dir == 1) q.push({ {nx,ny},3 });	//대각선(1)으로 가면 대각선(3)
			if (dir == 2) q.push({ {nx,ny},2 });	//아래(2)로 가면 세로(2)
		}
	}

	cout << ans;

	return 0;
}

#include<iostream>
#include<utility>
#include<queue>
#define X first
#define Y second
using namespace std;

int n;
int dx[3] = {0,1,1};	//������, �밢��, �Ʒ�
int dy[3] = {1,1,0};
queue < pair< pair<int,int>, int>> q;	//<�������� �� ��ġ, ���� �����ִ� ����(1:����, 2:����, 3:�밢��)>
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
	
	q.push({ {1,2},1 });	//ó���� ���η� �������� 

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
			if ((d == 1 && dir == 2) || (d == 2 && dir == 0)) continue;	//�� �� ���� ��� 
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx<1 || ny<1 || nx>n || ny>n) continue;
			if (board[nx][ny]) continue;
			if (dir == 1 && (board[nx - 1][ny] || board[nx][ny - 1])) continue;	//�밢���� �� ��ĭ���� �߰��� ��� 
			if (dir == 0) q.push({ {nx,ny},1 });	//������(0)���� ���� ����(1)
			if (dir == 1) q.push({ {nx,ny},3 });	//�밢��(1)���� ���� �밢��(3)
			if (dir == 2) q.push({ {nx,ny},2 });	//�Ʒ�(2)�� ���� ����(2)
		}
	}

	cout << ans;

	return 0;
}

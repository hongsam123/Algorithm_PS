#include<iostream>
#include<queue>
#include<tuple>
#include<algorithm>
#define X first 
#define Y second
using namespace std;

int l, r, c;
char board[32][32][32];
int dist[32][32][32];
int dl[6] = { 0,0,0,0,1,-1 };
int dx[6] = { 1, 0, -1, 0, 0, 0 };
int dy[6] = { 0, 1, 0, -1, 0, 0 };
bool posi;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (1)
	{
		queue<tuple<int, int, int>> q;
		int min_time = 0;
		posi = false;

		cin >> l >> r >> c;

		for (int i = 0; i < l; i++)
			for (int j = 0; j < r; j++)
				fill(dist[i][j], dist[i][j] + c, -1);

		if (l == 0 && r == 0 && c == 0) break;	//종료조건
		for (int i = 0; i < l; i++)
			for (int j = 0; j < r; j++)
				for (int k = 0; k < c; k++)
				{
					cin >> board[i][j][k];
					if (board[i][j][k] == 'S')
					{
						dist[i][j][k] = 0;
						q.push({ i,j,k });	//시작점
					}
				}

		while (!q.empty())
		{
			tuple<int, int, int> cur = q.front(); q.pop();
			for (int dir = 0; dir < 6; dir++)
			{
				int nl = get<0>(cur) + dl[dir];
				int nx = get<1>(cur) + dx[dir];
				int ny = get<2>(cur) + dy[dir];
				if (nl < 0 || nx < 0 || ny < 0 || nl >= l || nx >= r || ny >= c) continue;
				if (board[nl][nx][ny] == '#' || dist[nl][nx][ny] != -1) continue;
				dist[nl][nx][ny] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
				if (board[nl][nx][ny] == 'E')
				{
					posi = true;
					min_time = dist[nl][nx][ny];
					break;
				}
				q.push({ nl,nx,ny });
			}
			if (posi)
				break;
		}
		if (posi)
			cout << "Escaped in " << min_time << " minute(s).\n";
		else
			cout << "Trapped!\n";
		
	}


	return 0;
}

#include<iostream>
#include<queue>
#include<tuple>
#include<vector>
#include<algorithm>
#define tii tuple<int,int,int>
using namespace std;

int n;
int board[127][127];
int dist[127][127];
priority_queue<tii, vector<tii>, greater<tii>> pq;	//cost,x,y
const int INF = 1e9 + 10;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 0;
	while (1)
	{
		t++;

		cin >> n;
		if (n == 0) break;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int x;
				cin >> x;
				board[i][j] = x;
			}
		}

		for (int i = 0; i < n; i++)
			fill(dist[i], dist[i] + n + 1, INF);

		dist[0][0] = board[0][0];
		pq.push({ dist[0][0],0,0 });

		while (!pq.empty())
		{
			int cost, x, y;
			tie(cost, x, y) = pq.top(); pq.pop();

			if (dist[x][y] < cost) continue;

			for (int dir = 0; dir < 4; dir++)
			{
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
				if (dist[nx][ny] > cost + board[nx][ny])
				{
					dist[nx][ny] = cost + board[nx][ny];
					pq.push({ dist[nx][ny],nx,ny });
				}
			}
		}
		cout << "Problem " << t << ": "<< dist[n-1][n-1] << "\n";
	}

	return 0;
}

#include<iostream>
#include<queue>
using namespace std;

int board[102];
int dist[102];
int n, m;
queue<int> q;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		board[x] = y;
	}
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		board[u] = v;
	}

	q.push(1);

	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		
		if (cur == 100)
			break;

		for (int dir = 1; dir <= 6; dir++)
		{
			int nx = cur + dir;
			if (nx > 100) continue;
			if (board[nx]) nx = board[nx];
			if (dist[nx]) continue;
			dist[nx] = dist[cur] + 1;
			q.push(nx);
		}
	}

	cout << dist[100];

	return 0;
}

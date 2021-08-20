#include<iostream>
#include<queue>
#include<utility>
#include<algorithm>
#define X first
#define Y second
using namespace std;

int grid[101][101];
int visit[101][101];
int n, m;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
queue<pair<int, int>> q;
vector<int> v;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int k;
	int count = 0;
	cin >> m >> n >> k;

	while (k--)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = x1; i < x2; i++)
		{
			for (int j = y1; j < y2; j++)
			{
				grid[i][j] = 1;
				visit[i][j] = -1;
			}
		}
	}
	
	for(int i=0;i<n;i++)
		for (int j = 0; j < m; j++)
		{
			int area = 0;
			if (visit[i][j] == 0)
			{
				visit[i][j] = 1;
				q.push({ i,j });
				count++;
				area = 1;
			}
			
			while (!q.empty())
			{
				pair<int, int> cur = q.front(); q.pop();
				for (int dir = 0; dir < 4; dir++)
				{
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (grid[nx][ny] || visit[nx][ny] != 0) continue;
					visit[nx][ny] = 1;
					area++;
					q.push({ nx,ny });
				}
			}
			if(area>0)
				v.push_back(area);
		}

	cout << count << "\n";
	sort(v.begin(), v.end());
	for (int e : v)
		cout << e << " ";

	return 0;
}

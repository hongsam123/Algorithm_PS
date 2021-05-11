#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int n, m;
vector<int> v[10002];
bool visited[10002];
queue<int> q;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	int cnt = 0;

	for (int i = 1; i <= n; i++)
	{
		if (visited[i]) continue;

		q.push(i);
		visited[i] = 1;
		while (!q.empty())
		{
			int cur = q.front(); q.pop();
			if (!v[cur].empty())
			{
				for (int j = 0; j < v[cur].size(); j++)
				{
					int x = v[cur][j];
					if (visited[x]) continue;
					visited[x] = 1;
					q.push(x);
				}
			}
		}
		cnt++;
	}
	cout << cnt;

	return 0;
}

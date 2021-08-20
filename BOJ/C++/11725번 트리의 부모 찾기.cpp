#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n;
vector<int> adj[100002];
int p[100002];
queue<int> q;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n-1; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	q.push(1);

	while (!q.empty())
	{
		int cur = q.front(); q.pop();

		for (int nxt : adj[cur])
		{
			if (p[cur] == nxt) continue;
			q.push(nxt);
			p[nxt] = cur;
		}
	}

	for (int i = 2; i <= n; i++)
	{
		cout << p[i] << "\n";
	}

	return 0;
}

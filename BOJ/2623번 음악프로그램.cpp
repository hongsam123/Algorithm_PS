#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n, m;	//가수의 수, 보조 pd의 수
vector<int> adj[1002];
int indeg[1002];
queue<int> q;
vector<int> result;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	while (m--)
	{
		int x;
		cin >> x;
		vector<int> tmp;
		for (int i = 0; i < x; i++)
		{
			int singer;
			cin >> singer;
			tmp.push_back(singer);
		}

		for (int i = 0; i < x - 1; i++)
		{
			int u = tmp[i];
			int v = tmp[i + 1];
			bool isin = false;
			for (int j = 0; j < adj[u].size(); j++)
			{
				if (adj[u][j] == v)
				{
					isin = true;
					break;
				}
			}
			if (isin) continue;
			adj[u].push_back(v);
			indeg[v]++;
		}
	}

	for (int i = 1; i <= n; i++)
		if (indeg[i] == 0) q.push(i);

	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		result.push_back(cur);

		for (auto nxt : adj[cur])
		{
			indeg[nxt]--;
			if (indeg[nxt] == 0)
				q.push(nxt);
		}
	}

	if (result.size() != n)
		cout << 0;
	else
	{
		for (auto e : result)
			cout << e << "\n";
	}

	return 0;
}

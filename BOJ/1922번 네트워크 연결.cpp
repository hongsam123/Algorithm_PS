#include<iostream>
#include<tuple>
#include<algorithm>
using namespace std;

int n, m;
int p[1002];
tuple<int, int, int> adj[100002];

int find(int a)
{
	if (p[a]== a)
		return a;
	else return p[a] = find(p[a]);
}

bool if_diff(int a, int b)
{
	int pa = find(a);
	int pb = find(b);
	if (pa == pb) return false;
	p[pa] = pb;
	return true;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		p[i] = i;

	for (int i = 0; i < m; i++)
	{
		int u, v, c;
		cin >> u >> v >> c;
		adj[i] = { c,u,v };
	}

	sort(adj, adj + m);

	int cnt = 0;
	int ans = 0;

	for(int i=0;i<m;i++)
	{
		int u, v, cost;
		tie(cost, u, v) = adj[i];
		if (!if_diff(u, v)) continue;

		ans += cost;
		cnt++;

		if (cnt == n - 1) break;
	}

	cout << ans;

	return 0;
}

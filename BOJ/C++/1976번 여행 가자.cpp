#include<iostream>
#include<vector>
using namespace std;

int n, m;
int parent[202];
int adj[202][202];
vector<int> v;

void init()
{
	for (int i = 0; i <= n; i++)
		parent[i] = i;
}

int find(int a)
{
	if (parent[a] == a) return a;
	return parent[a] = find(parent[a]);
}

void Union(int a, int b)
{
	int pa = find(a);
	int pb = find(b);

	parent[pa] = pb;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> adj[i][j];

	init();

	for(int i=1;i<=n;i++)
		for (int j = i; j <= n; j++)
		{
			if (adj[i][j])
			{
				Union(i, j);
			}
		}

	for (int i = 0; i < m; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}

	for (int i = 0; i < v.size() - 1; i++)
	{
		int u = v[i];
		int w = v[i + 1];
		if (find(u) != find(w))
		{
			cout << "NO";
			return 0;
		}
	}
	
	cout << "YES";

	return 0;
}

#include<iostream>
using namespace std;

int n, m;
int parent[1000004];

void init()
{
	for (int i = 0; i <= n; i++)
		parent[i] = i;

	return;
}

int FIND(int u)
{
	if (parent[u] == u)
		return u;
	else
		return parent[u] = FIND(parent[u]);
		//return FIND(parent[u]); 는 시간초과 
}

void UNION(int a, int b)
{
	int aroot = FIND(a);
	int broot = FIND(b);
	if (aroot == broot) return;
	parent[aroot] = broot;
	return;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	init();

	for (int i = 0; i < m; i++)
	{
		int op, a, b;
		cin >> op >> a >> b;

		if (op == 0)
		{
			UNION(a,b);
		}
		else
		{
			if (FIND(a) == FIND(b))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}

	return 0;
}

#include<iostream>
#include<tuple>
#include<algorithm>
using namespace std;

int v, e;
int p[100002];
tuple<int, int, int> edge[1000002];
int ans;
int max_cost;

void init()
{
	for (int i = 1; i <= v; i++)
		p[i] = i;
}

int find(int a)
{
	if (p[a] == a) return a;
	return p[a] = find(p[a]);
}

bool is_diff_group(int a, int b)
{
	int pa = find(a);
	int pb = find(b);
	if (pa == pb) return false;

	p[pa] = pb;
	return true;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> v >> e;

	for (int i = 0; i < e; i++)
	{
		int u, v, cost;
		cin >> u >> v >> cost;
		edge[i] = { cost,u,v };
	}
	init();
	sort(edge, edge + e);
	int cnt = 0;

	for(int i=0;i<e;i++)
	{
		int cost, v1, v2;
		tie(cost, v1, v2) = edge[i];
		if (!is_diff_group(v1, v2)) continue;
		cnt++;
		ans += cost;
		max_cost = max(max_cost, cost);

		if (cnt == v - 1) break;
	}

	cout << ans-max_cost;
	return 0;
}

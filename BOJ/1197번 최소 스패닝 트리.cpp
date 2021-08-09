#include<iostream>
#include<tuple>
#include<algorithm>
using namespace std;

int v, e;
tuple<int, int, int> edge[100003];
int p[10003];

int find(int a)
{
	if(p[a]==a) return a;
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

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> v >> e;

	for (int i = 1; i <= v; i++)
		p[i] = i;

	for (int i = 0; i < e; i++)
	{
		int cost, u, v;
		cin >> u >> v >> cost;
		edge[i] = { cost,u,v };
	}

	sort(edge, edge + e);

	int cnt = 0;
	int ans = 0;
	
	for (int i = 0; i < e; i++)
	{
		int cost, a, b;
		tie(cost, a, b) = edge[i];

		if (!is_diff_group(a, b)) continue;	//같은 그룹이면 continue;

		ans += cost;
		cnt++;

		if (cnt == v - 1) break;
	}

	cout << ans;

	return 0;
}
//prim 알고리즘 
//#include<iostream>
//#include<queue>
//#include<vector>
//#include<utility>
//#include<tuple>
//#define ti3 tuple<int,int,int>
//using namespace std;
//
//int v, e;
//vector<pair<int, int>> adj[100005];		//cost, idx
//priority_queue<ti3, vector<ti3>, greater<ti3>> pq;
//bool check[10005];
//int cnt;
//int ans;
//
//int main()
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> v >> e;
//
//	for (int i = 0; i < e; i++)
//	{
//		int a, b, c;
//		cin >> a >> b >> c;
//		adj[a].push_back({ c,b });
//		adj[b].push_back({ c,a });
//	}
//
//	for (auto nxt : adj[1])
//	{
//		pq.push({ nxt.first, 1, nxt.second });
//	}
//	check[1] = 1;
//
//	while (1)
//	{
//		int cost, a, b;
//		tie(cost, a, b) = pq.top(); pq.pop();
//		if (check[b]) continue;
//
//		check[b] = 1;
//		cnt++;
//		ans += cost;
//
//		if (cnt == v - 1) break;
//
//		for (auto nxt : adj[b])
//		{
//			if (!check[nxt.second])
//				pq.push({ nxt.first,b,nxt.second });
//		}
//	}
//
//	cout << ans;
//
//	return 0;
//}


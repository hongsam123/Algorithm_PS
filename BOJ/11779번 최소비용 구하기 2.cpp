#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int n,m, st, t;
const int INF = 1e9 + 10;
vector<pair<int,int>> adj[1002];	//<cost, idx>
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int d[1002];
int pre[1002];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	
	fill(d, d + 1003, INF);

	for (int i = 0; i < m; i++)
	{
		int u, v, e;
		cin >> u >> v >> e;
		adj[u].push_back({ e,v });
	}

	cin >> st >> t;

	d[st] = 0;
	pq.push({ 0,st });
	while (!pq.empty())
	{
		auto cur = pq.top(); pq.pop();
		int dist = cur.first, idx = cur.second;
		if (dist != d[idx]) continue;
		for (auto nxt : adj[idx])
		{
			int cost = nxt.first, nidx = nxt.second;
			if (d[nidx] > cost + dist)
			{
				d[nidx] = cost + dist;
				pq.push({ d[nidx],nidx });
				pre[nidx] = idx;
			}
		}
	}

	vector<int> v;
	int cur = t;
	while (cur != st)
	{
		v.push_back(cur);
		cur = pre[cur];
	}
	v.push_back(cur);

	cout << d[t] << "\n";
	cout << v.size() << "\n";
	for (int i = v.size() - 1; i >= 0; i--)
		cout << v[i] << " ";
	//reverse(v.begin(),v.end());후 출력도 동일

	return 0;
}

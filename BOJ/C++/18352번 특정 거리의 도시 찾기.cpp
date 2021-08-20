#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

vector<int> board[300002];
int dist[300002];
int n, m, k, x;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k >> x;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		board[a].push_back(b);
	}

	fill(dist, dist + n + 1, -1);
	queue<int> q;
	q.push(x);
	dist[x] = 0;

	while (!q.empty())
	{
		int cur = q.front(); q.pop();

		for (int i = 0; i < board[cur].size(); i++)
		{
			int y = board[cur][i];
			if (dist[y] < 0)	//아직 가지 않은 노드
			{					//현재가 최단거리이므로 갔던 노드의 거리까지 계산할 필요는 없다
				dist[y] = dist[cur] + 1;
				q.push(y);
			}
		}
	}

	vector<int> v;
	for (int i = 1; i <= n; i++)
	{
		if (dist[i] == k)
			v.push_back(i);
	}

	if (v.empty())
		cout << -1;
	else
		for (int e : v)
			cout << e << "\n";

	return 0;
}

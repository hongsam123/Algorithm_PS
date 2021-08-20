#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int dist[100002];
queue<int> q;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	//¹Ý·Ê 
	if (n == k)
	{
		cout << 0;
		return 0;
	}

	fill(dist, dist + 100002, -1);

	dist[n] = 0;
	q.push(n);

	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		for (int n : {cur + 1, cur - 1, cur * 2})
		{
			if (n == k)
			{
				cout << dist[cur] + 1;
				return 0;
			}
			if (n < 0 || n>100000) continue;
			if (dist[n] >= 0) continue;
			dist[n] = dist[cur] + 1;
			q.push(n);
		}
	}
	return 0;
}

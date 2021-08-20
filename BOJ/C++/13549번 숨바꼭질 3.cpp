#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int n, k;
queue<int> q;
int dist[100002];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	fill(dist, dist + 100001, -1);

	q.push(n);
	dist[n] = 0;

	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		if (cur == k)	//동생을 찾으면 종료
		{
			cout << dist[cur];
			return 0;
		}

		//순간이동
		int teleport = cur * 2;
		if (teleport <= 100000 && dist[teleport] == -1)
		{
			dist[teleport] = dist[cur];
			q.push(teleport);
		}

		//왼쪽으로 걷기
		int dleft = cur - 1;
		if (dleft >= 0 && dist[dleft] == -1)	//새로운 위치가 범위를 벗어나지 않고 방문하지 않은곳이라면
		{
			dist[dleft] = dist[cur] + 1;	//시간을 갱신하고
			q.push(dleft);					//큐에 넣기
		}

		//오른쪽으로 걷기
		int dright = cur + 1;
		if (dright <= 100000 && dist[dright] == -1)
		{
			dist[dright] = dist[cur] + 1;
			q.push(dright);
		}
	}

	return 0;
}

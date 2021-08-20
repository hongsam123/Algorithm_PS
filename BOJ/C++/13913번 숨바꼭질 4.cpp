#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int n, k;
queue<int> q;
int dist[100002];
int pre[100002];	//경로 복원용 배열
//처음에 큐에 이전 경로를 모두 포함한 벡터를 넣고 bfs를 진행해
//cur.back()으로 경로 중 마지막으로 간 장소가 k인지 확인했는데
//그렇게하면 100000에서 0으로 가는 경우 큐에 들어가는 벡터에 100000,99999,99998...이 계속 들어가 시간초과 
vector<int> v;

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
			cout << dist[cur] << "\n";

			//시작 지점까지 거꾸로 경로 복원
			for (int i = k; i != n; i = pre[i])
				v.push_back(i);
			v.push_back(n);

			//거꾸로 출력
			for (int i = v.size() - 1; i >= 0; i--)
				cout << v[i] << " ";
			return 0;
		}

		//왼쪽으로 걷기
		int dleft = cur - 1;
		if (dleft >= 0 && dist[dleft] == -1)
		{
			dist[dleft] = dist[cur] + 1;
			pre[dleft] = cur;	//새로운 위치에 갔을 때 경로 복원용 배열에 이전 위치를 저장
			q.push(dleft);
		}

		//오른쪽으로 걷기
		int dright = cur + 1;
		if (dright <= 100000 && dist[dright] == -1)
		{
			dist[dright] = dist[cur] + 1;
			pre[dright] = cur;
			q.push(dright);
		}

		//순간이동
		int teleport = cur * 2;
		if (teleport <= 100000 && dist[teleport] == -1)
		{
			dist[teleport] = dist[cur] + 1;
			pre[teleport] = cur;
			q.push(teleport);
		}
	}

	return 0;
}

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int n, m;
int inDegree[32002];
int answer[32002];
vector<int> edge[32002];
int cnt;
queue<int> q;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	//1.진입차수(inDegree) input
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;

		//a<b
		edge[a].push_back(b);
		inDegree[b]++;
	}

	//2. 진입차수 0인애들 queue에 넣기
	for (int i = 1; i <= n; i++)
		if (inDegree[i] == 0) q.push(i);

	//3. queue에서 1개씩 뽑으면서 연결된 간선 끊기
	//string str;
	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		cout << cur<<" ";

		//연결된 간선
		for (auto e : edge[cur])
		{
			//1)진입차수 inDegree-1
			inDegree[e]--;
			if (inDegree[e] == 0)
				q.push(e);
		}
	}

	return 0;
}

//bfs로 푼 처음 풀이 ==> 무조건  시간초과
 
//#include<iostream>
//#include<queue>
//#include<utility>
//using namespace std;
//
//queue<pair<int, int>> q;
//pair<int, int> board[100002];
//
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int n, m;
//	cin >> n>> m;
//
//	int count[10002];
//	fill(count, count + n+1, 0);
//
//	for (int i = 0; i < m; i++)
//	{
//		int a, b;
//		cin >> a >> b;
//		board[i] = { a,b };
//	}
//	
//	for (int i = 1; i <= n; i++)
//	{
//		int visit[10002];
//		fill(visit, visit + n+1, 0);
//		for (int j = 0; j < m; j++)
//		{
//			//if (board[j].second == i && visit[i]!=1)
//			if (board[j].second == i)
//			{
//
//				q.push({ board[j].first,board[j].second });
//				visit[i] = 1;
//			}
//		}
//
//		while (!q.empty())
//		{
//			pair<int, int> cur = q.front(); q.pop();
//			count[i]++;
//			for (int j = 0; j < m; j++)
//			{
//				if (cur.first != board[j].second) continue;
//				if (visit[board[j].first] == 1) continue;
//				visit[board[j].first] = 1;
//				q.push({ board[j] });
//			}
//		}
//	}
//
//	int maxCount = 0;
//	
//	for (int i = 1; i <= n; i++)
//	{
//		maxCount = max(maxCount, count[i]);
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		if (count[i] == maxCount)
//			cout << i << " ";
//	}
//
//	cout << "\n";
//	for (int i = 1; i <= n; i++)
//		cout << count[i] << " ";
//
//	return 0;
//}

//dfs로 통과한 풀이 
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
vector<int> v[10002];	//각 번호의 컴퓨터를 믿고 있는 다른 컴퓨터들을 벡터에 저장
bool visited[10002];
int cnt[10002];
queue<int> q;
int count_num;
int max_count;

void dfs()
{
	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		count_num++;
		if (!v[cur].empty())
		{
			for (int i = 0; i < v[cur].size(); i++)
			{
				int nx = v[cur][i];
				if (visited[nx]) continue;
				visited[nx] = 1;
				q.push(nx);
				dfs();
			}
		}
	}
	return;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;	//a는 b를 신뢰한다
		v[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)
	{
		count_num = 0;
		fill(visited, visited + n + 1, 0);
		q.push(i);
		visited[i] = 1;
		dfs();
		cnt[i] = count_num;
		max_count = max(max_count, count_num);
	}

	vector<int> ans;
	for (int i = 1; i <= n; i++)
	{
		if (cnt[i] == max_count)
			ans.push_back(i);
	}

	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";

	return 0;
}

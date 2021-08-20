#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n, m;
vector<int> board[102];
queue<int> q;
bool visit[102];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		board[a].push_back(b);
		board[b].push_back(a);
	}

	q.push(1);
	visit[1] = 1;
	int cnt = 0;

	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		if (!board[cur].empty())
		{
			for (int i = 0; i < board[cur].size(); i++)
			{
				int x = board[cur][i];
				if (visit[x]) continue;
				visit[x] = 1;
				q.push(x);
				cnt++;
			}
		}
	}

	cout << cnt;


	return 0;
}

#include<iostream>
#include<queue>
#include<tuple>
using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n;
int board[52][52];
bool visited[52][52];
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
int ans;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++)
			board[i][j] = str[j] - '0';
	}

	pq.push({ 0,0,0 });
	visited[0][0] = 1;

	while (!pq.empty())
	{
		auto cur = pq.top(); pq.pop();
		if (get<1>(cur) == n - 1 && get<2>(cur) == n - 1)
		{
			ans = get<0>(cur);
			break;
		}

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = get<1>(cur) + dx[dir];
			int ny = get<2>(cur) + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (visited[nx][ny] == 1) continue;
			visited[nx][ny] = 1;
			if (board[nx][ny] == 0)
				pq.push({ get<0>(cur) + 1,nx,ny });
			else
				pq.push({ get<0>(cur) ,nx,ny });
		}
	}

	cout << ans;

	return 0;
}

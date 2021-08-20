#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int n, m;
vector<int> party[52];	//파티 당 참가한 사람들 
vector<int> participate[52];	//사람들 마다 참가한 파티
bool canLie[52];
bool visited[52];
queue<int> q;
int ans;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	fill(canLie, canLie + m + 1, 1);

	int num;
	cin >> num;
	if (num != 0)
		while (num--)
		{
			int x;
			cin >> x;
			visited[x] = 1;
			q.push(x);
		}

	for (int i = 1; i <= m; i++)
	{
		int pnum;
		cin >> pnum;

		for (int j = 0; j < pnum; j++)
		{
			int px;
			cin >> px;
			party[i].push_back(px);

			participate[px].push_back(i);
		}
	}


	while (!q.empty())
	{
		auto cur = q.front(); q.pop();

		if (participate[cur].empty()) continue;
		for (int i = 0; i < participate[cur].size(); i++)
		{
			int party_num = participate[cur][i];
			if (!canLie[party_num]) continue;
			canLie[party_num] = false;
			for (int j = 0; j < party[party_num].size(); j++)
			{
				int nx = party[party_num][j];
				if (visited[nx]) continue;
				visited[nx] = 1;
				q.push(nx);
			}
		}
	}

	for (int i = 1; i <= m; i++)
		if (canLie[i])
			ans++;

	cout << ans;

	return 0;
}

#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#define X first
#define Y second
using namespace std;
int visited[100001];
int board[100002];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int test;
	cin >> test;

	while (test--)
	{
		int n;
		int count = 0;
		cin >> n;
		queue<pair<int, int>> q;
		fill(visited, visited + n + 1, 0);
		fill(board, board + n + 1, 0);
		
		for (int i = 1; i <= n; i++)
		{
			cin >> board[i];
		}
		
		for (int i = 1; i <= n; i++)
		{
			if (visited[i] == 1) continue;
			q.push({ i ,board[i] });
			vector<int> vtmp;
			while (!q.empty())
			{
				pair<int, int> cur = q.front(); q.pop();
				if (visited[cur.X] != 1)
				{
					visited[cur.X] = 1;
					if (cur.X == cur.Y)
					{
						count++;
						while (!q.empty()) q.pop();
						break;
					}
					vtmp.push_back(cur.X);
					if (visited[cur.Y] != 1)
					{
						q.push({ cur.Y,board[cur.Y] });
					}
					else
					{
						for (int j = 0; j < vtmp.size(); j++)
						{
							if (vtmp[j] == cur.Y)
							{
								count += vtmp.size() - j;
								while (!q.empty()) q.pop();
								break;
							}
						}
					}
				}
			}
		}
		cout << n - count << "\n";
	}
	return 0;
}

#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#define X first
#define Y second
using namespace std;

int board[26][26];
int visited[26][26];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++)
		{
			board[i][j] = str[j] - '0';
		}
	}

	vector<int> v;
	queue<pair<int, int>> s;
	int num = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int cnt = 0;
			if (board[i][j] == 1 && visited[i][j]==0)
			{
				s.push({ i,j });
				num++;
				visited[i][j] == num;
			}

			while (!s.empty())
			{
				cnt++;
				pair<int, int> cur = s.front(); s.pop();
				for (int dir = 0; dir < 4; dir++)
				{
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (board[nx][ny] == 0 || visited[nx][ny] != 0) continue;
					visited[nx][ny] = num;
					s.push({ nx,ny });
				}
			}
			if(cnt>0)
				v.push_back(cnt);
		}
	}

	cout << num << "\n";

	sort(v.begin(), v.end());
	for (int e : v)
	{
		if (e > 1) cout << e - 1 << "\n";
		else cout << e << "\n";
	}

	return 0;
}

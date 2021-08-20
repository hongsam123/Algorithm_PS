#include<iostream>
#include<queue>
#include<algorithm>
#include<utility>
#define X first
#define Y second
using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
char board[14][8];
queue<pair<int,int>> q;
int ans;
bool visited[14][8];
vector<pair<int, int>> puyo;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 12; i++)
	{
		string str;
		cin >> str;

		for (int j = 0; j < 6; j++)
			board[i][j] = str[j];
	}

	while (1)
	{
		bool notChange = true;
		for (int i = 0; i < 12; i++)
			fill(visited[i], visited[i] + 7, 0);

		//¿¬¼â

		//¿¬¼âµÉ »Ñ¿äµé puyo¿¡ ´ã±â
		for (int i = 11; i >= 0; i--)
		{
			for (int j = 0; j < 6; j++)
			{
				if (board[i][j] == '.' || visited[i][j]) continue;

				visited[i][j] = 1;
				q.push({ i,j });
				puyo.push_back({ i,j });

				int cnt = 1;

				while (!q.empty())
				{
					auto cur = q.front(); q.pop();
					for (int dir = 0; dir < 4; dir++)
					{
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6) continue;
						if (board[nx][ny] != board[cur.X][cur.Y]) continue;
						if (visited[nx][ny]) continue;
						visited[nx][ny] = 1;
						cnt++;
						puyo.push_back({ nx,ny });
						q.push({ nx,ny });
					}
				}

				if (cnt < 4)
				{
					for (int i = 0; i < cnt; i++)
						puyo.pop_back();
				}
			}
		}

		//¿¬¼âµÉ »Ñ¿äµéÀÌ ÀÖ´Ù¸é '.'À¸·Î ¹Ù²Ù°í puyo º¤ÅÍ ºñ¿ì±â
		if (!puyo.empty())
		{
			ans++;
			notChange = false;
			for (int i = 0; i < puyo.size(); i++)
			{
				auto cur = puyo[i];
				board[cur.X][cur.Y] = '.';
			}
		}

		puyo.clear();

		//for (int i = 0; i < 12; i++)
		//{
		//	for (int j = 0; j < 6; j++)
		//	{
		//		cout << board[i][j] << " ";
		//	}
		//	cout << "\n";
		//}

		if (notChange) break;
		
		//¶³¾îÁö±â
		for (int i = 0; i < 6; i++)
		{
			vector<char> v;
			for (int j = 11; j >= 0; j--)
			{
				if (board[j][i] != '.')
					v.push_back(board[j][i]);
			}

			if (v.empty())
			{
				for (int j = 11; j >= 0; j--)
					board[j][i] = '.';
			}
			else
			{
				int num = 0;
				for (int j = 11; j >= 0; j--)
				{
					if (num == v.size())
						board[j][i] = '.';
					else
					{
						board[j][i] = v[num];
						num++;
					}
				}
			}
			v.clear();
		}
	}

	cout << ans;

	return 0;
}

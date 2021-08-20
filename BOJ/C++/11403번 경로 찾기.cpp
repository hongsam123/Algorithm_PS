#include<iostream>
#include<algorithm>
using namespace std;

int n;
int board[102][102];
const int INF = 1e9+10;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int x;
			cin >> x;
			if (x == 0)
				board[i][j] = INF;
			else
				board[i][j] = x;
		}
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				board[i][j] = min(board[i][j], board[i][k] + board[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (board[i][j] == INF)
				cout << 0 << " ";
			else
				cout << 1 << " ";
		}
		cout << "\n";
	}

	return 0;
}

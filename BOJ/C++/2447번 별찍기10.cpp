#include<iostream>
#include<algorithm>
using namespace std;
char board[6562][6562];

void func(int num, int r, int c)
{
	if (num == 3)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (i == 1 && j == 1) continue;
				board[r + i][c + j] = '*';
			}
		}
		return;
	}
	int cnt = 0;
	for (int i = r; i < r+num; i = i + num/3)
	{
		for (int j = c; j < c+num; j = j + num / 3)
		{
			cnt++;
			if (cnt == 5) continue;
			func(num / 3, i, j);
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		fill(board[i], board[i] + n, ' ');

	func(n, 0, 0);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << board[i][j];
		cout << "\n";
	}

	return 0;
}



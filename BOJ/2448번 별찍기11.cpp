#include<iostream>
using namespace std;

char board[3073][6145];
char DB[][7] =
{ "  *   ",
  " * *  ",
  "***** " };

void func(int num, int r, int c)
{
	if (num == 3)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				board[r + i][c + j] = DB[i][j];
			}
		}
		return;
	}

	func(num / 2, r, c + num / 2);
	func(num / 2, r + num / 2, c);
	func(num / 2, r + num / 2, c + num);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		fill(board[i], board[i] + 2*n, ' ');

	func(n,0,0);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 2 * n; j++)
			cout << board[i][j];
		cout << "\n";
	}
	return 0;
}

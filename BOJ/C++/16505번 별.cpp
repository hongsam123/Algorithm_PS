#include<iostream>
#include<algorithm>
using namespace std;
char board[1025][1025];

void func(int num,int r, int c)
{
	if (num == 1)
	{
		board[r][c] = '*';
		return;
	}

	func(num / 2, r, c);
	func(num / 2, r, c + num / 2);
	func(num / 2, r + num / 2, c);

}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < (1 << n); i++)
	{
		fill(board[i], board[i] + (1 << n), ' ');
	}

	func(1<<n,0,0);

	for (int i = 0; i < (1 << n); i++)
	{
		for (int j = 0; j < (1 << n)-i ; j++)
		{
			cout << board[i][j];
		}
		cout << "\n";
	}
	return 0;
}

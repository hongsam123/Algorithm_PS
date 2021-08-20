#include<iostream>
using namespace std;
int board[65][65];

void func(int num, int r, int c)
{
	if (num == 1)
	{
		if (board[r][c] == 1)
			cout << 1;
		else cout << 0;
		return;
	}

	bool posi = true;
	int tmp = board[r][c];
	for (int i = r; i < r + num; i++)
	{
		for (int j = c; j < c + num; j++)
		{
			if (tmp != board[i][j])
			{
				posi = false;
				cout << "(";
				func(num / 2, r, c);
				func(num / 2, r, c + (num / 2));
				func(num / 2, r + (num / 2), c);
				func(num / 2, r + (num / 2), c + (num / 2));
				cout << ")";
				break;
			}
			tmp = board[i][j];
		}
		if (posi == false)
			break;
	}
	if (posi)
	{
		if (tmp) cout << 1;
		else cout << 0;

		return;
	}

	return;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	string str;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		for (int j = 0; j < str.size(); j++)
			board[i][j] = str[j]-'0';
	}

	func(n, 0, 0);
	
	return 0;
}

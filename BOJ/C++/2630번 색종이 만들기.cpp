#include<iostream>
using namespace std;
int board[130][130];
int white;
int blue;

void func(int x, int y, int num)
{
	int tmp = 0;
	for(int i=x;i<x+num;i++)
		for (int j = y; j < y + num; j++)
		{
			if (board[i][j] == 1)
				tmp++;
		}
	if (tmp == 0) white++;
	else if (tmp == num * num) blue++;
	else
	{
		func(x, y, num / 2);
		func(x, y + num / 2, num / 2);
		func(x + num / 2, y, num / 2);
		func(x + num / 2, y + num / 2, num / 2);
	}
	return;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];

	func(0,0,n);
	cout << white << "\n" << blue;

	return 0;
} 

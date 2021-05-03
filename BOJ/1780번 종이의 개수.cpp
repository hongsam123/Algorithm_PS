#include<iostream>
using namespace std;
int board[2188][2188];
int count[3];

void func(int num,int r,int c)
{
	if (num == 1)
	{
		count[board[r][c] + 1]++;
		return;
	}
	bool posi = true;
	int tmp = board[r][c];
	for (int i = r; i < r+num; i++)
	{
		for (int j = c ; j < c + num; j++)
		{
			if (tmp != board[i][j])
			{
				posi = false;
				for (int a = r; a < r+num; a += num/3)
				{
					for (int b = c; b < c+num; b += num/3)
					{
			 			func(num / 3, a, b);
					}
				}
				break;
			}
			tmp = board[i][j];
		}
		if(posi==false) break;
	}
	
	if (posi)
	{
		count[(board[r][c] + 1)]++;
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

	for(int i=0;i<n;i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];

	func(n,0,0);
	
	for (int i = 0; i < 3; i++)
		cout << count[i] << "\n";

	return 0;
}

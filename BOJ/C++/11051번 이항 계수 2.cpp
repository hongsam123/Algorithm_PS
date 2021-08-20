#include<iostream>
using namespace std;

int  n, k;
int comb[1002][1002];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	
	for (int i = 1; i <= n; i++)
	{
		comb[i][0] = comb[i][i] = 1;
		for (int j = 1; j < i; j++)
		{
			comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % 10007;
		}
	}

	cout << comb[n][k];

	return 0;
}

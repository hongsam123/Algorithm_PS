#include<iostream>
using namespace std;

long long dp[1000002];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int test;
	cin >> test;

	fill(dp, dp + 1000002, -1);
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	while (test--)
	{
		int n;
		cin >> n;

		if (dp[n] != -1)
		{
			cout << dp[n] << "\n";
		}
		else
		{
			for (int i = 4; i <= n; i++)
				if (dp[i] == -1)
					dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % 1000000009;

			cout << dp[n] << "\n";
		}
	}

	return 0;
}

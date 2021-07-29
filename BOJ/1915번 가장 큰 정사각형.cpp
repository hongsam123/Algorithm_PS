#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
int arr[1002][1002];
int dp[1002][1002];
int ans;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < m; j++)
			arr[i][j] = str[j] - '0';
	}

	for(int i=0;i<n;i++)
		for (int j = 0; j < m; j++)
		{
			if ((i == 0 || j == 0) && arr[i][j])
				dp[i][j] = 1;
			else if (arr[i][j])
				dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));

			ans = max(ans, dp[i][j]);
		}

	cout << ans*ans;

	return 0;
}

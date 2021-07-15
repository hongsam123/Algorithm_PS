#include<iostream>
#include<algorithm>
using namespace std;

int n;
int dp[50002];	//dp[i] : 합이 i과 같게되는 제곱수들의 최소 갯수

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i * i <= n; i++)
		dp[i * i] = 1;

	for (int i = 1; i <= n; i++)
	{
		if (dp[i] > 0) continue;
		for (int j = 1; j * j <= i; j++) {
			if (dp[i] == 0) dp[i] = 1 + dp[i - j * j];
			else dp[i] = min(dp[i], 1 + dp[i - j * j]);
		}
	}
	
	cout << dp[n];

	return 0;
}

#include<iostream>
using namespace std;

int n;
int dp[1000002];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int num = abs(n);

	dp[1] = 1;

	for (int i = 2; i <= num; i++)
		dp[i] = (dp[i - 1] + dp[i - 2])%1000000000;

	if (n == 0)
		cout << 0 << "\n";
	else if (n < 0 && num % 2 == 0)
		cout << -1 << "\n";
	else
		cout << 1 << "\n";

	cout << dp[num];

	return 0;
}

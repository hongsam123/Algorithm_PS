//1. 테이블 정의하기
//dp[i][0] = i번째 자리에 0이 올때 이친수의 개수
//dp[i][1] = i번째 자리에 1이 올때 이친수의 개수
//2. 점화식
//dp[i][0] = dp[i - 1][0] + dp[i - 1][1]
//dp[i][1] = dp[i - 1][0]
//3. 초기값
//dp[1][0] = 0
//dp[1][1] = 1
//
#include<iostream>
using namespace std;

int n;
long long dp[92][2];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	dp[1][0] = 0;
	dp[1][1] = 1;

	for (int i = 2; i <= n; i++)
	{
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
	}

	cout << dp[n][0] + dp[n][1];

	return 0;
}

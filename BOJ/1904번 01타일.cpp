//1. 테이블 정의
//dp[n] = 길이가 n인 모든 2진 수열의 개수
//2. 점화식 찾기
//dp[i] = dp[i - 1] + dp[i - 2]
//3. 초기값 정의
//dp[1] = 1;
//dp[2] = 2; //00, 11
#include<iostream>
using namespace std;

int n;
int dp[1000002];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= n; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
	}

	cout << dp[n];

	return 0;
}

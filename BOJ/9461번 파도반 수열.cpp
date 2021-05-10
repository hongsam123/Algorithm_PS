//1.테의블 정의
//dp[n] = 정삼각형을 추가하며 나선에서 가장 긴 변의 길이를 k라고 할 때 n번째 삼각형의 길이
//2.점화식 찾기
//dp[i] = dp[i - 2] + dp[i - 3]
//3.초기값 정의
//dp[1] = 1
//dp[2] = 1
//dp[3] = 1
#include<iostream>
#include<algorithm>
using namespace std;

long long dp[103];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int test;
	cin >> test;

	while (test--)
	{
		int n;
		cin >> n;

		fill(dp, dp + 103, 0);

		dp[1] = 1;
		dp[2] = 1;
		dp[3] = 1;

		for (int i = 4; i <= n; i++)
			dp[i] = dp[i - 2] + dp[i - 3];

		cout << dp[n] << "\n";
	}

	return 0;
}

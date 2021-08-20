//1. 테이블 정의
//dp[n] = 3 * n 크기의 벽을 타일로 채우는 경우의 수
//2. 점화식 찾기
//i가 홀수이면
//dp[i] = 0;
//짝수면(i > 2)
//dp[i] = dp[i - 2] * 3;
//for (int j = i - 4; j >= 0; j = j - 2)
//	dp[i] += dp[j] * 2;
//3. 초기값 정의
//dp[0] = 1;`//새로운 도형 2개를 추가하기 위한 초기값
//dp[1] = 0;
//dp[2] = 3;

#include<iostream>
using namespace std;

int n;
int dp[32];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	
	dp[0] = 1;
	dp[1] = 0;
	dp[2] = 3;

	for (int i = 3; i <= n; i++)
	{
		if (i % 2 == 1)
			dp[i] = 0;
		else
		{
			dp[i] = dp[i - 2] * 3;
			for (int j = i - 4; j >= 0; j = j - 2)
				dp[i] += dp[j] * 2;
		}
	}

	cout << dp[n];

	return 0;
}

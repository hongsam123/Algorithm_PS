//1. 테이블 정의하기
//D[i] = i를 1,2,3의 합으로 나타내는 방법의 수
//2. 점화식 찾기
//D[4] = 
//1+1+1+1, 1+2+1, 2+1+1, 3+1 => 3을 1,2,3의 합으로 나타내는 방법+1 =>D[3]
//1+1+2, 2+2 => 2를 1,2,3의 합으로 나타내는 방법+2 => D[2]
//1+3 => 1을 1,2,3의 합으로 나타내는 방법+3 => D[1]
//D[i] = D[i-1]+D[i-2]+D[i-3]
//3. 초기값 정의
//초기값이 최소 3개는 주어져야함(D[1],D[2],D[3])
#include<iostream>
using namespace std;

int dp[13];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i <= 10; i++)
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];

	int test;
	cin >> test;

	while (test--)
	{
		int n;
		cin >> n;
		
		cout << dp[n] << "\n";
	}

	return 0;
}

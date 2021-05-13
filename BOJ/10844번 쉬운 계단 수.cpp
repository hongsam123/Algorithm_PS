//1. 테이블 정의
//dp[n][m] = 길이가 n인 m으로 시작하는 계단수의 갯수
//2. 점화식 찾기
//dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1]
//j가 0이고 9일 때 예외 처리 
//3. 초기값 정의
//for (int i = 0; i <= 9; i++)
//		dp[1][i] = 1;
#include<iostream>
using namespace std;

int n;
long long dp[102][10];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i <= 9; i++)
		dp[1][i] = 1;
	
	for(int i=2;i<=n;i++)			//길이가 2부터 n인 
		for (int j = 0; j <= 9; j++)
		{
			if(j==0)
				dp[i][j] = dp[i - 1][j + 1] % 1000000000;
			else if(j==9)
				dp[i][j] = dp[i - 1][j - 1] % 1000000000;
			else
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1])%1000000000;
		}

	long long total = 0;
	for (int i = 1; i <= 9; i++)
		total = (total + dp[n][i]) % 1000000000;
	cout << total;

	return 0;
}

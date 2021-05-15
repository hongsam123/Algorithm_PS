//1. 테이블 정의
//dp[n] = n을 제곱수들의 합으로 표현할 때에 그 항의 최소 개수
//2. 점화식 찾기
//for(int j=1;j*j<=i;j++)
//	dp[i] = dp[j] + dp[i - j*j] + 1
//(모든 경우의 수 중 최소값)
//3. 초기값 설정
//dp[n] = n
#include<iostream>
#include<algorithm>
using namespace std;

int n;
long long dp[100002];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	/*dp[1] = 1;
	int j = 1;
	int num = 2;
	for (int i = 2; i <= n; i++)
	{
		if (j == i)
			dp[i] = 1;
		else
			dp[i] = dp[j] + dp[i - j];

		if ((num * num - 1) == i)
		{
			j = num * num;
			num++;
		}
	}*/

	for (int i = 1; i <= n; i++)
		dp[i] = i;

	for (int i = 2; i <= n; i++)
		for (int j = 1; j * j <= i; j++)
			dp[i] = min(dp[i], dp[i - j * j] + 1);

	cout << dp[n];

	return 0;
}

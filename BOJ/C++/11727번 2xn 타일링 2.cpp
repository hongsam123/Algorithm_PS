//1. 테이블 정의하기
//dp[i] = 2 * i크기의 직사각형을 채우는 방법의 수
//2. 점화식 찾기
//1) 맨 왼쪽 위 타일이 1 * 2 타일 일 때 남은 칸을 채우는 방법의 수 = > dp[i - 2]
//2) 맨 왼쪽 위 타일이 2 * 1 타일 일 때 남은 칸을 채우는 방법의 수 = > dp[i - 1]
//3) 맨 왼쪽 위 타일이 2 * 2 타일 일 때 남은 칸을 채우는 방법의 수 = > dp[i - 2]
//dp[i] = dp[i - 1] + 2 * (dp[i - 2])
//3. 초기값 정의하기
//dp[1] = 1
//dp[2] = 3
#include<iostream>
using namespace std;

int dp[1002];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	
	dp[1] = 1;
	dp[2] = 3;
	for (int i = 3; i <= n; i++)
	{
		dp[i] =( dp[i - 1] + 2 * (dp[i - 2]) )%10007;
		/*마지막에만 10007로 나누면 int overflow발생.
		중간중간 나누어 저장해야한다*/
	}

	cout << dp[n];

	return 0;
}


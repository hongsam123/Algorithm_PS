//1. 테이블 정의하기
//dp[n] = 현재 병사를 배치했을때 가능한 최대 병사 수
//2. 점화식 찾기
//for (int j = 0; j <= i; j++)
//	if (arr[i] > arr[j]) dp[i] = max(dp[i], dp[j] + 1)
//
//LIS(Longest Increasing Subsequence)
//하나의 수열이 주어졌을 때 값들이 증가하는 형태의 가장 긴 부분 수열을 찾는 대표적인 dp
#include<iostream>
#include<algorithm>
using namespace std;

int n;
long long dp[2002];
long long arr[2002];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long max_num = 1;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	fill(dp, dp + n + 1, 1);
	
	for (int i = n-1; i >= 1; i--)
	{
		for (int j = n; j > i; j--)
		{
			if (arr[i] > arr[j])
				dp[i] = max(dp[i], dp[j] + 1);
			max_num = max(max_num, dp[i]);
		}
	}

	cout << n - max_num;

	return 0;
}

//1. 식 세우기
//dp[i][j] = 현재 i번째 물건을 봤고 가방의 무게가 j일때 가방에 담긴 가치
//2. 초기값
//dp[1~n][0] = 0;
//3. 점화식(고려1 : 현재 물건을 담을 수 있는가, 고려2 : 해당 물건을 담을 것인가)

#include<iostream>
#include<algorithm>
using namespace std;

int value[102];
int weight[102];
int n, k;
int dp[102][100002];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	for (int i = 1; i <= n; i++)
		cin >> weight[i] >> value[i];

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if (weight[i] > j) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
		}
	}

	cout << dp[n][k];

	return 0;
}

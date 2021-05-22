//1. 테이블 정의하기(색상에 대한 정보가 추가적으로 들어가게끔 정의해야함)
//dp[i][0] = i번째 집까지 칠할 때 비용의 최소값, 단, i번째 집은 빨강
//dp[i][1] = i번째 집까지 칠할 때 비용의 최소값, 단, i번째 집은 초록
//dp[i][2] = i번째 집까지 칠할 때 비용의 최소값, 단, i번째 집은 파랑
//2. 점화식 찾기
//dp[k][0] = min(dp[k - 1][1], dp[k - 1][2]) + cost[k][0]
//dp[k][1] = min(dp[k - 1][0], dp[k - 1][2]) + cost[k][1]
//dp[k][2] = min(dp[k - 1][0], dp[k - 1][1]) + cost[k][2]
//3. 초기값 정의하기
//dp[1][0] = cost[1][0]
//dp[1][1] = cost[1][1]
//dp[1][2] = cost[1][2]
//
#include<iostream>
#include<algorithm>
using namespace std;

int dp[1002][3];
int cost[1002][3];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> cost[i][j];
		}
	}

	dp[1][0] = cost[1][0];
	dp[1][1] = cost[1][1];
	dp[1][2] = cost[1][2];

	for (int i = 2; i <= n; i++)
	{
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
	}

	int min_cost = min(dp[n][0], dp[n][1]);
	min_cost = min(min_cost, dp[n][2]);
	//min_cost = min({ dp[n][0],dp[n][1],dp[n][2] });
	//min_cost = *min_element(dp[n], dp[n] + 3);

	cout << min_cost;

	return 0;
}

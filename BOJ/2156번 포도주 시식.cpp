#include<iostream>
#include<algorithm>
using namespace std;

int n;
int arr[10002];
long long dp[10002];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	dp[0] = 0;
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	dp[3] = max(arr[1], arr[2]) + arr[3];

	for (int i = 4; i <= n; i++)
	{
		dp[i] = max(dp[i-2] , arr[i - 1] + dp[i - 3])+arr[i];	//이전것을 안 먹었을 경우, 한번 건너뛰고  이전것을 먹었을 경우 
		dp[i] = max(dp[i],arr[i-1]+dp[i-4]+arr[i]);				//두 번 건너뛰고 이전 것을 먹었을 경우 
	}

	if (n == 1)
	{
		cout << dp[n];
		return 0;
	}
	cout << max(dp[n], dp[n - 1]);	//마지막 잔을 먹었을때, 안 먹었을때 

	return 0;
}

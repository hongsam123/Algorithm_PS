#include<iostream>
#include<algorithm>
using namespace std;

int n;
int arr[1002];
int dp[1002];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	fill(dp, dp + n + 1, 1);

	int max_num = 1;

	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (arr[i] > arr[j])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	cout << *max_element(dp, dp + n + 1);

	return 0;
}

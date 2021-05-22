//1. ���̺� �����ϱ�
//dp[i][j] = { i,j }��ο� �������� �ִ� ���� ����
//2. ��ȭ��
//dp[k][1] = dp[k - 1][1] + arr[k][1]
//dp[k][j] = max(dp[k-1][j - 1], dp[k-1][j]) + arr[k][j]
//dp[k][k] = dp[k - 1][k-1] + arr[k][k]
//3. �ʱⰪ �����ϱ�
//dp[1][1] = arr[1][1]

#include<iostream>
#include<algorithm>
using namespace std;

int arr[502][502];
int dp[502][502];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
			cin >> arr[i][j];
	}

	dp[1][1] = arr[1][1];
	if (n == 1)
	{
		cout << dp[1][1];
		return 0;
	}

	dp[2][1] = dp[1][1] + arr[2][1];
	dp[2][2] = dp[1][1] + arr[2][2];
	if (n == 2)
	{
		cout << max(dp[2][1], dp[2][2]);
		return 0;
	}

	for (int i = 3; i <= n; i++)
	{
		dp[i][1] = dp[i - 1][1] + arr[i][1];
		for (int j = 2; j <= i - 1; j++)
		{
			dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + arr[i][j];
		}
		dp[i][i] = dp[i - 1][i - 1] + arr[i][i];
	}

	int max_cost = *max_element(dp[n], dp[n] + n+1);

	cout << max_cost;

	return 0;
}

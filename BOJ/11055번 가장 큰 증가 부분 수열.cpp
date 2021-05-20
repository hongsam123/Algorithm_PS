//1. ���̺� ����
//dp[n] = arr[n]�� ������ �� ���� ���� �κ� ������ ���� �ִ밪
//2. ��ȭ�� ã��
//for (int j = i - 1; j >= 0; j--)
//	if (arr[j] < arr[i]) max_dp = max(max_dp, dp[j]);
//dp[i] = max_dp + arr[i];
//3. �ʱⰪ ����
//dp[0] = 0
//dp[1] = arr[1]
#include<iostream>
#include<algorithm>
using namespace std;

int n;
int arr[1002];
int dp[1002];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	dp[1] = arr[1];

	for (int i = 2; i <= n; i++)
	{
		int max_dp = 0;
		for (int j = i - 1; j >= 0; j--)
			if (arr[j] < arr[i])
				max_dp = max(max_dp, dp[j]);

		dp[i] = max_dp + arr[i];
	}

	cout << *max_element(dp, dp + 1001);

	return 0;
}

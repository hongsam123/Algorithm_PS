//1. ���̺� ����
//dp[n] = arr[n]�� ���� �� ���� �� �����ϴ� �κ� ������ ������ �ִ밪
//2. ��ȭ�� ã��
//for (int j = i - 1; j >= 0; j--)
//	if (arr[j] > arr[i]) max_len = max(max_len, dp[j])
//dp[i] = max_len + 1
//3. �ʱⰪ ����
//dp[1] = 1
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
	{
		cin >> arr[i];
	}

	dp[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		int max_len = 0;
		for (int j = i - 1; j >= 0; j--)
			if (arr[j] > arr[i])
				max_len = max(max_len, dp[j]);

		dp[i] = max_len + 1;
	}

	cout << *max_element(dp, dp + 1001);

	return 0;
}

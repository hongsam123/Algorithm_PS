//1. ���̺� ����
//dp[n][0] = ���ӵǴ� ������ �ڽ��� ������ �� �ִ�
//dp[n][1] = �ڽź��� ������ ������ ��
//2. ��ȭ�� ã��
//dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]) + arr[i]
//dp[i][1] = arr[i]
//3. �ʱⰪ ����
//dp[1][0] = arr[i]
//dp[1][1] = arr[i]

#include<iostream>
#include<algorithm>
using namespace std;

int arr[100002];
int dp[100002][2];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	dp[1][0] = arr[1];
	dp[1][1] = arr[1];

	int max_num = arr[1];

	for (int i = 2; i <= n; i++)
	{
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]) + arr[i];
		max_num = max(max_num, dp[i][0]);
		dp[i][1] = arr[i];
		max_num = max(max_num, dp[i][1]);
	}

	cout << max_num;

	return 0;
}

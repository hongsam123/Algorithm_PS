//1. ���̺� ����
//D[i] = i�� 1�� ����� ���� �ʿ��� ���� ��� Ƚ���� �ּڰ�
//2. ��ȭ�� ã��
//D[12] = min(D[4]+1, D[3]+1, D[11]+1)
//D[k] = min(D[k/3]+1, D[k/2]+1, D[k-1]+1
//3. �ʱⰪ ����
//D[i] = 0
#include<iostream>
#include<algorithm>
using namespace std;

int dp[1000002];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 2; i <= n; i++)
	{
		dp[i] = dp[i - 1] + 1;
		if (i % 3 == 0)
			dp[i] = min(dp[i / 3] + 1, dp[i]);
		if (i % 2 == 0)
			dp[i] = min(dp[i / 2] + 1, dp[i]);
	}

	cout << dp[n];

	return 0;
}

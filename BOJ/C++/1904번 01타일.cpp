//1. ���̺� ����
//dp[n] = ���̰� n�� ��� 2�� ������ ����
//2. ��ȭ�� ã��
//dp[i] = dp[i - 1] + dp[i - 2]
//3. �ʱⰪ ����
//dp[1] = 1;
//dp[2] = 2; //00, 11
#include<iostream>
using namespace std;

int n;
int dp[1000002];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= n; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
	}

	cout << dp[n];

	return 0;
}

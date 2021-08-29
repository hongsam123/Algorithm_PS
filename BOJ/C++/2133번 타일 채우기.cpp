//1. ���̺� ����
//dp[n] = 3 * n ũ���� ���� Ÿ�Ϸ� ä��� ����� ��
//2. ��ȭ�� ã��
//i�� Ȧ���̸�
//dp[i] = 0;
//¦����(i > 2)
//dp[i] = dp[i - 2] * 3;
//for (int j = i - 4; j >= 0; j = j - 2)
//	dp[i] += dp[j] * 2;
//3. �ʱⰪ ����
//dp[0] = 1;`//���ο� ���� 2���� �߰��ϱ� ���� �ʱⰪ
//dp[1] = 0;
//dp[2] = 3;

#include<iostream>
using namespace std;

int n;
int dp[32];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	
	dp[0] = 1;
	dp[1] = 0;
	dp[2] = 3;

	for (int i = 3; i <= n; i++)
	{
		if (i % 2 == 1)
			dp[i] = 0;
		else
		{
			dp[i] = dp[i - 2] * 3;
			for (int j = i - 4; j >= 0; j = j - 2)
				dp[i] += dp[j] * 2;
		}
	}

	cout << dp[n];

	return 0;
}

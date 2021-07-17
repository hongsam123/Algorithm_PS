//1.���̺� ����
//dp[n] = �¼��� n���� ��� ������ ��ġ�� ����
//2.�ʱⰪ
//dp[0] = 1
//dp[1] = 1
//3. ��ȭ�� ã��
//if (vip[i] || vip[i - 1]) dp[i] = dp[i - 1];
//else dp[i] = dp[i - 1] + dp[i - 2];

#include<iostream>
using namespace std;

int n, m;
bool vip[42];
int dp[42];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int x;
		cin >> x;
		vip[x] = true;
	}

	dp[0] = 1;
	dp[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		if (vip[i]||vip[i-1]) dp[i] = dp[i - 1];
		else dp[i] = dp[i - 1] + dp[i - 2];
	}

	cout << dp[n];

	return 0;
}

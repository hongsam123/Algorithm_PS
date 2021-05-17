//1. ���̺� ����
//dp[n] = n�� ���������� ������ ǥ���� ���� �� ���� �ּ� ����
//2. ��ȭ�� ã��
//for(int j=1;j*j<=i;j++)
//	dp[i] = dp[j] + dp[i - j*j] + 1
//(��� ����� �� �� �ּҰ�)
//3. �ʱⰪ ����
//dp[n] = n
#include<iostream>
#include<algorithm>
using namespace std;

int n;
long long dp[100002];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	/*dp[1] = 1;
	int j = 1;
	int num = 2;
	for (int i = 2; i <= n; i++)
	{
		if (j == i)
			dp[i] = 1;
		else
			dp[i] = dp[j] + dp[i - j];

		if ((num * num - 1) == i)
		{
			j = num * num;
			num++;
		}
	}*/

	for (int i = 1; i <= n; i++)
		dp[i] = i;

	for (int i = 2; i <= n; i++)
		for (int j = 1; j * j <= i; j++)
			dp[i] = min(dp[i], dp[i - j * j] + 1);

	cout << dp[n];

	return 0;
}

//1.���̺� �����ϱ�
//dp[n] = n��° ����� ���� �� ��� ������ �ִ� ��
//2. ��ȭ�� ã��
//dp[i + t[i] - 1] = max(dp[i + t[i] - 1], dp[i - 1] + p[i]);
//dp[i] = max(dp[i], dp[i - 1]);
//3. �ʱⰪ ����
//dp[1 + t[1] - 1] = p[1]

#include<iostream>
#include<algorithm>
using namespace std;

int dp[22];
int t[17];
int p[17];
int n;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> t[i] >> p[i];

	dp[1 + t[1] - 1] = p[1];

	for (int i = 2; i <= n; i++)
	{
		dp[i + t[i] - 1] = max(dp[i + t[i] - 1], dp[i - 1] + p[i]);
		dp[i] = max(dp[i], dp[i - 1]);
	}
	cout << dp[n];

	return 0;
}

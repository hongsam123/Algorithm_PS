//1.���Ǻ� ����
//dp[n] = ���ﰢ���� �߰��ϸ� �������� ���� �� ���� ���̸� k��� �� �� n��° �ﰢ���� ����
//2.��ȭ�� ã��
//dp[i] = dp[i - 2] + dp[i - 3]
//3.�ʱⰪ ����
//dp[1] = 1
//dp[2] = 1
//dp[3] = 1
#include<iostream>
#include<algorithm>
using namespace std;

long long dp[103];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int test;
	cin >> test;

	while (test--)
	{
		int n;
		cin >> n;

		fill(dp, dp + 103, 0);

		dp[1] = 1;
		dp[2] = 1;
		dp[3] = 1;

		for (int i = 4; i <= n; i++)
			dp[i] = dp[i - 2] + dp[i - 3];

		cout << dp[n] << "\n";
	}

	return 0;
}

//1. ���̺� ����
//dp[n][m] = n���� m�� ��ƼĿ�� �� �� ������ �ִ� ��
//2. ��ȭ�� ã��
//dp[i][1] = max(dp[i - 1][2], dp[i - 2][2]) + sticker[1][i];
//dp[i][2] = max(dp[i - 1][1], dp[i - 2][1]) + sticker[2][i];
//3. �ʱⰪ ����
//dp[0][1] = 0
//dp[0][2] = 0
//dp[1][1] = sticker[1][1]
//dp[1][2] = sticker[1][2]
#include<iostream>
using namespace std;

int n;
int sticker[3][100002];
int dp[100002][3];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int test;
	cin >> test;

	while (test--)
	{
		cin >> n;

		for (int i = 0; i <= 2; i++)
			fill(sticker[i], sticker[i] + 100001, 0);


		for (int i = 1; i <= 2; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cin >> sticker[i][j];
			}
		}

		dp[1][1] = sticker[1][1];
		dp[1][2] = sticker[2][1];

		for (int i = 2; i <= n; i++)
		{
			dp[i][1] = max(dp[i - 1][2], dp[i - 2][2]) + sticker[1][i];
			dp[i][2] = max(dp[i - 1][1], dp[i - 2][1]) + sticker[2][i];
		}

		cout<<max(dp[n][1],dp[n][2])<<"\n";
	}

	return 0;
}

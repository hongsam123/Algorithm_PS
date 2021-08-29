//1. �� �����
//dp[i][j] = ���� i��° ������ �ð� ������ ���԰� j�϶� ���濡 ��� ��ġ
//2. �ʱⰪ
//dp[1~n][0] = 0;
//3. ��ȭ��(���1 : ���� ������ ���� �� �ִ°�, ���2 : �ش� ������ ���� ���ΰ�)

#include<iostream>
#include<algorithm>
using namespace std;

int value[102];
int weight[102];
int n, k;
int dp[102][100002];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	for (int i = 1; i <= n; i++)
		cin >> weight[i] >> value[i];

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if (weight[i] > j) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
		}
	}

	cout << dp[n][k];

	return 0;
}

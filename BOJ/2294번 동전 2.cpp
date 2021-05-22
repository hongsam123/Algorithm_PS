//1.���̺�����
//dp[i] = i���� ������ �� ����ϴ� �ּ����� ȭ�󰳼�
//2.��ȭ�� ã��
//dp[i] = dp[arr[j]] + dp[i - arr[j]];
//3.�ʱⰪ ã��
//dp[arr[1]] = 1;
//...
//dp[arr[n]] = 1;
//
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, k;
vector<int> coin;
int dp[100003];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	fill(dp, dp + 100002, 100001);

	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		coin.push_back(x);
		dp[x] = 1;
	}

	sort(coin.begin(), coin.end());

	for (int i = 1; i <= k; i++)
	{
		if (dp[i]!=100001) continue;

		for (int j = n-1; j >=0 ; j--)
		{

			if (coin[j] > i) continue;
			if (dp[i - coin[j]] == 0) continue;
			dp[i] = min(dp[i - coin[j]] + dp[coin[j]],dp[i]);
			//ó�� �ڵ忡�� ���⼭ break�� �ɾ���.
			//������ ������谡 �ƴϱ� ������ ū �׼��� ������ ����������� �ּҰ��̶�� ������ ����
		}
	}
	
	if (dp[k] == 100001)
		cout << -1;
	else
		cout << dp[k];

	return 0;
}

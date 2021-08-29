#include<iostream>
#include<algorithm>
using namespace std;

int n;
int arr[10002];
long long dp[10002];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	dp[0] = 0;
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	dp[3] = max(arr[1], arr[2]) + arr[3];

	for (int i = 4; i <= n; i++)
	{
		dp[i] = max(dp[i-2] , arr[i - 1] + dp[i - 3])+arr[i];	//�������� �� �Ծ��� ���, �ѹ� �ǳʶٰ�  �������� �Ծ��� ��� 
		dp[i] = max(dp[i],arr[i-1]+dp[i-4]+arr[i]);				//�� �� �ǳʶٰ� ���� ���� �Ծ��� ��� 
	}

	if (n == 1)
	{
		cout << dp[n];
		return 0;
	}
	cout << max(dp[n], dp[n - 1]);	//������ ���� �Ծ�����, �� �Ծ����� 

	return 0;
}

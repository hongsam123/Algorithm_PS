//단순히 값을 출력하는 것이 아니라 거쳐온 과정을 출력한다.
//이럴때는 dp테이블을 채우며 추가적인 정보를 어딘가에 기입해야한다
//추가 적인 정보가 들어갈 테이블(경로 복원용 테이블)을 따로둔다.
//
#include<iostream>
#include<algorithm>
using namespace std;

int dp[1000002];
int pre[1000002];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;

	dp[1] = 0;
	pre[1] = 0;

	for (int i = 2; i <= n; i++)
	{
		dp[i] = dp[i - 1] + 1;
		pre[i] = i - 1;
		if (i % 3 == 0 && dp[i] > dp[i / 3] + 1)
		{
			dp[i] = dp[i / 3] + 1;
			pre[i] = i / 3;
		}
		if (i % 2 == 0 && dp[i] > dp[i / 2] + 1)
		{
			dp[i] = dp[i / 2] + 1;
			pre[i] = i / 2;
		}
	}

	cout << dp[n] << "\n";
	int x = n;
	cout << x << " ";
	while (1)
	{
		if (x == 1) break;
		cout<<pre[x]<<" ";
		x = pre[x];
	}

	return 0;
}


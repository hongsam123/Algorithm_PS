//1.테이블정의
//dp[i] = i원을 구성할 때 사용하는 최소한의 화폐개수
//2.점화식 찾기
//dp[i] = dp[arr[j]] + dp[i - arr[j]];
//3.초기값 찾기
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
			//처음 코드에서 여기서 break를 걸었다.
			//동전이 배수관계가 아니기 때문에 큰 액수의 동전을 사용했을때가 최소값이라는 보장이 없음
		}
	}
	
	if (dp[k] == 100001)
		cout << -1;
	else
		cout << dp[k];

	return 0;
}

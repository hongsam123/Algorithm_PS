//표를 생각하기
//1. 테이블 정의
//dp[n][m] = 첫번째 글자를 n번째, 두번째 글자를 m번째 봤을 때 최대 LCS의 길이
//2. 점화식 찾기
//if (a[i] == b[i]) dp[i][j] = dp[i - 1][j - 1] + 1
//else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j])
//3. 초기값 설정
#include<iostream>
using namespace std;

string a;
string b;
int dp[1002][1002];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b;

	a = '0' + a;
	b = '0' + b;

	for (int i = 1; i < a.size(); i++)
	{
		for (int j = 1; j < b.size(); j++)
		{
			if (a[i] == b[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	cout << dp[a.size() - 1][b.size() - 1];

	return 0;
}

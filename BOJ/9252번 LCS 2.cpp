//#include<iostream>
//using namespace std;
//
//string a;
//string b;
////int dp[1002][1002];
//string dpl[1002][1002];
//
//int main()
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> a >> b;
//
//	a = '0' + a;
//	b = '0' + b;
//
//	for (int i = 1; i < a.size(); i++)
//	{
//		for (int j = 1; j < b.size(); j++)
//		{
//			if (a[i] == b[j])
//			{
//				//dp[i][j] = dp[i - 1][j - 1] + 1;
//				dpl[i][j] = dpl[i - 1][j - 1] + a[i];
//			}
//			else
//			{
//				//dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
//				if (dpl[i][j - 1].size() >= dpl[i - 1][j].size())
//					dpl[i][j] = dpl[i][j - 1];
//				else
//					dpl[i][j] = dpl[i - 1][j];
//			}
//		}
//	}
//
//	cout << dpl[a.size() - 1][b.size() - 1].size() << "\n";
//	cout << dpl[a.size() - 1][b.size() - 1];
//
//	return 0;
//}
//처음의 코드
//lcs1을 구할때 처럼 dpl이라는 string dp테이블을 하나 더 생성
//답은 나오지만 시간이 다른 사람들에 비해 오래 걸려 다른 풀이를 찾아봄

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
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
		}
	}

	cout << dp[a.size() - 1][b.size() - 1] << "\n";

	//LCS DP표
	/*for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < b.size(); j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";*/
	
	//LCS구하기 (dp표를 거꾸로 추적하며 더해가기)
	string ans = "";
	int len = dp[a.size() - 1][b.size() - 1];
	int x = a.size()-1, y = b.size()-1;

	while (len)
	{
		while (dp[x][y] == dp[x][y - 1]) y--;
		while (dp[x][y] == dp[x - 1][y]) x--;
		ans = b[y] + ans;
		len--;
		x--;
		y--;
	}
	cout << ans;

	return 0;
}
//새로운 코드 시간이 단축된다
//위에서 작성한 dp테이블을 거꾸로 추적하며 테이블이 변화할때(같은 글자가 있을때)
//적절히 인덱스를 변경하여 lcs출력 

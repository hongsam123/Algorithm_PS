//1. 테이블 정의
//dp[i] = i번째 계단에 올랐을때 얻을 수 있는 최대 점수
//2. 점화식
//dp[4] = min(dp[2] + score[4],dp[3] + score[4])
//dp[i] = min(dp[i-2]+score[i],dp[i-1]+score[i])
//3. 초기값
//dp[1] = score[1]
//dp[2] = score[1] + score[2]
//dp[3] = score[1] + score[3]
//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//int dp[302];
//int score[302];
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int n;
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> score[i];
//	}
//
//	dp[1] = score[1];
//	dp[2] = score[1] + score[2];
//	dp[3] = score[1] + score[3];
//
//	for (int i = 4; i <= n; i++)
//		dp[i] = max(dp[i - 2] + score[i], dp[i - 1] + score[i]);
//
//	cout << dp[n];
//
//	return 0;
//}
//는 dp를 푼지 얼마 되지 않은 첫번째 풀이 
//위와 같이 푸는 것은 적합하지 않다...^^
//연속해서 밟을수 없는 것을 아주 단순하게만 고려함
//다시...!
//
//1. 테이블 정의하기
//dp[i][j] = 현재까지 j개의 계단을 연속해서 밟고 i번째 계단까지 올라 섰을 때
//점수 합의 최대값, 단 i번째 계단은 반드시 밟아야 함
//2. 점화식 찾기
//dp[k][1] = max(dp[k - 2][1] + score[k], dp[k - 2][2] + score[k])
//dp[k][2] = dp[k - 1][1] + score[k]
//3. 초기값 정의
//dp[1][1] = score[1], dp[1][2] = 0
//dp[2][1] = score[2], dp[2][2] = score[1] + score[2];
#include<iostream>
#include<algorithm>
using namespace std;

int score[302];
int dp[302][3];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> score[i];

	dp[1][1] = score[1];
	dp[1][2] = 0;
	dp[2][1] = score[2];
	dp[2][2] = score[1] + score[2];

	for (int i = 3; i <= n; i++)
	{
		dp[i][1] = max(dp[i - 2][1], dp[i - 2][2]) + score[i];
		dp[i][2] = dp[i - 1][1] + score[i];
	}

	cout << max(dp[n][1], dp[n][2]);
	return 0;
}
//그런데 이 문제를 관점을 바꿔 1차원 배열로 구현해 볼 수도 있다
//1. 테이블 정의
//dp[i] = i번째 계단까지 올라섰을 때 밟지 않을 계단의 합의 최소값,
//단 i번째 계단은 반드시 밟지 않을 계단으로 선택해야 함
//2. 점화식 찾기
//주의) 막막한것은 당연.막막하다면 테이블을 차근히 채워보기
//dp[i] = min(dp[i - 2], dp[i - 3]) + score[i]
//3. 초기값 정의
//dp[1] = score[1], dp[2] = score[2], dp[3] = score[3]
//정답 출력은 마지막 계단은 반드시 밟아야 하니 
//총 계단의 합에서 min(dp[n-1],dp[n-2])를 빼면된다

//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//int dp[302];
//int score[302];
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int n;
//	cin >> n;
//
//	int total = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> score[i];
//		total += score[i];
//	}
//
//	//계단이 2개 이하일때 예외처리
//	if (n <= 2)
//	{
//		cout << total;
//		return 0;
//	}
//
//	dp[1] = score[1];
//	dp[2] = score[2];
//	dp[3] = score[3];
//
//	for (int i = 4; i < n; i++)
//		dp[i] = min(dp[i - 2] + score[i], dp[i - 3] + score[i]);
//
//	cout << total - min(dp[n-2],dp[n-1]);
//	return 0;
//}

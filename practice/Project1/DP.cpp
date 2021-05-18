//DP를 푸는 과정
//1. 테이블 정의하기
//2. 점화식 찾기
//3. 초기값 정하기
//코딩테스트에 나올 수준의 DP는 일단 점화식만 찾고나면
//그 뒤는 초기값을 채워넣은 후 반복문을 돌며 배열을 채우면 된다

// boj 1463 1로 만들기
//1. 테이블 정의
//D[i] = i를 1로 만들기 위해 필요한 연산 사용 횟수의 최솟값
//2. 점화식 찾기
//D[12] = min(D[4]+1, D[3]+1, D[11]+1)
//D[k] = min(D[k/3]+1, D[k/2]+1, D[k-1]+1
//3. 초기값 정의
//D[i] = 0
//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//int dp[1000002];
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int n;
//	cin >> n;
//
//	for (int i = 2; i <= n; i++)
//	{
//		dp[i] = dp[i - 1] + 1;
//		if (i % 3 == 0)
//			dp[i] = min(dp[i / 3] + 1, dp[i]);
//		if (i % 2 == 0)
//			dp[i] = min(dp[i / 2] + 1, dp[i]);
//	}
//
//	cout << dp[n];
//
//	return 0;
//}

//boj 9095 1,2,3 더하기
//1. 테이블 정의하기
//D[i] = i를 1,2,3의 합으로 나타내는 방법의 수
//2. 점화식 찾기
//D[4] = 
//1+1+1+1, 1+2+1, 2+1+1, 3+1 => 3을 1,2,3의 합으로 나타내는 방법+1 =>D[3]
//1+1+2, 2+2 => 2를 1,2,3의 합으로 나타내는 방법+2 => D[2]
//1+3 => 1을 1,2,3의 합으로 나타내는 방법+3 => D[1]
//D[i] = D[i-1]+D[i-2]+D[i-3]
//3. 초기값 정의
//초기값이 최소 3개는 주어져야함(D[1],D[2],D[3])

//#include<iostream>
//using namespace std;
//
//int dp[13];
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	dp[1] = 1;
//	dp[2] = 2;
//	dp[3] = 4;
//	for (int i = 4; i <= 10; i++)
//		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
//
//	int test;
//	cin >> test;
//
//	while (test--)
//	{
//		int n;
//		cin >> n;
//		
//		cout << dp[n] << "\n";
//	}
//
//	return 0;
//}

//boj 1,2,3 더하기 3

//boj 2579
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

//위와 같이 푸는 것은 적합하지 않다...^^
//왜냐면 연속해서 밟을수 없는 것을 아주 단순하게만 고려함
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
//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//int score[302];
//int dp[302][3];
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int n;
//	cin >> n;
//
//	for (int i = 1; i <= n; i++)
//		cin >> score[i];
//
//	dp[1][1] = score[1];
//	dp[1][2] = 0;
//	dp[2][1] = score[2];
//	dp[2][2] = score[1] + score[2];
//
//	for (int i = 3; i <= n; i++)
//	{
//		dp[i][1] = max(dp[i - 2][1], dp[i - 2][2]) + score[i];
//		dp[i][2] = dp[i - 1][1] + score[i];
//	}
//
//	cout << max(dp[n][1], dp[n][2]);
//	return 0;
//}
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

//boj1149
//1. 테이블 정의하기(색상에 대한 정보가 추가적으로 들어가게끔 정의해야함)
//dp[i][0] = i번째 집까지 칠할 때 비용의 최소값, 단, i번째 집은 빨강
//dp[i][1] = i번째 집까지 칠할 때 비용의 최소값, 단, i번째 집은 초록
//dp[i][2] = i번째 집까지 칠할 때 비용의 최소값, 단, i번째 집은 파랑
//2. 점화식 찾기
//dp[k][0] = min(dp[k - 1][1], dp[k - 1][2]) + cost[k][0]
//dp[k][1] = min(dp[k - 1][0], dp[k - 1][2]) + cost[k][1]
//dp[k][2] = min(dp[k - 1][0], dp[k - 1][1]) + cost[k][2]
//3. 초기값 정의하기
//dp[1][0] = cost[1][0]
//dp[1][1] = cost[1][1]
//dp[1][2] = cost[1][2]
//
//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//int dp[1002][3];
//int cost[1002][3];
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int n;
//	cin >> n;
//
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			cin >> cost[i][j];
//		}
//	}
//
//	dp[1][0] = cost[1][0];
//	dp[1][1] = cost[1][1];
//	dp[1][2] = cost[1][2];
//
//	for (int i = 2; i <= n; i++)
//	{
//		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
//		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
//		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
//	}
//
//	int min_cost = min(dp[n][0], dp[n][1]);
//	min_cost = min(min_cost, dp[n][2]);
//	//min_cost = min({ dp[n][0],dp[n][1],dp[n][2] });
//	//min_cost = *min_element(dp[n], dp[n] + 3);
//
//	cout << min_cost;
//
//	return 0;
//}

//boj11726 2*n 타일링
//1. 테이블 정의하기
//dp[i] = 2 * i크기의 직사각형을 채우는 방법의 수
//2. 점화식 찾기
//맨 왼쪽 위 타일이 2 * 1일때 남은 칸을 채우는 방법의 수 = > dp[i - 1]
//맨 왼쪽 위 타일이 1 * 2일때 남은 칸을 채우는 방법의 수 = > dp[i - 2]
//dp[i] = dp[i - 1] + dp[i - 2]
//3. 초기값 정의하기
//dp[1] = 1
//dp[2] = 2


//boj11659
//#include<iostream>
//using namespace std;
//
//int arr[100002];
//int dp[100002];
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int n, m;
//	cin >> n >> m;
//	for (int i=1; i <= n; i++)
//	{
//		cin >> arr[i];
//	}
//
//	dp[1] = arr[1];
//	for (int i = 2; i <= n; i++)
//		dp[i] = dp[i - 1] + arr[i];
//
//	while (m--)
//	{
//		int a, b;
//		cin >> a >> b;
//		cout << dp[b] - dp[a - 1]<<"\n";
//	}
//
//	return 0;
//}

//boj12852
//단순히 값을 출력하는 것이 아니라 거쳐온 과정을 출력한다.
//이럴때는 dp테이블을 채우며 추가적인 정보를 어딘가에 기입해야한다
//추가 적인 정보가 들어갈 테이블(경로 복원용 테이블)을 따로둔다.
//
//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//int dp[1000002];
//int pre[1000002];
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	
//	int n;
//	cin >> n;
//
//	dp[1] = 0;
//	pre[1] = 0;
//
//	for (int i = 2; i <= n; i++)
//	{
//		dp[i] = dp[i - 1] + 1;
//		pre[i] = i - 1;
//		if (i % 3 == 0 && dp[i] > dp[i / 3] + 1)
//		{
//			dp[i] = dp[i / 3] + 1;
//			pre[i] = i / 3;
//		}
//		if (i % 2 == 0 && dp[i] > dp[i / 2] + 1)
//		{
//			dp[i] = dp[i / 2] + 1;
//			pre[i] = i / 2;
//		}
//	}
//
//	cout << dp[n] << "\n";
//	int x = n;
//	cout << x << " ";
//	while (1)
//	{
//		if (x == 1) break;
//		cout<<pre[x]<<" ";
//		x = pre[x];
//	}
//
//	return 0;
//}

//boj 1932
//1. 테이블 정의하기
//dp[i][j] = { i,j }경로에 왔을때의 최대 값을 저장
//2. 점화식
//dp[k][1] = dp[k - 1][1] + arr[k][1]
//dp[k][j] = max(dp[k-1][j - 1], dp[k-1][j]) + arr[k][j]
//dp[k][k] = dp[k - 1][k-1] + arr[k][k]
//3. 초기값 정의하기
//dp[1][1] = arr[1][1]

//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//int arr[502][502];
//int dp[502][502];
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int n;
//	cin >> n;
//
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= i; j++)
//			cin >> arr[i][j];
//	}
//
//	dp[1][1] = arr[1][1];
//	if (n == 1)
//	{
//		cout << dp[1][1];
//		return 0;
//	}
//
//	dp[2][1] = dp[1][1] + arr[2][1];
//	dp[2][2] = dp[1][1] + arr[2][2];
//	if (n == 2)
//	{
//		cout << max(dp[2][1], dp[2][2]);
//		return 0;
//	}
//
//	for (int i = 3; i <= n; i++)
//	{
//		dp[i][1] = dp[i - 1][1] + arr[i][1];
//		for (int j = 2; j <= i - 1; j++)
//		{
//			dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + arr[i][j];
//		}
//		dp[i][i] = dp[i - 1][i - 1] + arr[i][i];
//	}
//
//	int max_cost = *max_element(dp[n], dp[n] + n+1);
//
//	cout << max_cost;
//
//	return 0;
//}

//boj 2193
//1. 테이블 정의하기
//dp[i][0] = i번째 자리에 0이 올때 이친수의 개수
//dp[i][1] = i번째 자리에 1이 올때 이친수의 개수
//2. 점화식
//dp[i][0] = dp[i - 1][0] + dp[i - 1][1]
//dp[i][1] = dp[i - 1][0]
//3. 초기값
//dp[1][0] = 0
//dp[1][1] = 1
//
//#include<iostream>
//using namespace std;
//
//int n;
//long long dp[92][2];
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> n;
//
//	dp[1][0] = 0;
//	dp[1][1] = 1;
//
//	for (int i = 2; i <= n; i++)
//	{
//		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
//		dp[i][1] = dp[i - 1][0];
//	}
//
//	cout << dp[n][0] + dp[n][1];
//
//	return 0;
//}

//boj11727
//1. 테이블 정의하기
//dp[i] = 2 * i크기의 직사각형을 채우는 방법의 수
//2. 점화식 찾기
//1) 맨 왼쪽 위 타일이 1 * 2 타일 일 때 남은 칸을 채우는 방법의 수 = > dp[i - 2]
//2) 맨 왼쪽 위 타일이 2 * 1 타일 일 때 남은 칸을 채우는 방법의 수 = > dp[i - 1]
//3) 맨 왼쪽 위 타일이 2 * 2 타일 일 때 남은 칸을 채우는 방법의 수 = > dp[i - 2]
//dp[i] = dp[i - 1] + 2 * (dp[i - 2])
//3. 초기값 정의하기
//dp[1] = 1
//dp[2] = 3
//
//#include<iostream>
//using namespace std;
//
//int dp[1002];
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int n;
//	cin >> n;
//	
//	dp[1] = 1;
//	dp[2] = 3;
//	for (int i = 3; i <= n; i++)
//	{
//		dp[i] =( dp[i - 1] + 2 * (dp[i - 2]) )%10007;
//		/*마지막에만 10007로 나누면 int overflow발생.
//		중간중간 나누어 저장해야한다*/
//	}
//
//	cout << dp[n];
//
//	return 0;
//}


//boj14501 퇴사
//boj 18353 병사배치하기
//1. 테이블 정의하기
//dp[n] = 현재 병사를 배치했을때 가능한 최대 병사 수
//2. 점화식 찾기
//for (int j = 0; j <= i; j++)
//	if (arr[i] > arr[j]) dp[i] = max(dp[i], dp[j] + 1)
//
//LIS(Longest Increasing Subsequence)
//하나의 수열이 주어졌을 때 값들이 증가하는 형태의 가장 긴 부분 수열을 찾는 대표적인 dp
//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//int n;
//long long dp[2002];
//long long arr[2002];
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	long long max_num = 1;
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//		cin >> arr[i];
//
//	fill(dp, dp + n + 1, 1);
//	
//	for (int i = n-1; i >= 1; i--)
//	{
//		for (int j = n; j > i; j--)
//		{
//			if (arr[i] > arr[j])
//				dp[i] = max(dp[i], dp[j] + 1);
//			max_num = max(max_num, dp[i]);
//		}
//	}
//
//	cout << n - max_num;
//
//	return 0;
//}

//boj 11053 가장 긴 증가하는 부분 수열(LCS)

//boj 2156 포도주 시식(boj 2579와 비슷)
//(하다고 생각했겠지만 아주 큰 착각이었음을)
//
//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//int n;
//int arr[10002];
//long long dp[10002];
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> n;
//
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> arr[i];
//	}
//
//	dp[0] = 0;
//	dp[1] = arr[1];
//	dp[2] = arr[1] + arr[2];
//	dp[3] = max(arr[1], arr[2]) + arr[3];
//
//	for (int i = 4; i <= n; i++)
//	{
//		dp[i] = max(dp[i-2] , arr[i - 1] + dp[i - 3])+arr[i];
//		dp[i] = max(dp[i],arr[i-1]+dp[i-4]+arr[i]);
//	}
//
//	if (n == 1)
//	{
//		cout << dp[n];
//		return 0;
//	}
//	cout << max(dp[n], dp[n - 1]);
//
//	return 0;
//}

//boj2294 동전 2
//1.테이블정의
//dp[i] = i원을 구성할 때 사용하는 최소한의 화폐개수
//2.점화식 찾기
//dp[i] = dp[arr[j]] + dp[i - arr[j]];
//3.초기값 찾기
//dp[arr[1]] = 1;
//...
//dp[arr[n]] = 1;
//
//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//
//int n, k;
//vector<int> coin;
//int dp[100003];
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> n >> k;
//
//	fill(dp, dp + 100002, 100001);
//
//	for (int i = 1; i <= n; i++)
//	{
//		int x;
//		cin >> x;
//		coin.push_back(x);
//		dp[x] = 1;
//	}
//
//	sort(coin.begin(), coin.end());
//
//	for (int i = 1; i <= k; i++)
//	{
//		if (dp[i]!=100001) continue;
//
//		for (int j = n-1; j >=0 ; j--)
//		{
//
//			if (coin[j] > i) continue;
//			if (dp[i - coin[j]] == 0) continue;
//			dp[i] = min(dp[i - coin[j]] + dp[coin[j]],dp[i]);
//			//처음 코드에서 여기서 break를 걸었다.
//			//동전이 배수관계가 아니기 때문에 큰 액수의 동전을 사용했을때가 최소값이라는 보장이 없음
//		}
//	}
//	
//	if (dp[k] == 100001)
//		cout << -1;
//	else
//		cout << dp[k];
//
//	return 0;
//}

//boj1912 연속합
//boj9461 파도반 수열
//boj10844 쉬운 계단 수
//boj1699 제곱수의 합
//boj2133 타일 채우기
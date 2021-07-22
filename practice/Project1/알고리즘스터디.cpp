// p.178 위에서 아래로
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//bool comp(int a, int b)
//{
//	return a > b;
//}
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	vector<int> v;
//	int n,x;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> x;
//		v.push_back(x);
//	}
//	
//	// 1. reverse 함수 사용
//	/*sort(v.begin(), v.end());
//	reverse(v.begin(), v.end());*/
//
//	//2. rbegin(), rend()
//	/*sort(v.rbegin(), v.rend());*/
//
//	//3. 비교함수 인수로 넘기기
//	sort(v.begin(), v.end(), comp);
//
//	for (int i = 0; i < n; i++)
//		cout << v[i] << " ";
//	
//	return 0;
//}

// p.180 성적이 낮은 순서로 학생 출력하기
//#include<iostream>
//#include<vector>
//#include<utility>
//#include<algorithm>
//using namespace std;
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int n;
//	cin >> n;
//
//	vector<pair<int, string>> v;
//	string str;
//	int idx;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> str >> idx;
//		v.push_back({ idx,str });
//	}
//
//	sort(v.begin(), v.end());
//
//	for (int i = 0; i < n; i++)
//	{
//		cout << v[i].second << " ";
//	}
//
//	return 0;
//}

//p.182 두 배열의 원소교체
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int n, k;
//	cin >> n >> k;
//	
//	int x;
//	vector<int> v1;
//	vector<int> v2;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> x;
//		v1.push_back(x);
//	}
//	for (int i = 0; i < n; i++)
//	{
//		cin >> x;
//		v2.push_back(x);
//	}
//
//	sort(v1.begin(), v1.end());
//	sort(v2.rbegin(), v2.rend());
//
//	int tmp;
//	for (int i = 0; i < k; i++)
//	{
//		if (v1[i] > v2[i]) break;
//		tmp = v1[i];
//		v1[i] = v2[i];
//		v2[i] = tmp;
//	}
//
//	int sum = 0;
//	for (int i = 0; i < n; i++)
//	{
//		sum += v1[i];
//	}
//
//	cout << sum;
//
//	return 0;
//}


//p.322 문자열재정렬
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	string str;
//	cin >> str;
//
//	vector<char> v;
//	int total = 0;
//
//	for (int i = 0; i < str.size(); i++)
//	{
//		if (str[i] - '0' >= 0 && str[i] - '0' <= 9)	//숫자라면
//			total += str[i] - '0';
//		else
//		{
//			v.push_back(str[i]);
//		}
//	}
//	sort(v.begin(), v.end());
//
//	for (int i = 0; i < v.size(); i++)
//		cout << v[i];
//	cout << total;
//
//	return 0;
//}

//p.217 1로 만들기
//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//int dp[30002];
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
//	
//	for (int i = 2; i <= n; i++)
//	{
//		dp[i] = dp[i - 1] + 1;
//		if (i % 2 == 0)
//		{
//			dp[i] = min(dp[i / 2]+1, dp[i]);
//		}
//		else if (i % 3 == 0)
//		{
//			dp[i] = min(dp[i], dp[i / 3] + 1);
//		}
//		else if (i % 5 == 0)
//		{
//			dp[i] = min(dp[i], dp[i / 5]+1);
//		}
//	}
//
//	cout << dp[n];
//	return 0;
//}

//p.220 개미전사
//1. 테이블 정의
//dp[i] = i번째 식량창고에 왔을 때 얻을 수 있는 최대 식량의 양
//2. 점화식 찾기
//dp[i] = max(dp[i - 1], dp[i - 2]+arr[i])
//3.초기값 정의
//dp[1] = arr[1]
//dp[2] = arr[2]
//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//int arr[102];
//int dp[102];
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
//		cin >> arr[i];
//
//	dp[1] = arr[1];
//	dp[2] = arr[2];
//
//	for (int i = 3; i <= n; i++)
//	{
//		dp[i] = max(dp[i - 2], dp[i - 3]) + arr[i];
//	}
//
//	cout << max(dp[n], dp[n - 1]);
//
//
//	return 0;
//}
//dp[i] = i번째 식량 창고에 도달했을 때 최대 턴 식량의 양
//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//int arr[102];
//int dp[102];
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
//		cin >> arr[i];
//
//	dp[1] = arr[1];
//	dp[2] = max(arr[1],arr[2]);
//
//	for (int i = 3; i <= n; i++)
//	{
//		dp[i] = max(dp[i - 1], dp[i - 2] + arr[i]);
//	}
//
//	cout << dp[n];
//
//
//	return 0;
//}

//p.223 바닥공사
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
//		dp[i] =( dp[i - 1] + 2 * (dp[i - 2]) )%796796;
//		/*마지막에만 10007로 나누면 int overflow발생.
//		중간중간 나누어 저장해야한다*/
//	}
//
//	cout << dp[n];
//
//	return 0;
//}
//SDS 알고리즘 특강
//7/19
//boj 3425 고스택
//boj 3055 탈출
//boj 1062 가르침
//boj 1713 후보 추천하기
//boj 1104 게임
//7/21
//boj 2042 구간 합 구하기
//7/22
//boj 2243 사탕상자
//boj 9202 Boggle
//boj 14476 최대공약수 하나 빼기
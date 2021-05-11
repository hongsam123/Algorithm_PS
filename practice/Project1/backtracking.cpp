//N과 M(1)
//#include<iostream>
//using namespace std;
//
//int n, m;
//int arr[10];
//bool isused[10];
//
//void func(int k)
//{
//	if (k == m)
//	{
//		for (int i = 0; i < m; i++)
//			cout << arr[i] << " ";
//		cout << "\n";
//		return;
//	}
//	
//	for (int i = 1; i <= n; i++)
//	{
//		if (!isused[i])
//		{
//			arr[k] = i;
//			isused[i] = 1;
//			func(k + 1);
//			isused[i] = 0;
//		}
//	}
//}
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> n >> m;
//	func(0);
//
//	return 0;
//}

//N과 M(2)
//#include<iostream>
//using namespace std;
//
//int n, m;
//int arr[10];
//bool isused[10];
//
//void func(int k)
//{
//	if (k == m)
//	{
//		for (int i = 0; i < m; i++)
//			cout << arr[i] << " ";
//		cout << "\n";
//		return;
//	}
//	
//	for (int i = 1; i <= n; i++)
//	{
//		if (!isused[i])
//		{
//			if (k == 0)
//			{
//				arr[k] = i;
//				isused[i] = 1;
//				func(k + 1);
//				isused[i] = 0;
//			}
//			else
//				if (arr[k - 1] < i)
//				{
//					arr[k] = i;
//					isused[i] = 1;
//					func(k + 1);
//					isused[i] = 0;
//				}
//		}
//	}
//}
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> n >> m;
//	func(0);
//
//	return 0;
//}
//
// N과 M(3)
//#include<iostream>
//using namespace std;
//
//int n, m;
//int arr[10];
////bool isused[10];
//
//void func(int k)
//{
//	if (k == m)
//	{
//		for (int i = 0; i < m; i++)
//			cout << arr[i] << " ";
//		cout << "\n";
//		return;
//	}
//	
//	for (int i = 1; i <= n; i++)
//	{
//		//if (!isused[i])
//		{
//			arr[k] = i;
//			//isused[i] = 1;
//			func(k + 1);
//			//isused[i] = 0;
//		}
//	}
//}
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> n >> m;
//	func(0);
//
//	return 0;
//}

// N과 M(4)
//#include<iostream>
//using namespace std;
//
//int n, m;
//int arr[10];
////bool isused[10];
//
//void func(int k)
//{
//	if (k == m)
//	{
//		for (int i = 0; i < m; i++)
//			cout << arr[i] << " ";
//		cout << "\n";
//		return;
//	}
//	
//	for (int i = 1; i <= n; i++)
//	{
//		//if (!isused[i])
//		{
//			if (k == 0)
//			{
//				arr[k] = i;
//				//isused[i] = 1;
//				func(k + 1);
//				//isused[i] = 0;
//			}
//			else
//				if (arr[k - 1] <= i)
//				{
//					arr[k] = i;
//					//isused[i] = 1;
//					func(k + 1);
//					//isused[i] = 0;
//				}
//		}
//	}
//}
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> n >> m;
//	func(0);
//
//	return 0;
//}

// N과 M(5)
//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//int n, m;
//int board[10];
//int arr[10];
//bool isused[10002];
//
//void func(int k)
//{
//	if (k == m)
//	{
//		for (int i = 0; i < m; i++)
//			cout << arr[i] << " ";
//		cout << "\n";
//		return;
//	}
//	
//	for (int i = 0; i < n; i++)
//	{
//		int x = board[i];
//		if (isused[x]) continue;
//		arr[k] = x;
//		isused[x] = 1;
//		func(k + 1);
//
//		isused[x] = 0;
//	}
//}
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> n >> m;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> board[i];
//	}
//
//	sort(board, board + n);
//
//	func(0);
//
//	return 0;
//}

//N과 M(6) (next_permutation)
//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//
//int n,m;
//int arr[10002];
//int tmp[10002];
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> n >> m;
//
//	for (int i = 0; i < n; i++)
//	{
//		cin >> arr[i];
//	}
//
//	for (int i = m; i < n; i++)
//	{
//		tmp[i] = 1;
//	}
//	
//	sort(arr, arr + n);
//
//	do
//	{
//		for (int i = 0; i < n; i++)
//		{
//			if (tmp[i] == 0)
//			{
//				cout << arr[i] << " ";
//			}
//		}
//		cout << "\n";
//	} while (next_permutation(tmp, tmp + n));
//
//
//	return 0;
//}

//boj 9663
//#include<iostream>
//using namespace std;
//
//int n;
//bool isused1[16];	//열(y)
//bool isused2[32];	//우상좌하 대각선(x+y)
//bool isused3[32];	//좌상우하 대각선(x-y+n-1) => 음수가 되는 인덱스를 없애기 위해서
//int cnt;
//
//void func(int cur)	//cur행의 퀸의 위치를 정하는 함수
//{
//	if (cur == n )
//	{
//		cnt++;
//		return;
//	}
//	for (int i = 0; i < n; i++)
//	{
//		if (isused1[i] || isused2[cur + i] || isused3[cur - i + n - 1]) continue;
//		isused1[i] = true;
//		isused2[cur + i] = true;
//		isused3[cur - i + n - 1] = true;
//		func(cur + 1);
//
//		isused1[i] = false;
//		isused2[cur + i] = false;
//		isused3[cur - i + n - 1] = false;
//	}
//}
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	
//	cin >> n;
//	func(0);
//
//	cout << cnt;
//
//	return 0;
//}

//boj1182
//#include<iostream>
//using namespace std;
//
//int n, s;
//int cnt;
//bool isused[22];
//int arr[22];
//int sum;
//
//void func(int nx,int x)
//{
//	if (nx == n) return;
//
//	if (sum == s && nx != 0)		
//	{
//		cnt++;
//		//return;	//return 하면 sum과 s 같아졌을때 그 이후 수열을 더하지 않고 return 해버린다
//	}
//
//	for (int i = 0 ; i < n; i++)
//	{
//		if (isused[i] || x>i) continue;		// 이미 합을 구했던 부분수열은 고려하지 않음
//
//		isused[i] = true;
//		sum += arr[i];
//		func(nx + 1,i);
//
//		isused[i] = false;
//		sum -= arr[i];
//	}
//}
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> n >> s;
//	for (int i = 0 ; i < n; i++)
//		cin >> arr[i];
//
//	func(0,0);
//
//	cout << cnt;
//
//	return 0;
//}

// boj 1182 바킹독
// 각 수를 더할지 말지를 고려하며 모든 부분수열의 합 상태공간 트리를 그린다고 생각
// 시간 복잡도는 O(n^2) (위 코드보다 빠르다)
//#include<iostream>
//using namespace std;
//
//int n, s;
//int arr[22];
//int cnt;
//
//void func(int cur, int tot)
//{
//	if (cur == n)
//	{
//		if (tot == s)	// 각 수가 들어가는지 안들어가는지 모든 경우의 수(cur==n)를 구하는 것이므로
//						// 합이 s면 return;
//		{
//			cnt++;
//		}
//		return;
//	}
//	func(cur + 1, tot);
//	func(cur + 1, tot + arr[cur]);
//}
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> n >> s;
//	for (int i = 0; i < n; i++)
//		cin >> arr[i];
//
//	func(0, 0);
//
//	if (s == 0) cnt--;	//s가 0일때는 공집합 일때를 고려(-1)
//	cout << cnt;
//
//	return 0;
//}

//next_permutation
//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//int main(void)
//{
//	int a[3] = { 1,1,3 };
//	//next_permutation을 이용한 순열
//	//
//	//nest_permutation은 현재의 수열을 사전순으로 생각했을 때 
//	//다음 수열로 만들고 true를 return한다
//	//만약 현재의 수열이 사전순으로 생각했을 때 제일
//	//마지막 수열이라면 false를 return
//	do {
//		for (int i = 0; i < 3; i++)
//		{
//			cout << a[i];
//		}
//		cout << "\n";
//	} while (next_permutation(a, a + 3));
//
//	cout << "\n";
//
//	//next_permutation을 이용한 조합
//	int b[4] = { 0,0,1,1 };
//	do {
//		for (int i = 0; i < 4; i++)
//		{
//			if (b[i] == 0)
//				cout << i + 1;
//		}
//		cout << "\n";
//	} while (next_permutation(b, b + 4));
//	//만약 5개중에 3개의 조합을 구한다면
//	//a[5] = {0,0,0,1,1}의 배열로 구할 수 있다
//
//	return 0;
//}


//#include<iostream>
//using namespace std;
//
//int n, s;
//int cnt;
//bool isused[22];
//int arr[22];
//int sum;
//
//void func(int nx, int x)
//{
//	//if (nx == n) return;	//isused로 점점 고려할 수열의 원소 수가 줄어들기 때문에 이 조건에는 어차피 한번밖에 걸리지 않는다 
//
//	if (sum == s && nx != 0)
//	{
//		cnt++;
//		//return;	//return 하면 sum과 s 같아졌을때 그 이후 수열을 더하지 않고 return 해버린다
//	}
//
//	for (int i = 0; i < n; i++)
//	{
//		if (isused[i] || x > i) continue;		// 이미 합을 구했던 부분수열은 고려하지 않음
//
//		isused[i] = true;
//		sum += arr[i];
//		func(nx + 1, i);
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
//	for (int i = 0; i < n; i++)
//		cin >> arr[i];
//
//	func(0, 0);
//
//	cout << cnt;
//
//	return 0;
//}
// but 한눈에 들어오지 않는 코드.. 
// (다른풀이)
// 각 수를 더할지 말지를 고려하며 모든 부분수열의 합 상태공간 트리를 그린다
// 시간 복잡도는 O(n^2)
#include<iostream>
using namespace std;

int n, s;
int arr[22];
int cnt;

void func(int cur, int tot)
{
	if (cur == n)
	{
		if (tot == s)	// 각 수가 들어가는지 안들어가는지 모든 경우의 수(cur==n)를 구하는 것이므로
						// 합이 s면 return;
		{
			cnt++;
		}
		return;
	}
	func(cur + 1, tot);
	func(cur + 1, tot + arr[cur]);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	func(0, 0);

	if (s == 0) cnt--;	//s가 0일때는 공집합 일때를 고려(-1)
	cout << cnt;

	return 0;
}

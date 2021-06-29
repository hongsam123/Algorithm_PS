//정렬된 배열의 이분탐색에서 오름차순 순서가 유지되는 제일 왼쪽/오른쪽 인덱스의 차이가 해당 배열 내에 target의 등장 횟수
#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
int arr[500002];

int lower_idx(int target)
{
	int st = 0;
	int en = n;
	while (st < en)
	{
		int mid = (st + en) / 2;
		if (arr[mid] >= target) en = mid;
		else st = mid+1;
	}
	return st;
}

int upper_idx(int target)
{
	int st = 0;
	int en = n;
	while (st < en)
	{
		int mid = (st + en) / 2;
		if (arr[mid] <= target) st = mid + 1;
		else en = mid;
	}
	return st;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);

	cin >> m;
	int target;
	while (m--)
	{
		cin >> target;
		cout << upper_idx(target) - lower_idx(target) << " ";
	}

	return 0;
}

//stl(array)
//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//
//int n,m;
//int arr[500002];
//
//int main()
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> n;
//	for (int i = 0; i < n; i++)
//		cin >> arr[i];
//
//	sort(arr, arr + n);
//
//	cin >> m;
//	while (m--)
//	{
//		int x;
//		cin >> x;
//		cout << upper_bound(arr, arr + n, x) - lower_bound(arr, arr + n, x) << " ";
//	}
//
//	return 0;
//}

//stl(vector)
//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//
//int n,m;
//vector<int> v;
//
//int main()
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> n;
//	int x;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> x;
//		v.push_back(x);
//	}
//
//	sort(v.begin(), v.end());
//
//	cin >> m;
//	while (m--)
//	{
//		int x;
//		cin >> x;
//		cout << upper_bound(v.begin(), v.end(), x) - lower_bound(v.begin(), v.end(), x) << " ";
//	}
//
//	return 0;
//}

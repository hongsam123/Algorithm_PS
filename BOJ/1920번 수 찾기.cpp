#include<iostream>
#include<algorithm>
using namespace std;

int n,m;
int arr[100002];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);

	cin >> m;
	int x;
	while (m--)
	{
		cin >> x;

		int st = 0;
		int en = n;
		int mid = (st + en) / 2;
		int ans = 0;

		while (st <= en)
		{
			if (arr[mid] == x)
			{
				ans = 1;
				break;
			}
			else if (arr[mid] > x)
				en = mid-1;
			else
				st = mid+1;
			
			mid = (st + en) / 2;
		}

		cout << ans << "\n";
	}


	return 0;
}

//stl »ç¿ë(binary_search)
//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//int n;
//int arr[100002];
//
//int main()
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> n;
//
//	for (int i = 0; i < n; i++)
//	{
//		cin >> arr[i];
//	}
//
//	sort(arr, arr + n);
//
//	int test;
//	cin >> test;
//
//	while (test--)
//	{
//		int x;
//		cin >> x;
//
//		if (binary_search(arr, arr + n, x))
//			cout << 1 << "\n";
//		else
//			cout << 0 << "\n";
//	}
//
//	return 0;
//} 

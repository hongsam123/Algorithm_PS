#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
int arr[500002];

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
		cout << binary_search(arr,arr+n,target) << " ";
	}

	return 0;
}

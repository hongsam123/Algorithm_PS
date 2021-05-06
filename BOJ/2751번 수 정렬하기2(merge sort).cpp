#include<iostream>
using namespace std;

int n = 10;
int arr[1000001];
int tmp[1000001];

void merge(int st, int en)
{
	int mid = (st + en) / 2;

	int a = st;
	int b = mid;
	for (int i = st; i < en; i++)
	{
		if (a == mid) tmp[i] = arr[b++];
		else if (b == en) tmp[i] = arr[a++];
		else if (arr[a] <= arr[b]) tmp[i] = arr[a++];
		else tmp[i] = arr[b++];
	}
	for (int i = st; i < en; i++)
		arr[i] = tmp[i];

	return;
}

void merge_sort(int st, int en)
{
	if (st + 1 == en) return;
	int mid = (st + en) / 2;
	merge_sort(st, mid);
	merge_sort(mid, en);
	merge(st, en);
}
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	merge_sort(0, n);
	for (int i = 0; i < n; i++) cout << arr[i] << "\n";

	return 0;
}

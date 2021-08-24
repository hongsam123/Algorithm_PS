#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
int arr[100002];
int ans = 0x7fffffff;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	//값을 정렬시킨다
	sort(arr,arr + n);

	int st = 0;
	int en = 0;
	while (1) {
		while (arr[en] - arr[st] < m) {
			en++;
			if (en >= n) break;
		}
		if (en >= n) break;
		ans = min(ans, arr[en] - arr[st]);

		st++;
		if (st == n) break;
	}

	cout << ans;

	return 0;
}

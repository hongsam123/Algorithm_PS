#include<iostream>
using namespace std;

int money[12];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	int cnt = 0;
	cin >> n >> k;

	for (int i = 0; i < n; i++)
		cin >> money[i];

	for (int i = n - 1; i >= 0; i--)
	{
		if (money[i] > k) continue;
		int x = k / money[i];
		k -= x * money[i];
		cnt += x;
		if (k == 0) break;
	}
	cout << cnt;

	return 0;
}

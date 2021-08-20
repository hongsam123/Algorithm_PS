#include<iostream>
#include<algorithm>
using namespace std;

int n;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int ans = -1;
	
	if (n < 5)
	{
		if (n % 3 == 0)
			ans = n / 3;
		else
			ans = -1;
	}
	else
	{
		for (int i = 0; i <= n; i += 5)
		{
			int cnt = 0;
			int five = i;
			int tmp = n - five;
			cnt += five / 5;

			if (tmp % 3 != 0)
				continue;
			else
				cnt += tmp / 3;

			if (ans == -1)
				ans = cnt;
			else
				ans = min(ans, cnt);
		}
	}
	
	cout << ans;

	return 0;
}

#include<iostream>
using namespace std;

int n;
long long m;
int arr[10002];
int ans;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
	
	int a = 0;
	int b = 0;
	long long sum = arr[0];

	while (1)
	{
		if (a == n)
			break;

		if (sum <= m)
		{
			if (sum == m)
			{
				ans++;
			}
			a++;
			sum += arr[a];
		}
		else
		{
			sum -= arr[b];
			b++;
		}
	}

	cout << ans;

	return 0;
}

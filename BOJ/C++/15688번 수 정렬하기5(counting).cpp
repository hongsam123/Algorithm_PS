#include<iostream>
using namespace std;

int n;
int cnt[2000004];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	int x;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		cnt[x + 1000000]++;
	}

	int total = 0;
	int a = 0;
	while (1)
	{
		if (total == n) break;
		if (cnt[a])
		{
			cout << a-1000000 << "\n";
			cnt[a]--;
			total++;
		}
		else
		{
			a++;
		}
	}

	return 0;
}


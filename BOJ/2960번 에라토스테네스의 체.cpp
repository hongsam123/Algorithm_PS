#include<iostream>
using namespace std;

int n, k;
bool eratos[1002];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	int a = 1;
	for (int i = 2; i <= n; i++)
	{
		if (eratos[i]) continue;
		eratos[i] = true;
		if (a == k)
		{
			cout << i;
			break;
		}
		a++;

		for (int j = i * i; j <= n; j += i)
		{
			if (eratos[j]) continue;
			eratos[j] = true;
			if (a == k)
			{
				cout << j;
				exit(0);
			}
			a++;
		}
	}

	return 0;
}

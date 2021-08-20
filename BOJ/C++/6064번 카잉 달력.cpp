#include<iostream>
using namespace std;

int t, M, N, x, y;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	while (t--)
	{
		bool posi = false;
		cin >> M >> N >> x >> y;
		if (M == x) x = 0;
		if (N == y) y = 0;
		for (int i = x; i <= M * N; i += M)
		{
			if (i % N == y)
			{
				cout << i << "\n";
				posi = true;
				break;
			}
		}
		if (!posi)
			cout << -1 << "\n";
	}

	return 0;
}

#include<iostream>
#include<algorithm>
using namespace std;

int m, n;
bool state[1000002];

void eratos(int num)
{
	fill(state, state + num + 1, true);
	state[1] = false;

	for (int i = 2; i * i <= num; i++)
	{
		if (state[i] == false) continue;
		for (int j = i * i; j <= num; j += i) state[j] = false;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n;

	eratos(n);

	for (int i = m; i <= n; i++)
	{
		if (state[i])
			cout << i << "\n";
	}

	return 0;
}

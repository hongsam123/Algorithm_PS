#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long a, b, ans;
const long long MAX = 10000000 + 1;
bool state[MAX];
vector<long long> prime;

void eratos()	//소수판별
{
	fill(state, state + MAX, true);
	state[1] = false;

	for (long long i = 2; i*i <  MAX; i++)
	{
		if (state[i] == false) continue;
		for (long long j = i * i; j < MAX; j += i) state[j] = false;
	}

	for (int i = 2; i < MAX; i++)
	{
		if (state[i]) prime.push_back(i);
	}

	return;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b;

	eratos();

	for (int i = 0; i < prime.size(); i++)
	{
		long long num = prime[i];
		while (prime[i] <= b / num)
			//여기서 if (prime[i] * num <= b) 을 하면 long long 범위를 벗어난다
		{
			if (prime[i] * num >= a)
				ans++;
			num *= prime[i];
		}
	}

	cout << ans;

	return 0;
}

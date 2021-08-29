#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long a, b, ans;
const long long MAX = 10000000 + 1;
bool state[MAX];
vector<long long> prime;

void eratos()	//�Ҽ��Ǻ�
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
			//���⼭ if (prime[i] * num <= b) �� �ϸ� long long ������ �����
		{
			if (prime[i] * num >= a)
				ans++;
			num *= prime[i];
		}
	}

	cout << ans;

	return 0;
}

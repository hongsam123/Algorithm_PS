#include<iostream>
#include<algorithm>
using namespace std;

int n;
int arr[102];
bool state[1002];

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

	cin >> n;
	int num = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		num = max(num, arr[i]);
	}

	eratos(num);

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int x = arr[i];
		if (state[x])
			ans++;
	}

	cout << ans;

	return 0;
}

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
bool state[4000002];
vector<int> v;
int ans;

void eratos(int num) {
	fill(state, state + num + 1, true);
	state[1] = false;

	for (int i = 2; i * i <= num; i++) {
		if (state[i] == false) continue;
		for (int j = i * i; j <= num; j += i) {
			state[j] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	if (n == 1) {
		cout << 0;
		return 0;
	}

	eratos(n);

	for (int i = 2; i <= n; i++) {
		if (state[i])
			v.push_back(i);
	}

	sort(v.begin(), v.end());

	int st = 0;
	int en = 0;

	int total = v[en];

	while (1) {
		while (total < n) {
			en++;
			if (en >= v.size()) break;
			else total += v[en];
		}
		//en이 범위를 벗어나면 종료
		if (en >= v.size()) break;

		if (total == n) ans++;

		total -= v[st];
		st++;
		if (st >= v.size()) break;
	}

	cout << ans;

	return 0;
}

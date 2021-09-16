#include<iostream>
using namespace std;

int n;
int s[10];
int w[10];
int ans;

void func(int k) {
	if (k == n) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] <= 0) cnt++;
		}
		ans = max(ans, cnt);
		return;
	}

	if (s[k] <= 0) func(k + 1);
	else {
		bool flag = false;
		for (int i = 0; i < n; i++) {
			if (i == k) continue;
			if (s[i] <= 0) continue;
			s[k] -= w[i];
			s[i] -= w[k];
			flag = true;
			func(k + 1);
			s[k] += w[i];
			s[i] += w[k];
		}
		if (!flag) func(n);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i] >> w[i];
	}

	func(0);

	cout << ans;

	return 0;
}

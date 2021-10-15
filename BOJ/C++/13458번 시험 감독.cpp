#include<iostream>
using namespace std;

int n;
int b, c;
int number[1000002];
int ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> number[i];
	}

	cin >> b >> c;

	for (int i = 0; i < n; i++) {
		number[i] -= b;
		ans++;
		if (number[i] > 0) {
			ans += ((number[i] / c));
			number[i] %= c;
			if (number[i]) ans++;
		}
	}

	cout << ans;

	return 0;
}

#include<iostream>
#define ll long long
using namespace std;

int k, n;
int lan[10002];

bool solve(ll x) {
	ll cur = 0;
	for (int i = 0; i < k; i++) {
		cur += lan[i] / x;
	}
	if (cur >= n) return true;
	else return false;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> k >> n;
	for (int i = 0; i < k; i++) cin >> len[i];
	ll st = 1;
	ll en = 0x7fffffff; // 2^31 - 1
	while (st < en) {
		ll mid = (st + en + 1) / 2;
		if (solve(mid)) st = mid;
		else en = mid - 1;
	}
	cout << st;
}

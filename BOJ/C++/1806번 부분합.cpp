#include<iostream>
#include<algorithm>
using namespace std;

int n, s;
int arr[100002];
int ans = 0x7fffffff;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int tot = arr[0];
	int st = 0;
	int en = 0;

	while (1) {
		while (tot < s) {
			en++;
			if (en >= n)break;
			else tot += arr[en];
		}
		if (en >= n) break;	//en이 범위를 벗어나면 종료

		ans = min(ans, en-st+1);	//수열의 길이를 구하는 부분

		tot -= arr[st];
		st++;
		if (st >= n) break;
	}

	if (ans == 0x7fffffff) cout << 0;	//합을 만드는 것이 불가능한 경우
	else cout << ans;

	return 0;
}

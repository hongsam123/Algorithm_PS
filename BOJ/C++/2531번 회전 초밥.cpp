#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

int n, d, k, c;
int dishes[60002];
int cnt_dishes[3002];
int ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> d >> k >> c;

	for (int i = 0; i < n; i++) {
		cin >> dishes[i];
	}

	for (int i = n; i < 2 * n; i++) {
		dishes[i] = dishes[i - n];
	}

	int st = 0;
	int en = 0;
	int cnt = 1;	//¸ÔÀ» ¼ö ÀÖ´Â ÃÊ¹äÀÇ °¡Áþ¼ö
	int tot = 1;	//¿¬¼ÓÀ¸·Î ¸Ô´Â ÃÑ °¹¼ö
	cnt_dishes[dishes[en]]++;


	while (1) {
		while (1) {
			if (tot < k) {
				en++;
				if (en >= 2 * n) break;
				if (cnt_dishes[dishes[en]]) {
					cnt_dishes[dishes[en]]++;
					tot++;
				}
				else {
					cnt_dishes[dishes[en]]++;
					tot++;
					cnt++;
				}
				if (cnt_dishes[c] == 0) {
					ans = max(ans, cnt + 1);
				}
				else ans = max(cnt, ans);
			}
			else break;
		}
		if (en >= 2 * n) break;

		cnt_dishes[dishes[st]]--;
		if (cnt_dishes[dishes[st]] == 0) cnt--;
		st++;
		tot--;

		if (st >= 2 * n) break;
	}
	cout << ans;

	return 0;
}

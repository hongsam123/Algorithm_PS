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
		if (en >= n) break;	//en�� ������ ����� ����

		ans = min(ans, en-st+1);	//������ ���̸� ���ϴ� �κ�

		tot -= arr[st];
		st++;
		if (st >= n) break;
	}

	if (ans == 0x7fffffff) cout << 0;	//���� ����� ���� �Ұ����� ���
	else cout << ans;

	return 0;
}

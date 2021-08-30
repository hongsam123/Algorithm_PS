#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int n, k;
int arr[1000002];
int ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	
	int st = 0;
	int en = 0;
	int cnt = 0;
	int ans = 0;
	queue<int> q;

	while (1) {
		while (1) {
			en++;
			if ((arr[en] % 2 == 1) || en > n) {
				break;
			}
			cnt++;
		}

		ans = max(ans, cnt);
		if (en > n) break;

		if (arr[en] % 2 == 1) {
			if (q.size() < k) {
				//���� k����ŭ Ȧ���� ������ �ʾ��� ��
				q.push(en);
			}
			else {
				//�̹� k����ŭ Ȧ���� ������ ��
				int cur = q.front(); q.pop();
				q.push(en);
				st = cur;
				cnt = en - st - q.size();
				ans = max(ans, cnt);
			}
		} 
		if (st > n)break;
	}

	cout << ans;

	return 0;
}

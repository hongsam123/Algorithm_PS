#include<iostream>
using namespace std;

int n, m, h;
bool ladder[12][32]; //ladder[i][j] : i, i+1 ��° ���μ��� �մ�
					 //j��° ���μ��� ���� �ϸ� true
int ans = -1;
bool flag;			//������ �����ϸ� �� ��� �����ϱ� ���� flag

bool check() {
	//i�� ���μ��� ����� i���� �������� Ȯ��
	for (int i = 1; i <= n; i++) {
		int result = i;
		for (int j = 1; j <= h; j++) {
			//������ �������� �������� �ִ��� Ȯ��
			if (ladder[result][j]) {
				//���������� ���� ���
				result++;
			}
			else if (ladder[result - 1][j]) {
				//�������� ���� ���
				result--;
			}
		}
		if (result != i) return false;
	}

	return true;
}

void func(int k,int x,int a) {
	//���μ��� k�� �߰����� �� ����� �� ���ϱ�
	//���� x�� �߰�
	if (x == k) {
		if (check()) {
			flag = true;
			ans = k;
		}
		return;
	}

	//����) �����ؼ� �� �� ����
	for (int i = 1; i < n; i++) {
		for (int j = a; j <= h; j++) {
			if (ladder[i][j]) continue;	//�̹� ���μ��� �ִ� ���
			if (ladder[i + 1][j] || ladder[i - 1][j]) continue;
			//�����ϴ� ���μ��� �ִ� ���
			
			ladder[i][j] = 1;
			func(k, x + 1,j);
			if (flag) return;
			ladder[i][j] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> h;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		ladder[b][a] = 1;
	}

	if (check()) {
		cout << 0;
		return 0;
	}
	for (int i = 1; i <= 3; i++) {
		func(i,0,0);
		if (flag) break;
	}

	cout << ans;

	return 0;
}

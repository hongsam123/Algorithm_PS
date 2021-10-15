#include<iostream>
using namespace std;

int n,k;
int durability[202];
bool robots[102];

void move() {
	//��Ʈ �̵�
	int x = durability[n * 2-1];
	for (int i = n * 2 - 2; i >= 0; i--) {
		durability[i + 1] = durability[i];
	}
	durability[0] = x;
	
	//�κ� �̵�
	if (robots[n - 1]) robots[n - 1] = 0;
	for (int i = n - 2; i >= 0; i--) {
		if (robots[i]) {
			robots[i + 1] = 1;
			robots[i] = 0;
		}
	}
}

void robot() {
	if (robots[n - 1]) robots[n - 1] = 0;
	for (int i = n - 2; i >= 0; i--) {
		if (robots[i]) {
			if (!(robots[i + 1]) && durability[i + 1]>=1) {
				robots[i + 1] = 1;
				robots[i] = 0;
				durability[i + 1]--;
			}
		}
	}
}

void upRobot() {
	if (durability[0]) {
		robots[0] = 1;
		durability[0]--;
	}
}

bool check() {
	int cnt = 0;
	for (int i = 0; i < 2 * n; i++) {
		if (durability[i] == 0) cnt++;
	}
	if (cnt >= k) return true;
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	for (int i = 0; i < 2 * n; i++) {
		cin >> durability[i];
	}

	int stage = 0;
	while (1) {
		stage++;

		//1. ��Ʈ�� �� ĭ ���� �ִ� �κ��� �Բ� �� ĭ ȸ���Ѵ�.
		move();

		//2. ���� ���� ��Ʈ�� �ö� �κ�����, ��Ʈ�� ȸ���ϴ� �������� �� ĭ �̵��� �� �ִٸ� �̵��Ѵ�. 
		//	 ���� �̵��� �� ���ٸ� ������ �ִ´�.
		robot();

		//3. �ø��� ��ġ�� �ִ� ĭ�� �������� 0�� �ƴϸ� �ø��� ��ġ�� �κ��� �ø���.
		upRobot();

		//4. �������� 0�� ĭ�� ������ K�� �̻��̶�� ������ �����Ѵ�. �׷��� �ʴٸ� 1������ ���ư���.
		if (check()) {
			break;
		}
	}
	
	cout << stage;

	return 0;
}

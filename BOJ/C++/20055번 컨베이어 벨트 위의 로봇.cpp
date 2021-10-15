#include<iostream>
using namespace std;

int n,k;
int durability[202];
bool robots[102];

void move() {
	//벨트 이동
	int x = durability[n * 2-1];
	for (int i = n * 2 - 2; i >= 0; i--) {
		durability[i + 1] = durability[i];
	}
	durability[0] = x;
	
	//로봇 이동
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

		//1. 벨트가 각 칸 위에 있는 로봇과 함께 한 칸 회전한다.
		move();

		//2. 가장 먼저 벨트에 올라간 로봇부터, 벨트가 회전하는 방향으로 한 칸 이동할 수 있다면 이동한다. 
		//	 만약 이동할 수 없다면 가만히 있는다.
		robot();

		//3. 올리는 위치에 있는 칸의 내구도가 0이 아니면 올리는 위치에 로봇을 올린다.
		upRobot();

		//4. 내구도가 0인 칸의 개수가 K개 이상이라면 과정을 종료한다. 그렇지 않다면 1번으로 돌아간다.
		if (check()) {
			break;
		}
	}
	
	cout << stage;

	return 0;
}

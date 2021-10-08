#include<iostream>
#include<algorithm>
using namespace std;

int board[10][10];
bool isused[10][10];	//isused[i][j] : i번째 행(가로줄)에서 j가 쓰였는지
bool isused2[10][10];	//isused2[i][j] : i번째 열(세로줄)에서 j가 쓰였는지
bool isused3[10][10];	//isused3[i][j] : i번째 사각형 안에 j가 쓰였는지

int getNum(int x, int y) {
	if (x < 3) {
		if (y < 3) return 1;
		else if (y < 6) return 2;
		else return 3;
	}
	else if (x < 6) {
		if (y < 3) return 4;
		else if (y < 6) return 5;
		else return 6;
	}
	else {
		if (y < 3) return 7;
		else if (y < 6) return 8;
		else return 9;
	}
}

void func(int line, int k) {
	//line번째 줄의 k번째 수를 채우는 함수
	if (line == 9) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << board[i][j] << " ";
			}
			cout << "\n";
		}
		exit(0);
	}

	if (board[line][k]) {
		//이미 수가 채워진 칸
		if (k == 8) func(line + 1, 0);
		else func(line, k + 1);
	}
	else {
		for (int i = 1; i <= 9; i++) {
			if (isused[line][i]) continue;
			if (isused2[k][i]) continue;
			if (isused3[getNum(line, k)][i]) continue;
			
			isused[line][i] = 1;
			isused2[k][i] = 1;
			isused3[getNum(line, k)][i] = 1;

			board[line][k] = i;
			if (k == 8)func(line + 1, 0);
			else func(line, k + 1);

			board[line][k] = 0;
			isused[line][i] = 0;
			isused2[k][i] = 0;
			isused3[getNum(line, k)][i] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> board[i][j];
			isused[i][board[i][j]] = 1;
			isused2[j][board[i][j]] = 1;
			isused3[getNum(i,j)][board[i][j]] = 1;
		}
	}

	func(0, 0);

	return 0;
}

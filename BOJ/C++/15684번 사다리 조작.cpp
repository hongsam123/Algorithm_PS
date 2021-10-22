#include<iostream>
using namespace std;

int n, m, h;
bool ladder[12][32]; //ladder[i][j] : i, i+1 번째 세로선을 잇는
					 //j번째 가로선이 존재 하면 true
int ans = -1;
bool flag;			//조건을 만족하면 그 즉시 종료하기 위한 flag

bool check() {
	//i번 세로선의 결과가 i번이 나오는지 확인
	for (int i = 1; i <= n; i++) {
		int result = i;
		for (int j = 1; j <= h; j++) {
			//밑으로 내려가다 가로줄이 있는지 확인
			if (ladder[result][j]) {
				//오른쪽으로 가는 경우
				result++;
			}
			else if (ladder[result - 1][j]) {
				//왼쪽으로 가는 경우
				result--;
			}
		}
		if (result != i) return false;
	}

	return true;
}

void func(int k,int x,int a) {
	//가로선을 k개 추가했을 때 경우의 수 구하기
	//현재 x개 추가
	if (x == k) {
		if (check()) {
			flag = true;
			ans = k;
		}
		return;
	}

	//주의) 연속해서 갈 수 없음
	for (int i = 1; i < n; i++) {
		for (int j = a; j <= h; j++) {
			if (ladder[i][j]) continue;	//이미 가로선이 있는 경우
			if (ladder[i + 1][j] || ladder[i - 1][j]) continue;
			//연속하는 가로선이 있는 경우
			
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

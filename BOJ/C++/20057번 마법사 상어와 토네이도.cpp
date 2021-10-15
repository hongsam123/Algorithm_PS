#include<iostream>
#include<cmath>
using namespace std;

int n;
int ans;
int board[501][501];
double percentage[5][5] = {
	{0,0,0.02,0,0},
	{0,0.1,0.07,0.01,0},
	{0.05,0.45,0,0,0},
	{0,0.1,0.07,0.01,0},
	{0,0,0.02,0,0}
};
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

int getLeftSand(int sand) {
	return sand - (floor(sand * 0.01) * 2
		+ floor(sand * 0.02) * 2
		+ floor(sand * 0.07) * 2
		+ floor(sand * 0.1) * 2
		+ floor(sand * 0.05) );
}

void rotatePercentage() {
	//�ݽð�������� 90�� ȸ��
	double tmp_percentage[5][5];
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			tmp_percentage[i][j] = percentage[i][j];
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			percentage[5-1-j][i] = tmp_percentage[i][j];
		}
	}
}

void moveSand(int x,int y) {
	int sand = board[x][y];
	board[x][y] = 0;

	if (sand == 0)
		return;

	for (int i = -2; i <= 2; i++) {
		for (int j = -2; j <= 2; j++) {
			double percent =  percentage[i + 2][j + 2];
			if (percent == 0) continue;

			int moveSand;
			if (percent < 0.4) {
				//���İ� �ƴѰ��
				moveSand = floor(sand*percent);
			}
			else {
				//������ ���
				moveSand = getLeftSand(sand);
			}

			int nx = x + i;
			int ny = y + j;

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
				ans += moveSand;
			}
			else {
				board[nx][ny] += moveSand;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	int x = n / 2;
	int y = n / 2;
	int cnt = 1;
	int dir = 0;

	while (1) {
		for (int i = 0; i < 2; i++) {
			//�ι��� ������ ����ŭ ����
			for (int j = 0; j < cnt; j++) {
				//�̵�
				x += dx[dir];
				y += dy[dir];

				//���̵�
				moveSand(x,y);

				//0,0�̸� Ż��
				if (x == 0 && y == 0) {
					cout << ans;
					return 0;
				}
			}

			//���� ��ȯ
			dir++;
			if (dir > 3) dir = 0;
			rotatePercentage();
		}
		cnt++;
	}
}

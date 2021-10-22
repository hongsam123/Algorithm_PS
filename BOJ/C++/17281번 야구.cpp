#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define pii pair<int,int>
using namespace std;

int n;
int inning[52][10];	//inning[i][j] : i�� �̴�(����)���� j�� ������ �ϴ� ��
vector<int> order;
bool isused[10];
int ans;

void getAns() {
	int score = 0;				//����
	int player_i = 0;			//���� ������ �� ����
	int player = order[player_i];		//Ÿ��
	int round = 0;				//����(�̴�)(1~n)
	int out_ = 0;				//�ƿ� Ƚ��
	int base[4];		//0�̸� ����� ���� 1�̸� ����

	while (1) {
		round++;
		if (round > n) break;
		for (int i = 1; i <= 3; i++) base[i] = 0;
		out_ = 0;

		while (1) {
			int result = inning[round][player];
			if (result == 1) {
				//��Ÿ

				for (int i = 3; i >= 1; i--) {
					if (base[i]) {
						if (i == 3) {
							base[i] = 0;
							score++;
						}
						else {
							base[i + 1] = 1;
							base[i] = 0;
						}
					}
				}
				base[1] = 1;
			}
			else if (result == 2) {
				//2��Ÿ
				for (int i = 3; i >= 1; i--) {
					if (base[i]) {
						if (i == 3 || i==2) {
							base[i] = 0;
							score++;
						}
						else {
							base[i + 2] = 1;
							base[i] = 0;
						}
					}
				}
				base[2] = 1;
			}
			else if (result == 3) {
				//3��Ÿ
				for (int i = 3; i >= 1; i--) {
					if (base[i]) {
						base[i] = 0;
						score++;
					}
				}
				base[3] = 1;
			}
			else if (result == 4) {
				//Ȩ��
				for (int i = 3; i >= 1; i--) {
					if (base[i]) {
						base[i] = 0;
						score++;
					}
				}
				score++;
			}
			else {
				//�ƿ�
				out_++;
			}
			if (out_ == 3) { 
				player_i++;
				if (player_i == 9) player_i = 0;
				player = order[player_i];
				break; 
			}
			
			player_i++;
			if (player_i == 9) player_i = 0;
			player = order[player_i];
		}
	}

	ans = max(ans, score);
}

void func(int k) {
	//k�� Ÿ�ڸ� ���ϴ� �Լ�
	if (k == 9) {
		getAns();
		return;
	}

	if (k == 3) {
		order.push_back(1);
		isused[1] = 1;
		func(k + 1);

		order.pop_back();
		isused[1] = 0;
	}
	else {
		for (int i = 2; i <= 9; i++) {
			if (isused[i]) continue;
			isused[i] = 1;
			order.push_back(i);
			func(k + 1);

			order.pop_back();
			isused[i] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(0); 
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 9; j++) {
			cin >> inning[i][j];
		}
	}

	func(0);

	cout << ans;

	return 0;
}

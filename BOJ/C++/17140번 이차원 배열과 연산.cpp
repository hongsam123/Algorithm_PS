#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#define pii pair<int,int>
using namespace std;

int r, c, k;
int board[102][102];
int tmp[102][102];
int x, y;
map<int, int> m;	// <수, 수 등장 횟수>

bool comp(pii a, pii b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

void copy() {
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			board[i][j] = tmp[i][j];
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c >> k;

	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> board[i][j];
		}
	}

	x = 3;
	y = 3;

	if (board[r][c] == k) {
		cout << 0;
		return 0;
	}

	int cnt = 0;
	while (1) {
		cnt++;
		if (cnt > 100) break;

		int tmpX = 0;
		int tmpY = 0;

		for (int i = 1; i <= 100; i++) {
			fill(tmp[i], tmp[i] + 101, 0);
		}

		if (x >= y) {
			//R연산
			for (int i = 1; i <= x; i++) {
				//모든 행에 대해 연산 수행
				m.clear();
				for (int j = 1; j <= y; j++) {
					if (board[i][j] == 0) continue;
					m[board[i][j]]++;
				}

				vector<pii> v(m.begin(), m.end());
				sort(v.begin(), v.end(), comp);

				int k = 1;
				for (auto e : v) {
					tmp[i][k] = e.first;
					tmp[i][++k] = e.second;
					if (k == 100) {
						tmpY = 100;
						break; 
					}
					tmpY = max(tmpY, k);
					k++;
				}
			}
			tmpX = x;
		}
		else {
			//C연산
			
			for (int i = 1; i <= y; i++) {
				m.clear();
				for (int j = 1; j <= x; j++) {
					if (board[j][i] == 0) continue;
					m[board[j][i]]++;
				}

				vector<pii> v(m.begin(), m.end());
				sort(v.begin(), v.end(), comp);

				int k = 1;
				for (auto e : v) {
					tmp[k][i] = e.first;
					tmp[++k][i] = e.second;
					if (k == 100) {
						tmpX = 100;
						break;
					}
					tmpX = max(tmpX, k);
					k++;
				}
			}
			tmpY = y;
		}

		x = tmpX;
		y = tmpY;

		copy();

		if (board[r][c] == k) {
			cout << cnt;
			return 0;
		}
	}

	cout << -1;

	return 0;
}

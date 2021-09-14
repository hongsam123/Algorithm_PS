#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n, m, t;
vector<vector<int>> board;

bool remove() {
	bool rem = false;

	vector<vector<int>> tmp;
	for (int i = 0; i < n; i++) {
		vector<int> v;
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0) {
				v.push_back(0);
				continue; }
			bool flag = false;
			//같은 원판에서 인접
			if (j == 0) {
				if (board[i][j] == board[i][1] || board[i][j] == board[i][m - 1]) {
					v.push_back(0);
					if (!rem) rem = true;
					if (!flag) flag = true;
				} 
			}
			else if (j == m - 1) {
				if (board[i][j] == board[i][0] || board[i][j] == board[i][m - 2]) {
					v.push_back(0);
					if (!rem) rem = true;
					if (!flag) flag = true;
				}
			}
			else {
				if (board[i][j] == board[i][j-1] || board[i][j] == board[i][j+1]) {
					v.push_back(0);
					if (!rem) rem = true;
					if (!flag) flag = true;
				}
			}
			if (flag) continue;

			//다른 원판과 인접한지 확인
			if (i == 0) {
				if (board[i][j] == board[1][j]) {
					v.push_back(0);
					if (!rem) rem = true;
					if (!flag) flag = true;
				}
			}
			else if (i == n - 1) {
				if (board[i][j] == board[n - 2][j]) {
					v.push_back(0);
					if (!rem) rem = true;
					if (!flag) flag = true;
				}
			}
			else {
				if (board[i][j] == board[i - 1][j] || board[i][j] == board[i + 1][j]) {
					v.push_back(0);
					if (!rem) rem = true;
					if (!flag) flag = true;
				}
			}
			//인접하지 않았으면(삭제되지 않았으면) 원래 수 넣기
			if (!flag) v.push_back(board[i][j]);
		}
		tmp.push_back(v);
	}
	board = tmp;

	return rem;
}

void avg() {
	int total = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			total += board[i][j];
			if (board[i][j]) cnt++;
		}
	}
	double avgerage = (double)total / cnt;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			double nx = board[i][j];
			if (board[i][j] == 0) continue;
			if (nx > avgerage) board[i][j]--;
			if (nx < avgerage) board[i][j]++;
		}
	}

	return;
}

int getTotal() {
	int total = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			total += board[i][j];
		}
	}
	return total;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> t;

	for (int i = 0; i < n; i++) {
		vector<int> v;
		for (int j = 0; j < m; j++) {
			int x;
			cin >> x;
			v.push_back(x);
		}
		board.push_back(v);
	}

	while (t--) {
		int x, d, k;
		cin >> x >> d >> k;
		if (d == 0) {
			//시계방향

			//회전
			for (int i = x-1; i < n; i += x) {
				vector<int> tmp;
				for (int j = 0; j < m; j++) {
					int idx = j - k;
					while (idx < 0) idx += m;
					tmp.push_back(board[i][idx]);
				}
				board[i].clear();
				for (int j = 0; j < m; j++) {
					board[i].push_back(tmp[j]);
				}
			}
		}
		else {
			//반시계방향

			//회전
			for (int i = x-1; i < n; i += x) {
				vector<int> tmp;
				for (int j = 0; j < m; j++) {
					int idx = j + k;
					while (idx >= m) idx -= m;
					tmp.push_back(board[i][idx]);
				}
				board[i].clear();
				for (int j = 0; j < m; j++) {
					board[i].push_back(tmp[j]);
				}
			}
		}

		//인접한 것 삭제
		if (!remove()) {
			//인접해서 삭제한것이 없는 경우
			avg();
			//평균을 구해서 +1,-1
		}
	}

	cout << getTotal();

	return 0;
}

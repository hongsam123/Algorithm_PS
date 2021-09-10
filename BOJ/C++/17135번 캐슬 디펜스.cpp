#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define X first
#define Y second
#define pii pair<int,int>
using namespace std;

int n, m, d;
int b[17][17];
int board[17][17];
int tmp[17][17];
bool isused[17];	//�ü� ��ġ�� ��Ʈ��ŷ�� ���� �迭
vector<pii> archer;	//�ü� ��ġ
int eneymy_num;
int ans;
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };
bool visited[17][17];

int getDist(pii a, pii b) {
	return abs(a.X - b.X) + abs(a.Y - b.Y);
}

void solution() {
	int cnt = 0;
	int enNum = eneymy_num;
	vector<pii> e;	//������ �ü��� ������ ���� ��ġ ����

	while (enNum) {
		//bfs : �ü��� �� ����

		//�� �ü��� ������ �� ����
		for (int p = 0; p < 3; p++) {
			queue<pii> q;
			for (int i = 0; i < n; i++)
				fill(visited[i], visited[i] + m, false);

			auto cur = archer[p];
			visited[cur.X][cur.Y] = 1;
			q.push({ cur.X,cur.Y });
			while (!q.empty()) {
				auto cur = q.front(); q.pop();
				if (board[cur.X][cur.Y]) {
					//���� ����� �� �߰�
					//�Ÿ� �˻� �� �����ϸ� break; 
					if (getDist(archer[p], cur) <= d) {
						e.push_back({ cur.X,cur.Y });
						break;
					}
				}
				if (getDist(cur, archer[p]) > d) continue;

				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (visited[nx][ny]) continue;
					visited[nx][ny] = 1;
					q.push({ nx,ny });
				}
			}
		}

		//�� ����
		for (auto x : e) {
			if (board[x.X][x.Y]) {
				board[x.X][x.Y] = 0;
				enNum--;
				cnt++;
			}
			//��ĥ �� �ִ�
		}
		e.clear();

		if (enNum == 0) break;

		//���� �Ʒ��� ��ĭ �̵�, �� ��ġ ����
		for (int i = 0; i < n; i++)
			fill(tmp[i], tmp[i] + m, 0);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 1) {
					if (i + 1 >= n) {
						enNum--;
						continue;
					}
					else tmp[i + 1][j] = 1;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				board[i][j] = tmp[i][j];
		}
	}
	
	ans = max(ans, cnt);

	return;
}

//�ü� ��ġ�� ����� ��
void func(int x, int k) {
	//k��° �ü� ��ġ
	if (k == 3) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				board[i][j] = b[i][j];
			}
		}
		solution();
		return;
	}

	for (int i = x; i < m; i++) {
		if (isused[i]) continue;
		isused[i] = true;
		archer.push_back({ n,i });
		func(i + 1, k + 1);

		isused[i] = false;
		archer.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> d;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> b[i][j];
			if(b[i][j])
				eneymy_num++;
		}
	}

	func(0,0);

	cout << ans;

	return 0;
}

#include<iostream>
#include<algorithm>
#include<vector>
#define pii pair<int,int>
#define X first
#define Y second
using namespace std;

int n, m;
int board[52][52];
int tmp[52][52];
vector<pii> cloud;
int dx[9] = {0,0,-1,-1,-1,0,1,1,1};	//1������ ��, ��, ��, ��, ��, ��, ��, ��
int dy[9] = {0,-1,-1,0,1,1,1,0,-1};

void move(int d, int s) {
	for (int i = 0; i < cloud.size(); i++) {
		auto cur = cloud[i];
		int nx = cur.X;
		int ny = cur.Y;
		for (int j = 0; j < s; j++) {
			nx += dx[d];
			ny += dy[d];
			if (nx < 0) nx = n - 1;
			if (nx >= n) nx = 0;
			if (ny < 0) ny = n - 1;
			if (ny >= n) ny = 0;
		}
		cloud[i] = { nx,ny };
	}
}

void rain() {
	for (auto e : cloud) {
		board[e.X][e.Y]++;
	}
}

void copy() {
	for (auto e : cloud) {
		int cnt = 0;
		for (int dir = 2; dir < 9; dir += 2) {
			//��, ��, ��, ��
			int nx = e.X + dx[dir];
			int ny = e.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (board[nx][ny]) cnt++;
		}
		board[e.X][e.Y] += cnt;
	}
}

void newCloud() {
	//tmp �ʱ�ȭ
	for (int i = 0; i < n; i++)
		fill(tmp[i], tmp[i] + n + 1, 0);

	//cloud�� ���鼭 tmp�� ǥ��
	for (int i = 0; i < cloud.size(); i++) {
		auto cur = cloud[i];
		tmp[cur.X][cur.Y] = 1;
	}

	//cloud �ʱ�ȭ
	cloud.clear();

	//�� cloud �߰�
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] >= 2 && !tmp[i][j]) {
				cloud.push_back({ i,j });
				board[i][j] -= 2;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	cloud.push_back({ n - 1,0 });
	cloud.push_back({ n - 1,1 });
	cloud.push_back({ n - 2,0 });
	cloud.push_back({ n - 2,1 });

	while (m--) {
		int d, s;
		cin >> d >> s;

		//1. ��� ������ di �������� siĭ �̵��Ѵ�.
		move(d, s);

		//2. �� �������� �� ���� ������ �ִ� ĭ�� �ٱ��Ͽ� ����� ���� ���� 1 �����Ѵ�.
		rain();

		//3. ������ ��� �������.

		//4. 2���� ���� ������ ĭ (r, c)�� ��������� ������ �����Ѵ�.
		copy();

		//5. �ٱ��Ͽ� ����� ���� ���� 2 �̻��� ��� ĭ�� ������ �����, ���� ���� 2 �پ���.
		newCloud();
	}

	int ans = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans += board[i][j];
		}
	}

	cout << ans;

	return 0;
}

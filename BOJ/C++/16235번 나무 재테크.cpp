#include<iostream>
#include<queue>
#include<tuple>
#include<algorithm>
#include<vector>
#define tii tuple<int,int,int>
using namespace std;

int n, m, k;
int board[12][12];	//양분
int a[12][12];
deque<tii> trees; //<나이,x,y>
//vector<tii> alive;
vector<tii> dead;
int dx[8] = { -1,-1,-1,0,0,1,1,1 };
int dy[8] = { -1,0,1,-1,1,-1,0,1 };

void spring()
{
	int size = trees.size();
	for (int i = 0; i < size; i++) {
		auto cur = trees.front(); trees.pop_front();

		int age = get<0>(cur);
		int x = get<1>(cur);
		int y = get<2>(cur);

		if (board[x][y] >= age) {
			board[x][y] -= age;
			trees.push_back({ age + 1,x,y });
		}
		else {
			dead.push_back(cur);
		}
	}
}

void summer() {
	for (auto cur : dead) {
		int age = get<0>(cur);
		int x = get<1>(cur);
		int y = get<2>(cur);
		board[x][y] += age / 2;
	}
	dead.clear();
}

void fall() {
	vector<tii> tmp;
	for (auto cur : trees) {
		int age = get<0>(cur);
		int x = get<1>(cur);
		int y = get<2>(cur);

		if (age % 5) continue;

		for (int dir = 0; dir < 8; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx<1 || ny<1 || nx>n || ny>n) continue;
			tmp.push_back({ 1,nx,ny });
		}
	}
	for (auto cur : tmp)
		trees.push_front(cur);
}

void winter() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			board[i][j] += a[i][j];
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;

	//각 칸에 추가되는 양분 값 입력
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}

	//나무의 정보 입력
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		trees.push_back({ z,x,y });
	}

	for (int i = 1; i <= n; i++)
		fill(board[i], board[i] + n + 1, 5);
	sort(trees.begin(), trees.end());

	while (k--) {
		spring();
		summer();
		fall();
		winter();
	}

	cout << trees.size();

	return 0;
}

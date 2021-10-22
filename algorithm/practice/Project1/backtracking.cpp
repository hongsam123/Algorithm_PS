//boj15649 N�� M(1)
//boj15650 N�� M(2)
//boj15651 N�� M(3)
//boj15652 N�� M(4)
//boj15654 N�� M(5)
//boj15655 N�� M(6) (next_permutation)
//boj12101 1,2,3 ���ϱ� 2
//boj9663 N-Queen
//boj1182 �κм����� ��
// (�ٸ�Ǯ��)
// �� ���� ������ ������ ����ϸ� ��� �κм����� �� ���°��� Ʈ���� �׸��ٰ� ����
// �ð� ���⵵�� O(n^2) 
//boj18428 ���� ���ϱ�
//boj15656 N�� M(7)
//boj6603 �ζ�
//boj1759 ��ȣ�����
//���α׷��ӽ� 2021 īī�� ����ε� �޴�������
//boj16987 ������� ���ġ��
//boj2580 ������
//boj2023 �ű��� �Ҽ�
//boj7490 0 �����
//boj15684 ��ٸ� ����
//boj1941 �ҹ��� ĥ����
//#include<iostream>
//#include<vector>
//#include<map>
//#include<set>
//#include<algorithm>
//#define X first
//#define Y second
//#define pii pair<int,int>
//using namespace std;
//
//int dx[4] = { 1,0,-1,0 };
//int dy[4] = { 0,1,0,-1 };
//char board[7][7];
//bool isused[7][7];
//set<vector<pii>> ans;
//vector<pii> sevenP;
//
//bool check() {
//	int cnt = 0;
//	for (auto e : sevenP) {
//		if (board[e.X][e.Y] == 'S') cnt++;
//	}
//	if (cnt >= 4) return true;
//	else return false;
//}
//
//void dfs(int x,int y) {
//	if (sevenP.size() == 7) {
//		if (check()) {
//			vector<pii> tmp;
//			for (auto e : sevenP) {
//				//cout << e.first << " " << e.second << "\n";
//				tmp.push_back(e);
//			}
//			sort(tmp.begin(), tmp.end());
//			ans.insert(tmp);
//			return;
//		}
//		else return;
//	}
//
//	for (int dir = 0; dir < 4; dir++) {
//		int nx = x + dx[dir];
//		int ny = y + dy[dir];
//		if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
//		if (isused[nx][ny]) continue;
//		isused[nx][ny] = 1;
//		sevenP.push_back({ nx,ny });
//		dfs(nx,ny);
//		isused[nx][ny] = 0;
//		sevenP.pop_back();
//	}
//}
//
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	for (int i = 0; i < 5; i++) {
//		string line;
//		cin >> line;
//		for (int j = 0; j < 5; j++) {
//			board[i][j] = line[j];
//		}
//	}
//
//	for (int i = 0; i < 5; i++) {
//		for (int j = 0; j < 5; j++) {
//			isused[i][j] = 1;
//			sevenP.push_back({ i,j });
//			dfs(i, j);
//			sevenP.pop_back();
//			isused[i][j] = 0;
//		}
//	}
//
//	for (auto e : ans) {
//		for (auto x : e) {
//			cout << x.X << " " << x.Y << "\n";
//		}
//		cout << "\n";
//	}
//
//	cout << ans.size();
//
//	return 0;
//}
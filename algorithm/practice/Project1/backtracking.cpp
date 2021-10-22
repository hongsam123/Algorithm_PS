//boj15649 N과 M(1)
//boj15650 N과 M(2)
//boj15651 N과 M(3)
//boj15652 N과 M(4)
//boj15654 N과 M(5)
//boj15655 N과 M(6) (next_permutation)
//boj12101 1,2,3 더하기 2
//boj9663 N-Queen
//boj1182 부분수열의 합
// (다른풀이)
// 각 수를 더할지 말지를 고려하며 모든 부분수열의 합 상태공간 트리를 그린다고 생각
// 시간 복잡도는 O(n^2) 
//boj18428 감시 피하기
//boj15656 N과 M(7)
//boj6603 로또
//boj1759 암호만들기
//프로그래머스 2021 카카오 블라인드 메뉴리뉴얼
//boj16987 계란으로 계란치기
//boj2580 스도쿠
//boj2023 신기한 소수
//boj7490 0 만들기
//boj15684 사다리 조작
//boj1941 소문난 칠공주
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
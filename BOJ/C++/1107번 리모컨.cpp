//#include<iostream>
//#include<string>
//using namespace std;
//
//int n, m;
//string str, tmp;
//bool notWorking[12];
//int ans;
//
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> n >> m;
//
//	for (int i = 0; i < m; i++) {
//		int x;
//		cin >> x;
//		notWorking[x] = 1;
//	}
//
//	if (n == 100) {
//		cout << 0;
//		return 0;
//	}
//	if (m == 10) {
//		cout << abs(n - 100);
//		return 0;
//	}
//
//	str = to_string(n);
//	
//	for (int i = 0; i < str.size();  i++) {
//		if (notWorking[str[i]-'0']) {
//			//고장난 번호
//			int x = str[i]-'0';
//			while (notWorking[x]) {
//				x++;
//				if (x > 9)break;
//			}
//			char tmp_up = x + '0';
//
//			x = str[i]-'0';
//			while (notWorking[x]) {
//				x--;
//				if (x < 0) break;
//			}
//			char tmp_down = x + '0';
//
//			if (tmp_up-'0' > 9) tmp += tmp_down;
//			else if (tmp_down - '0' < 0) tmp += tmp_up ;
//			else {
//				if (abs(str[i] - tmp_up) < abs(str[i] - tmp_down)) {
//					tmp += tmp_up;
//				}
//				else {
//					tmp += tmp_down;
//				}
//			}
//		}
//		else {
//			tmp += str[i];
//		}
//		ans++;
//	}
//
//	ans += abs(n - stoi(tmp));
//
//	cout<<ans;
//
//	return 0;
//}
//#include<iostream>
//#include<string>
//using namespace std;
//
//int n, m;
//bool notWorking[12];
//int x = -1; //+/-하기 전 누를 번호
//int ans;
//
//void dfs(int cur,int op) {
//	//op가 1이면 +, -1이면 -
//	//cout << cur << "\n";
//
//	if (cur < 0) return;
//
//	string str = to_string(cur);
//	bool posi = true;
//	for (int i = 0; i < str.size(); i++) {
//		char a = str[i];
//		int a_int = a - '0';
//		if (notWorking[a_int]) {
//			posi = false;
//			break;
//		}
//	}
//	if (posi) {
//		if (x == -1) {
//			x = cur;
//		}
//		else {
//			if (abs(cur - n) < abs(x - n))
//				x = cur;
//		}
//	}
//	else {
//		if (op == 1) dfs(cur + 1, 1);
//		else dfs(cur - 1, -1);
//	}
//}
//
//int main() {
//	ios::sync_with_stdio;
//	cin.tie(0);
//
//	cin >> n >> m;
//
//	for (int i = 0; i < m; i++) {
//		int x;
//		cin >> x;
//		notWorking[x] = 1;
//	}
//
//	if (n == 100) {
//		cout << 0;
//		return 0;
//	}
//	if (m == 10) {
//		cout << abs(n - 100);
//		return 0;
//	}
//
//	dfs(n-1, -1);
//	//dfs(n + 1, 1);
//
//	string str = to_string(x);
//	ans += str.size();
//	ans += abs(n - x);
//
//	cout << ans;
//
//	return 0;
//}

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int n, m;
bool notWorking[12];
int ans;

bool check(int x) {
	string str = to_string(x);

	for (int i = 0; i < str.size(); i++) {
		int num = str[i]-'0';
		if (notWorking[num]) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio;
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		notWorking[x] = 1;
	}

	if (n == 100) {
		cout << 0;
		return 0;
	}
	if (m == 10) {
		cout << abs(n - 100);
		return 0;
	}
	int number;

	if (check(n)) {
		number = n;
	}
	else {
		int up_n = n + 1;
		int down_n = n - 1;
		while (1) {
			if (check(up_n)) {
				number = up_n;
				if(check(down_n)) {
					if (to_string(up_n).size() > to_string(down_n).size())
						number = down_n;
				}
				break;
			} 
			else {
				up_n++;
				if (down_n < 0) continue;
				if (check(down_n)) {
					number = down_n;
					break;
				}
				else {
					down_n--;
				}
			}
		}
	}

	int a = abs(100 - n);
	//100에서 +/-로만 이동하는 횟수
	int b = to_string(number).size() + abs(n - number);
	//가능한 수 중 가장 가까운 수를 찍고  +/-로 이동

	cout << min(a,b);

	return 0;
}


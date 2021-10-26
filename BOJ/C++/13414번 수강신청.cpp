#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

int n, k;
map<string, int> m;
vector<pair<int, string>> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	for (int i = 1; i <= k; i++) {
		string x;
		cin >> x;
		m[x] = i;
	}
	for (auto e : m) {
		v.push_back({ e.second,e.first });
	}

	sort(v.begin(), v.end());
	int cnt = 0;
	for (auto e : v) {
		cnt++;
		cout << e.second << "\n";
		if (cnt == n) break;
	}
	return 0;
}

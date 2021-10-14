#include<iostream>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;

int t, a, b;
bool visited[10002];
queue<int> q;
string pre[10002];

int func(int x, int op) {
	if (op == 0) {
		//D연산
		x = (x * 2) % 10000;
	}
	else if (op == 1) {
		//S연산
		if (x == 0) x = 9999;
		else x = x - 1;
	}
	else if (op == 2) {
		//L연산

		int d1 = x / 1000;
		x %= 1000;
		int d2 = x / 100;
		x %= 100;
		int d3 = x / 10;
		x %= 10;
		int d4 = x;

		x = d2 * 1000 + d3 * 100 + d4 * 10 + d1;
	}
	else {
		//R연산

		int d1 = x / 1000;
		x %= 1000;
		int d2 = x / 100;
		x %= 100;
		int d3 = x / 10;
		x %= 10;
		int d4 = x;

		x = d4 * 1000 + d1 * 100 + d2 * 10 + d3;
	}
	return x;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	while (t--) {
		cin >> a >> b;
		fill(visited, visited + 10000, 0);
		fill(pre, pre + 10000, "");

		q.push(a);
		visited[a] = 1;

		while (!q.empty()) {
			int cur = q.front(); q.pop();

			if (cur == b) {
				cout << pre[b] << "\n";
				while (!q.empty()) q.pop();
				break;
			}

			for (int dir = 0; dir < 4; dir++) {
				int nxt = func(cur, dir);
				if (visited[nxt]) continue;
				visited[nxt] = 1;
				
				if (dir == 0) pre[nxt] = pre[cur] + "D";
				else if(dir==1) pre[nxt] = pre[cur] + "S";
				else if (dir == 2) pre[nxt] = pre[cur] + "L";
				else  pre[nxt] = pre[cur] + "R";
				q.push(nxt);
			}
		}
	}

	return 0;
}

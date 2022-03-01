#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int n, m;
int a, b;
int arr[102][102];
queue<int> q;
int visited[102];
int depth[102];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> a >> b >> m;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		arr[x][y] = 1;
		arr[y][x] = 1;
	}


	q.push(a);

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int i = 1; i <= n; i++) {
			if (!visited[i] && arr[cur][i]) {
				visited[i] = 1;
				depth[i] = depth[cur] + 1;
				q.push(i);
			}
		}
	}

	if (depth[b] == 0)
		cout << -1;
	else
		cout << depth[b];


	return 0;
}

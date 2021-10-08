#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int n;
vector<int> adj[12];
int population[12];
int area[12];
int visited[12];
queue<int> q;
int ans = -1;

void getAns() {
	int atotal = 0;
	int btotal = 0;

	for (int i = 1; i <= n; i++) {
		if (visited[i] == 1) atotal += population[i];
		else if (visited[i] == 2) btotal += population[i];
	}
	if (ans == -1) ans = abs(atotal - btotal);
	else ans = min(ans, abs(atotal-btotal));
}

bool check() {
	fill(visited, visited + n + 1, 0);

	//a구역 bfs
	for (int i = 1; i <= n; i++) {
		if (area[i]) {
			q.push(i);
			visited[i] = 1;
			break;
		}
	}

	while (!q.empty()) {
		int cur = q.front(); q.pop();

		for (int nxt : adj[cur]) {
			if (area[nxt] != 1) continue;	//a구역이 아니라면 continue
			if (visited[nxt]) continue;		//a구역이 맞지만 이미 방문했다면 continue;
			q.push(nxt);
			visited[nxt] = 1;
		}
	}

	//b구역 bfs
	for (int i = 1; i <= n; i++) {
		if (area[i] == 0) {
			q.push(i);
			visited[i] = 2;
			break;
		}
	}

	while (!q.empty()) {
		int cur = q.front(); q.pop();

		for (int nxt : adj[cur]) {
			if (area[nxt] == 1) continue;	//a구역이라면 continue
			if (visited[nxt]) continue;		//b구역이지만 이미 방문했다면 continue;
			q.push(nxt);
			visited[nxt] = 2;
		}
	}

	//방문안한 도시가 있는지 확인, 있다면 불가능한 방법
	for (int i = 1; i <= n; i++) {
		if (visited[i] == 0) return false;
	}
	return true;
}

void func(int k,int x,int num) {
	//k개의 도시가 a구역이라고 할때 현재 x번째 도시를 보고 있고,
	//num는 현재 a구역으로 정한 도시의 갯수

	if (k == num) {

		if (check()) {
			//조건을 만족할 때(두 구역으로 나누어질 때)
			getAns();
		}
		return;
	}

	for (int i = x; i <= n; i++) {
		if (area[i]) continue;
		area[i] = 1;

		func(k, i + 1,num+1);

		area[i] = 0;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> population[i];
	}

	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		while (x--) {
			int v;
			cin >> v;
			adj[i].push_back(v);
		}
	}

	//모든 경우의 수 구하기(a구역에 포함된 도시)
	for (int i = 1; i <n; i++) {
		fill(area, area + n + 1, 0);
		func(i,1,0);
	}

	cout << ans;

	return 0;
}

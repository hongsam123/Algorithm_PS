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

	//a���� bfs
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
			if (area[nxt] != 1) continue;	//a������ �ƴ϶�� continue
			if (visited[nxt]) continue;		//a������ ������ �̹� �湮�ߴٸ� continue;
			q.push(nxt);
			visited[nxt] = 1;
		}
	}

	//b���� bfs
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
			if (area[nxt] == 1) continue;	//a�����̶�� continue
			if (visited[nxt]) continue;		//b���������� �̹� �湮�ߴٸ� continue;
			q.push(nxt);
			visited[nxt] = 2;
		}
	}

	//�湮���� ���ð� �ִ��� Ȯ��, �ִٸ� �Ұ����� ���
	for (int i = 1; i <= n; i++) {
		if (visited[i] == 0) return false;
	}
	return true;
}

void func(int k,int x,int num) {
	//k���� ���ð� a�����̶�� �Ҷ� ���� x��° ���ø� ���� �ְ�,
	//num�� ���� a�������� ���� ������ ����

	if (k == num) {

		if (check()) {
			//������ ������ ��(�� �������� �������� ��)
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

	//��� ����� �� ���ϱ�(a������ ���Ե� ����)
	for (int i = 1; i <n; i++) {
		fill(area, area + n + 1, 0);
		func(i,1,0);
	}

	cout << ans;

	return 0;
}

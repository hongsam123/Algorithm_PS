#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

int t, f;
map<string, int> m;
int p[200002];			//집합의 루트를 저장
int num[200002];		//해당 인덱스가 루트인 트리에 있는 원소 갯수

void init() {
	for (int i = 1; i <= f*2; i++)
	{
		p[i] = i;
		num[i] = 1;
	}
}

int find(int a) {
	if (p[a] == a) return a;
	return p[a] = find(p[a]);
}

void Union(int a, int b) {
	int pa = find(a);
	int pb = find(b);
	if (pa == pb) return;

	//다른 집합이었다면
	int n = num[pb];
	num[pb] = 0;
	num[pa] += n;
	p[pb] = pa;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	while (t--) {
		cin >> f;
		init();

		int id = 1;
		for (int i = 0; i < f; i++) {
			string f1, f2;
			cin >> f1 >> f2;

			int fid1, fid2 = 0;
			if (m[f1]) {
				fid1 = m[f1];
			}
			else {
				m[f1] = id++;
				fid1 = m[f1];
			}

			if (m[f2]) {
				fid2 = m[f2];
			}
			else {
				m[f2] = id++;
				fid2 = m[f2];
			}

			Union(fid1, fid2);
			int root = find(fid1);
			cout << num[root] << "\n";
		}

		m.clear();
	}

	return 0;
}

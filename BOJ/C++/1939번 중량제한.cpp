#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<tuple>
#define ll long long
using namespace std;

ll n, m;
ll u, v;
vector<tuple<ll, ll, ll>> edge;
ll p[10002];
ll ans;

void init() {
	for (int i = 1; i <= n; i++) {
		p[i] = i;
	}
}

ll find(ll a) {
	if (p[a] == a) return a;
	return p[a] = find(p[a]);
}

void Union(ll a, ll b) {
	int pa = find(a);
	int pb = find(b);

	p[pa] = p[pb];
	//return true;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		ll a, b, c;
		cin >> a >> b >> c; 
		edge.push_back({ c,a,b });
	}

	cin >> u >> v;
	init();
	//내림차순으로 
	sort(edge.rbegin(), edge.rend());

	ll cnt = 0;

	for (int i = 0; i < m; i++) {
		ll ta, tb, c;
		tie(c, ta, tb) = edge[i];
		ll a = max(ta, tb);
		ll b = min(ta, tb);

		if (find(u) != find(v)) {
			Union(a, b);
			ans = c;
		}
	}

	cout << ans;

	return 0;
}

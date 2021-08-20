#include<iostream>
#include<vector>
#include<utility>
#include<tuple>
#include<algorithm>
#include<cmath>
using namespace std;
int v;
vector<pair<double, double>> star;
double ans;
int cnt;
int p[102];
vector<tuple<double, int, int>> edge;

int find(int a)
{
	if (p[a] == a) return a;
	return p[a] = find(p[a]);
}

bool is_diff(int a, int b)
{
	int pa = find(a);
	int pb = find(b);

	if (pa == pb) return false;

	p[pa] = pb;
	return true;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> v;

	//input
	for (int i = 0; i < v; i++)
	{
		double a, b;
		cin >> a >> b;
		star.push_back({ a,b });
	}

	//adj
	for (int i = 0; i < star.size(); i++)
	{
		for (int j = i + 1; j < star.size(); j++)
		{
			double ax = star[i].first;
			double ay = star[i].second;
			double bx = star[j].first;
			double by = star[j].second;

			edge.push_back({ sqrt(((ax - bx) * (ax - bx)) + ((ay - by) * (ay - by))),i,j });
		}
	}

	//init
	for (int i = 0; i < v; i++)
		p[i] = i;

	sort(edge.begin(), edge.end());

	for (int i = 0; i < edge.size(); i++)
	{
		double cost;
		int a, b;
		tie(cost, a, b) = edge[i];

		if (!is_diff(a, b)) continue;
		cnt++;
		ans += cost;
		if (cnt == v - 1) break;
	}


	cout << ans;

	return 0;
}

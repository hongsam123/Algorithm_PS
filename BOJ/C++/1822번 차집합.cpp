#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, m;
int a[500002];
int b[500002];
vector<int> v;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++)
		cin >> b[i];

	sort(b, b + m);
	for (int i = 0; i < n; i++)
	{
		int x = a[i];
		if (!binary_search(b, b + m, x))
			v.push_back(x);
	}

	if (v.empty())
		cout << 0;
	else
	{
		sort(v.begin(), v.end());
		cout << v.size() << "\n";
		for (auto e : v)
			cout << e << " ";
	}

	return 0;
}

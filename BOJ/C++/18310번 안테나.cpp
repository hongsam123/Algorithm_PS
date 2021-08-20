#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n;
vector<int> v;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	if (n % 2 == 0)
		cout << v[(n / 2)-1];
	else
		cout << v[(n / 2)];

	return 0;
}

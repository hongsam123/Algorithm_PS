#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
int arr[10002];
vector<int> v;

void func(int k)
{
	if (k == m)
	{
		for (int e : v)
			cout << e << " ";
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++)
	{
		v.push_back(arr[i]);
		func(v.size());
		v.pop_back();
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);
	func(0);

	return 0;
}

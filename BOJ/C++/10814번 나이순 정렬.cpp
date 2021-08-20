#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<tuple<int,int, string>> v;
	string str;
	int idx;
	for (int i = 0; i < n; i++)
	{
		cin >> idx >> str;
		v.push_back({ idx,i,str });
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++)
	{
		cout << get<0>(v[i]) << " " << get<2>(v[i]) << "\n";
	}

	return 0;
}

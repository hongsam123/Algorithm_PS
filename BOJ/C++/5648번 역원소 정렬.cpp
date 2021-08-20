#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<long long> v;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;

		long long new_num = 0;
		long long x = 1;
		for (int j = 0; j < str.size(); j++)
		{
			new_num += (str[j] - '0') * x;
			x *= 10;
		}
		v.push_back(new_num);
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++)
		cout << v[i] << "\n";

	return 0;
}


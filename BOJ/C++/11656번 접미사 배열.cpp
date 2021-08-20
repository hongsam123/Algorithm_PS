#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str;
	cin >> str;

	string str_new = "";
	vector<string> v;
	for (int i = str.size()-1; i >= 0 ; i--)
	{
		str_new = str[i] + str_new;
		v.push_back(str_new);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << "\n";

	return 0;
}

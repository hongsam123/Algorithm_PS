#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool comp(string a, string b)
{
	if (a.size() != b.size()) return a.size() < b.size();
	return a < b;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<string> v;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		
		bool posi = true;
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i] == str)
			{
				posi = false;
				break;
			}
		}
		if(posi)
			v.push_back(str);
	}

	sort(v.begin(), v.end(),comp);

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << "\n";

	return 0;
}

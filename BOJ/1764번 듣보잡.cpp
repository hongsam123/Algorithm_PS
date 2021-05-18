//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int n, m;
//	cin >> n >> m;
//
//	vector<vector<string>> v(27);
//	string str;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> str;
//		v[str[0] - 'a'].push_back(str);
//	}
//
//	vector<string> ans;
//	for (int i = 0; i < m; i++)
//	{
//		cin >> str;
//		int x = str[0] - 'a';
//		for (int j = 0; j < v[x].size(); j++)
//		{
//			if (v[x][j] == str)
//				ans.push_back(str);
//		}
//	}
//
//	sort(ans.begin(), ans.end());
//
//	cout << ans.size() << "\n";
//	for (int i = 0; i < ans.size(); i++)
//		cout << ans[i] << "\n";
//
//	return 0;
//}
//시간 초과
//어차피 정렬 하면 같은 것은 항상 붙어있게 된다

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<string> v;
	string str;
	for (int i = 0; i < n + m; i++)
	{
		cin >> str;
		v.push_back(str);
	}

	sort(v.begin(), v.end());

	vector<string> ans;
	string pre = v[0];
	for (int i = 1; i < v.size(); i++)
	{
		if (v[i] == pre) ans.push_back(v[i]);
		pre = v[i];
	}

	cout << ans.size() << "\n";
	for (string e : ans)
		cout << e << "\n";

	return 0;
}

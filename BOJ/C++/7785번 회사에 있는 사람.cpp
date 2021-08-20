#include<iostream>
#include<set>
using namespace std;

int n;
set<string,greater<string>> isin;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		string name, order;
		cin >> name >> order;

		if (order == "enter")
			isin.insert(name);
		else
			isin.erase(name);
	}

	for (auto e : isin)
		cout << e << "\n";


	return 0;
}

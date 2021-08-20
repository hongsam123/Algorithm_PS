#include<iostream>
#include<map>
using namespace std;

int n, m;
map<string, string> mm;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string address, password;
		cin >> address >> password;

		mm[address] = password;
	}

	for (int i = 0;i < m; i++)
	{
		string site;
		cin >> site;
		cout << mm[site] << "\n";
	}

	return 0;
}

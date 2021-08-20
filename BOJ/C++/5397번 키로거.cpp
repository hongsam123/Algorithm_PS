#include<iostream>
#include <list>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;

		list<char> L;
		auto t = L.begin();

		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '<')
			{
				if (t != L.begin()) t--;
			}
			else if (s[i] == '>')
			{
				if (t != L.end()) t++;
			}
			else if (s[i] == '-')
			{
				if (t != L.begin())
				{
					t--;
					t = L.erase(t);
				}
			}
			else
			{
				L.insert(t, s[i]);
			}
			
		}
		for (auto it : L)
			cout << it;
		cout << '\n';
	}


	return 0;
}

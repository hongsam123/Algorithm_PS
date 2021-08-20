#include<iostream>
#include <list>
using namespace std;

list<char> L;
list<char>::iterator cursor = L.end();

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	for (int i = 0; i < s.size(); i++)
	{
		L.push_back(s[i]);
	}
	
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		char op;
		cin >> op;
		switch (op)
		{
		case ('L'): if(cursor != L.begin()) cursor--; break;
		case('D'): if (cursor != L.end()) cursor++; break;
		case('B'): 
			if (cursor != L.begin())
			{
				cursor--;
				cursor = L.erase(cursor);
			}
			break;
		case('P'): 
			char x;
			cin >> x;
			L.insert(cursor, x); 
			break;
		default: break;
		}
	}

	for (auto it : L) cout << it;

	return 0;
}

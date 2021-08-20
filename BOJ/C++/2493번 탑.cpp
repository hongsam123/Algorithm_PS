#include<iostream>
#include<utility>
#include<stack>
using namespace std;

stack<pair<int,int>> s;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, x;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> x;

		while (!s.empty())
		{
			if (x < s.top().second)
			{
				cout << s.top().first << " ";
				break;
			}
			s.pop();
		}
		
		if (s.empty())
			cout << 0 << " ";

		s.push(make_pair(i + 1, x));
	}

	return 0;
}

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

stack<int> s;
vector<char> v;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n,x;
	int max = 0;
	bool posi = true;
	
	cin >> n;
	while (n--)
	{
		cin >> x;
		if (x > max)
		{
			for (int i = max + 1; i <= x; i++)
			{
				s.push(i);
				v.push_back('+');
			}
		}
		else
		{
			if (s.top() != x)
			{
				posi = false;
				break;
			}
		}
		s.pop();
		v.push_back('-');

		if (x > max) max = x;
	}

	if (posi)
	{
		for (char it : v)
			cout << it << '\n';
	}
	else
		cout << "NO";

	return 0;
}

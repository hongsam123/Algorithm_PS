#include<iostream>
#include<stack>
using namespace std;

stack<int> s;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int k,n;
	int cnt = 0;
	cin >> k;

	for (int i = 0; i < k; i++)
	{
		cin >> n;
		if (n != 0)
		{
			s.push(n);
		}
		else s.pop();
	}

	while (s.size() != 0)
	{
		cnt += s.top();
		s.pop();
	}
	
	cout << cnt;
	

	return 0;
}

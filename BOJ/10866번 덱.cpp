#include<iostream>
#include<deque>
using namespace std;

deque<int> dq;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, val;
	cin >> n;

	string input;

	while (n--)
	{
		cin >> input;
		if (input == "push_front")
		{
			cin >> val;
			dq.push_front(val);
		}
		else if (input == "push_back")
		{
			cin >> val;
			dq.push_back(val);
		}
		else if (input == "pop_front")
		{
			if (dq.empty()) cout << -1 << '\n';
			else
			{
				cout << dq.front() << '\n';
				dq.pop_front();
			}
		}
		else if (input == "pop_back")
		{
			if (dq.empty()) cout << -1 << '\n';
			else
			{
				cout << dq.back() << '\n';
				dq.pop_back();
			}
		}
		else if (input == "size")
		{
			cout << dq.size() << '\n';
		}
		else if (input == "empty")
		{
			if (dq.empty()) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (input == "front")
		{
			if (dq.empty()) cout << -1 << '\n';
			else cout << dq.front() << '\n';
		}
		else
		{
			if (dq.empty()) cout << -1 << '\n';
			else cout << dq.back() << '\n';
		}
	}

	return 0;
}

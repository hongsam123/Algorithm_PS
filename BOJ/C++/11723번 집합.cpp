#include<iostream>
using namespace std;
bool arr[22];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int test;
	string str;
	int x;
	cin >> test;

	while (test--)
	{
		cin >> str;

		if (str == "add")
		{
			cin >> x;
			if (!arr[x]) arr[x] = 1;
		}
		else if (str == "remove")
		{
			cin >> x;
			if (arr[x]) arr[x] = 0;
		}
		else if (str == "check")
		{
			cin >> x;
			if (arr[x]) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
		else if (str == "toggle")
		{
			cin >> x;
			if (arr[x]) arr[x] = 0;
			else arr[x] = 1;
		}
		else if (str == "all")
		{
			for (int i = 0; i < 20; i++)
				arr[i] = 1;
		}
		else
		{
			for (int i = 0; i < 20; i++)
				arr[i] = 0;
		}
	}

	return 0;
}

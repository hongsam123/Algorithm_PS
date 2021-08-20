#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (1)
	{
		stack<char> s;

		string str;
		getline(cin, str);

		if (str.size()==1 && str[0] == '.') break;

		bool posi = true;

		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == '[' || str[i] == '(')
			{
				s.push(str[i]);
			}

			if (str[i] == ']' || str[i] == ')')
			{
				if (s.empty())
				{
					posi = false;
					break;
				}
				char ch = s.top(); s.pop();
				if (str[i] == ']')
				{
					if (ch != '[')
					{
						posi = false;
						break;
					}
				}
				else
				{
					if (ch != '(')
					{
						posi = false;
						break;
					}
				}

			}
			if (!posi) break;
		}

		if (!s.empty()) posi = false;

		if (posi)
			cout << "yes\n";
		else
			cout << "no\n";
	}

	return 0;
}

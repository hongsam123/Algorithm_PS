#include<iostream>
#include<stack>
#include<vector>
#include<utility>
#define INF 1000000000
using namespace std;

stack<long long> s;
vector<pair<string, long long>> command;

void num(long long x)
{
	s.push(x);
	return;
}

bool pop()
{
	if (s.empty())
		return false;
	s.pop();
	return true;
}

bool inv()
{
	if (s.empty())
		return false;
	long long x = s.top(); s.pop();
	s.push(x * -1);
	return true;
}

bool dup()
{
	if (s.empty())
		return false;
	long long x = s.top();
	s.push(x);
	return true;
}

bool swp()
{
	if (s.size() < 2)
		return false;
	long long n1 = s.top(); s.pop();
	long long n2 = s.top(); s.pop();
	s.push(n1);
	s.push(n2);
	return true;
}

bool add()
{
	if (s.size() < 2)
		return false;
	long long n1 = s.top(); s.pop();
	long long n2 = s.top(); s.pop();
	if (abs(n1 + n2) > INF) return false;
	s.push(n1 + n2);
	return true;
}

bool sub()
{
	if (s.size() < 2)
		return false;
	long long n1 = s.top(); s.pop();
	long long n2 = s.top(); s.pop();
	if (abs(n2 - n1) > INF) return false;
	s.push(n2 - n1);
	return true;
}

bool mul()
{
	if (s.size() < 2)
		return false;
	long long n1 = s.top(); s.pop();
	long long n2 = s.top(); s.pop();
	if (abs(n1 * n2) > INF) return false;
	s.push(n1 * n2);
	return true;
}

bool div()
{
	if (s.size() < 2)
		return false;
	long long n1 = s.top(); s.pop();
	long long n2 = s.top(); s.pop();
	if (n1 == 0) return false;
	if ((n1 <= 0 && n2 <= 0) || (n1 >= 0 && n2 >= 0))
	{
		n1 = abs(n1); n2 = abs(n2);
		if (abs(n2/n1) > INF) return false;
		s.push(n2 / n1);
		return true;
	}
	n1 = abs(n1); n2 = abs(n2);
	if (abs(n2 / n1) > INF) return false;
	s.push(n2 / n1 *-1);
	return true;
}

bool mod()
{
	if (s.size() < 2)
		return false;
	long long n1 = s.top(); s.pop();
	long long n2 = s.top(); s.pop();
	if (n1 == 0) return false;
	long long n1_ = abs(n1);
	long long n2_ = abs(n2);
	if (abs(n2_ % n1_) > INF) return false;
	if (n2 < 0) s.push(n2_ % n1_ * -1);
	else s.push(n2_ % n1_);
	return true;
}

int main()
{
	ios::sync_with_stdio();
	cin.tie();

	while (1)
	{
		while (1)
		{
			string str;
			long long x = 0;
			cin >> str;
			if (str == "NUM")
				cin >> x;
			command.push_back({ str,x });

			if (str == "END") break;

			if (str == "QUIT")
				return 0;
		}

		long long t;
		cin >> t;
		while (t--)
		{
			while (!s.empty()) s.pop();
		
			long long x;
			cin >> x;
			s.push(x);

			bool impo = false;

			for (long long i = 0; i < command.size(); i++)
			{
				string com = command[i].first;

				if (com == "NUM")
				{
					long long n = command[i].second;
					num(n);
				}
				else if (com == "POP")
				{
					if (!pop()) impo = true;
				}
				else if (com == "INV")
				{
					if (!inv()) impo = true;
				}
				else if (com == "DUP")
				{
					if (!dup()) impo = true;
				}
				else if (com == "SWP")
				{
					if (!swp()) impo = true;
				}
				else if(com == "ADD")
				{ 
					if (!add()) impo = true;
				}
				else if (com == "SUB")
				{
					if(!sub()) impo = true;
				}
				else if (com == "MUL")
				{
					if (!mul()) impo = true;
				}
				else if (com == "DIV")
				{
					if (!div()) impo = true;
				}
				else if (com == "MOD")
				{
					if(!mod()) impo = true;
				}

				if (impo)	break;
			}

			if (impo)
			{
				cout << "ERROR\n";
				continue;
			}

			if (s.size() != 1)
			{
				cout << "ERROR\n";
				continue;
			}

			cout << s.top() << "\n";
		}
		cout << "\n";
		command.clear();
	}

	return 0;
}

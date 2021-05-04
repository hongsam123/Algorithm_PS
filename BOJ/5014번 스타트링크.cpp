#include<iostream>
using namespace std;

int f, s, g, u, d;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> f >> s >> g >> u >> d;
	int  answer = 0;

	if (s > g && d == 0)
		cout << "use the stairs";
	else if (s < g && u == 0)
		cout << "use the stairs";
	else if (u != 0 && abs(s - g) % u != 0 && d == 0)
		cout << "use the stairs";
	else if (d != 0 && abs(s - g) % d != 0 && u == 0)
		cout << "use the stairs";
	else if (u != 0 && abs(s - g) % u != 0 && d == u)
		cout << "use the stairs";
	else if (d != 0 && abs(s - g) % d != 0 && u == d)
		cout << "use the stairs";
	else if (u != 0 && abs(s - g) % u != 0 && d > f)
		cout << "use the stairs";
	else if (d != 0 && abs(s - g) % d != 0 && u > f)
		cout << "use the stairs";
	else if (u != 0 && abs(s - g) % u != 0 && abs(s - g) % d != 0)
		cout << "use the stairs";
	else if (d != 0 && abs(s - g) % d != 0 && abs(s - g) % u != 0)
		cout << "use the stairs";
	else
	{
		while (s != g)
		{
			while (s < g)
			{
				if (s + u > f)
				{
					s -= d;
					answer++;
				}
				s += u;
				answer++;
			}
			while (s > g)
			{
				if (s - d <= 0)
				{
					s += u;
					answer++;
				}
				s -= d;
				answer++;
			}
		}
		cout << answer;
	}

	return 0;
}

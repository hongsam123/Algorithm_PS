#include<iostream>
using namespace std;

int n, m;
string s;
int ans;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> s;

	bool isCnt = false;
	int Ocnt = 0;
	char pre = ' ';
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 'I')
		{
			if (isCnt)
			{
				if (pre == 'I')
				{
					Ocnt = 0;
				}
				if (Ocnt == n && pre=='O')
				{
					ans++;
					Ocnt--;
				}
			}
			else
			{
				isCnt = true;
			}
		}
		else
		{
			if (pre == 'O')
			{
				isCnt = false;
				Ocnt = 0;
			}
			if (isCnt && pre=='I')
			{
				Ocnt++;
			}
		}
		pre = s[i];
	}

	cout << ans;

	return 0;
}

#include<iostream>
using namespace std;

string str;
int ans;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> str;

	char pre;
	int cnt = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(')
		{
			cnt++;
		}
		else
		{
			if (pre == '(')	//·¹ÀÌÀú
			{
				cnt--;
				ans += cnt;
			}
			else
			{
				cnt--;
				ans++;
			}
		}
		pre = str[i];
	}

	cout << ans;

	return 0;
}

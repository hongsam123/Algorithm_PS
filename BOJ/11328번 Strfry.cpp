#include<iostream>
#include<algorithm>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	int cnt[27];
	cin >> n;

	string s1,s2;
	for (int i = 0; i < n; i++)
	{
		fill(cnt, cnt + 27, 0);
		bool posi = true;

		cin >> s1;
		for (int j = 0; j < s1.size(); j++)
		{
			cnt[s1[j] - 'a']++;
		}

		cin >> s2;
		for (int j = 0; j < s2.size(); j++)
		{
			if (cnt[s2[j] - 'a'] != 0)
			{
				cnt[s2[j] - 'a']--;
			}
			else
			{
				posi = false;
				break;
			}
		}

		if (posi)
		{
			for (int j = 0; j < 27; j++)
			{
				if (cnt[j] != 0)
				{
					posi = false;
					break;
				}
			}
		}
		if (posi) cout << "Possible\n";
		else cout << "Impossible\n";
	}

	return 0;
}

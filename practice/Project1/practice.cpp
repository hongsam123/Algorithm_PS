#include<iostream>
#include<algorithm>
using namespace std;

int check[27];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int cnt = 0;
	cin >> n;

	while (n--)
	{
		string str;
		bool posi = true;
		char tmp = "";

		for (int i = 0; i < str.size(); i++)
		{
			if (tmp == str[i]) continue;

			if (check[str[i] - 'a'] == 1)
			{
				posi = false;
				break;
			}
			else
			{
				check[str[i] - 'a'] = 1;
				tmp = str[i];
			}
		}
		if (posi) cnt++;
	}

	cout << cnt;
	return 0;
}
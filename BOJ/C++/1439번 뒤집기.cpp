#include<iostream>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str;
	cin >> str;

	int count0 = 0;
	int count1 = 0;
	
	if (str[0] == '0')
		count0++;
	else
		count1++;

	char prev = str[0];
	for (int i = 1; i < str.size(); i++)
	{
		if (prev == str[i])
		{
			prev = str[i];
			continue;
		}
		else
		{
			prev = str[i];
			if (str[i] == '0')
				count0++;
			else
				count1++;
		}
	}

	cout << min(count0, count1);

	return 0;
}

#include<iostream>
using namespace std;

int a[27];
int b[27];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string first, second;

	cin >> first >> second;

	for (int i = 0; i < first.size(); i++)
	{
		a[first[i] - 'a']++;
	}
	for (int i = 0; i < second.size(); i++)
	{
		b[second[i] - 'a']++;
	}

	int cnt = 0;;
	for (int i = 0; i <= 26; i++)
	{
		if (a[i] != b[i])
		{
			/*int max, min;
			if (a[i] > b[i])
			{
				max = a[i];
				min = b[i];
			}
			else
			{
				max = b[i];
				min = a[i];
			}
			cnt += max - min;*/
			cnt += abs(a[i] - b[i]);
		}
	}

	cout << cnt;

	return 0;
}

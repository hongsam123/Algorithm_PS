#include<iostream>
using namespace std;

int girl[7];
int boy[7];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		int s,grade;
		cin >> s >> grade;

		if (s)
			boy[grade]++;
		else
			girl[grade]++;
	}

	int room = 0;
	for (int i = 1; i <= 6; i++)
	{
		while (girl[i] > 0)
		{
			room++;
			girl[i] -= k;
		}
		while (boy[i] > 0)
		{
			room++;
			boy[i] -= k;
		}
	}

	cout << room;

	return 0;
}


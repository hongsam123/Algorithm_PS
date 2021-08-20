#include<iostream>
using namespace std;

int arr[10];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string rnum;
	cin >> rnum;

	for (int i = 0; i < rnum.size(); i++)
	{
		if (rnum[i] == 6 + '0')
		{
			arr[9]++;
		}
		else
		{
			arr[rnum[i]-'0']++;
		}
	}

	//for (char e : rnum)
	//{
	//	arr[e - '0']++;
	//}

	int cnt = 0;
	while (arr[9] > 0)
	{
		cnt++;
		arr[9] -= 2;
	}

	int max = arr[0];
	for (int i = 1; i <= 8; i++)
	{
		if (max < arr[i]) max = arr[i];
	}

	if (cnt >= max)
		cout << cnt;
	else
		cout << max;

	return 0;
}

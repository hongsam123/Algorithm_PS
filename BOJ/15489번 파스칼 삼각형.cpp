#include<iostream>
using namespace std;

int r, c, w;
int arr[32][32];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c >> w;

	for (int i = 1; i <= r + w; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (j == 1 || j == i) arr[i][j] = 1;
			else arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		}
	}

	int answer = 0;
	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			answer += arr[i+r][j+c];
		}
	}

	cout << answer;

	return 0;
}

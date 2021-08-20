#include<iostream>
#include<algorithm>
using namespace std;

int arr[52];
int tmp[52];
bool check[52];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		tmp[i] = arr[i];
	}

	sort(tmp, tmp + n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i] == tmp[j] && check[j] == false)
			{
				cout << j << " ";
				check[j] = true;
				break;
			}
		}
	}

	return 0;
}

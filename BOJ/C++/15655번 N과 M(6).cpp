//next_permutation»ç¿ë 
#include<iostream>
#include<algorithm>

using namespace std;

int n,m;
int arr[10002];
int tmp[10002];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	for (int i = m; i < n; i++)
	{
		tmp[i] = 1;
	}
	
	sort(arr, arr + n);

	do
	{
		for (int i = 0; i < n; i++)
		{
			if (tmp[i] == 0)
			{
				cout << arr[i] << " ";
			}
		}
		cout << "\n";
	} while (next_permutation(tmp, tmp + n));


	return 0;
}

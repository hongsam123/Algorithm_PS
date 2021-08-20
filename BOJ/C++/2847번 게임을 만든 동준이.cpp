#include<iostream>
using namespace std;

int n;
int arr[102];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin>>arr[i];
	}

	int pre = arr[n - 1];
	int cnt = 0;
	//배열을 뒤에서부터 봤을 때 이전 수보다 크거나 같으면 감소 
	for (int i = n - 2; i >= 0; i--)
	{
		if (arr[i] >= pre)
		{
			cnt += arr[i] - (pre - 1);
			arr[i] = pre - 1;
		}
		pre = arr[i];
	}

	cout << cnt;

	return 0;
}

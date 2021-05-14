#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
int board[10];
int arr[10];
bool isused[10002];

void func(int k)
{
	if (k == m)
	{
		for (int i = 0; i < m; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}
	
	for (int i = 0; i < n; i++)
	{
		int x = board[i];
		if (isused[x]) continue;
		arr[k] = x;
		isused[x] = 1;
		func(k + 1);

		isused[x] = 0;
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> board[i];
	}

	sort(board, board + n);

	func(0);

	return 0;
}

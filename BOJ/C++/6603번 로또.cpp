#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n;
int number[15];
bool isused[15];
vector<int> v;

void func(int cur,int k)
{
	if (k == 6)
	{
		for (int e : v)
			cout << e << " ";
		cout << "\n";
	}

	for (int i = cur; i < n; i++)
	{
		if (isused[i]) continue;
		isused[i] = true;
		v.push_back(number[i]);

		func(i + 1,k + 1);

		isused[i] = false;
		v.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (1)
	{
		cin >> n;
		if (n == 0) break;

		for (int i = 0; i < n; i++)
			cin >> number[i];

		func(0,0);

		cout << "\n";
		
		v.clear();
	}

	return 0;
}

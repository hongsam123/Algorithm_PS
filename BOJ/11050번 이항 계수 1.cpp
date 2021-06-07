#include<iostream>
using namespace std;

int n, k;

int fac(int num)
{
	if (num == 0 || num == 1) return 1;
	else return fac(num - 1) * num;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	cout << fac(n) / (fac(k) * fac(n - k));

	return 0;
}

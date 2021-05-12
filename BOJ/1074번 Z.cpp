#include<iostream>
using namespace std;

int func(int num, int r, int c)
{
	if (num == 0) return 0;
	//base condition
	int half = 1 << (num - 1);
	//한변 길이의 절반, 즉 2^n-1
	if (r < half && c < half) return func(num - 1, r, c);
	if (r < half && c >= half) return half * half + func(num - 1, r, c - half);
	if (r >= half && c < half) return 2 * half * half + func(num - 1, r - half, c);
	return 3 * half * half + func(num - 1, r - half, c - half);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, r, c;
	cin >> n >> r >> c;
	cout<<func(n, r, c);

	return 0;
}

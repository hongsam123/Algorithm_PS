#include<iostream>
using namespace std;
using ll = long long;

ll func(ll a, ll b, ll m)
{
	if (b == 1) return a % m;
	//base condition을 잡고
	ll val = func(a, b / 2, m);
	//k승의 결과를 토대로
	val = val * val % m;
	if (b % 2 == 0) return val;
	//2k승의 결과를 계산할 수 있다
	return val * a % m;
	//(2k+1)승의 결과도 계산할 수 있다.
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll a, b, m;
	cin >> a >> b >> m;
	cout << func(a, b, m);

	return 0;
}

//마지막에 백기가 놓이는 것은 제곱수
#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	long double n;

	cin >> n;

	//제곱근 구하고 소수점 버리기
	long double ans;

	ans = sqrt(n);

	int x = ans;

	cout << x;

	return 0;
}

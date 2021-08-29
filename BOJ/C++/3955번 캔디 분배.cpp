//x:���� �� , y:������
//k*x + 1 = c*y
//�� -k*x + c*y = 1 �� �����ϴ� x,yã��(ax,by = c)
#include<iostream>
#include<algorithm>
#include<cmath>
#define ll long long
using namespace std;

struct EGResult {
	ll s, t, r;
	EGResult(ll _s, ll _t, ll _r) :s(_s), t(_t), r(_r) {}
};

EGResult extendedgcd(ll a, ll b)
{
	ll s0 = 1, t0 = 0, r0 = a;
	ll s1 = 0, t1 = 1, r1 = b;
	ll tmp;
	while (r1 != 0)
	{
		ll q = r0 / r1;

		tmp = r0 - q * r1;
		r0 = r1;
		r1 = tmp;

		tmp = s0 - q * s1;
		s0 = s1;
		s1 = tmp;

		tmp = t0 - q * t1;
		t0 = t1;
		t1 = tmp;
	}

	return EGResult(s0,t0,r0);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--)
	{
		ll A, B;

		cin >> A >> B;

		EGResult result = extendedgcd(A, B);
		//Ax + By = C �϶� C % D == 0 �̾�� �ظ� ���� �� �ִ�(�����׵��)
		if (result.r != 1)
			cout << "IMPOSSIBLE\n";
		else
		{
			ll x0 = result.s;
			ll y0 = result.t;

			//y����
			ll kFromY = ceil((double)y0 / A) - 1;
			//x����
			ll kFromX = ceil((double)x0 / B) - 1;
			//���� ����
			ll k = min(kFromX, kFromY);


			y0 %= A;
			if (y0 < 0) y0 += A;
			y0 = max(y0, (A + B) / B);
			//ll y = y0 - A * k;

			if (y0 <= 1e9)
				cout << y0 << "\n";
			else
				cout << "IMPOSSIBLE\n";
		}
	}

	return 0;
}

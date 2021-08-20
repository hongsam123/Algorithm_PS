#include<iostream>
#include<deque>
using namespace std;

int n, k;
int num;
deque<int> dq;
bool posi;

void func(int sum)
{
	if (sum == n)
	{
		num++;
		if (num == k)
		{
			int tmp = 0;
			for (auto e : dq)
			{
				tmp += e;
				if (tmp == n)
					cout << e;
				else cout << e << "+";
				posi = true;
			}
		}
		return;
	}

	for (int i = 1; i <= 3; i++)
	{
		if (sum + i > n) continue;
		dq.push_back(i);
		func(sum+i);
		dq.pop_back();
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	func(0);

	if(!posi)
		cout << -1;

	return 0;
}

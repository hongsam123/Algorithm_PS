#include<iostream>
using namespace std;

int n;
bool isused1[16];	//열(y)
bool isused2[32];	//우상좌하 대각선(x+y)
bool isused3[32];	//좌상우하 대각선(x-y+n-1) => 음수가 되는 인덱스를 없애기 위해서
int cnt;

void func(int cur)	//cur행의 퀸의 위치를 정하는 함수
{
	if (cur == n )
	{
		cnt++;
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (isused1[i] || isused2[cur + i] || isused3[cur - i + n - 1]) continue;
		isused1[i] = true;
		isused2[cur + i] = true;
		isused3[cur - i + n - 1] = true;
		func(cur + 1);

		isused1[i] = false;
		isused2[cur + i] = false;
		isused3[cur - i + n - 1] = false;
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	func(0);

	cout << cnt;

	return 0;
}


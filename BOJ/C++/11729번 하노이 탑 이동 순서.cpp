#include<iostream>
using namespace std;

void hanoi(int a, int b, int num)
//시작 기둥과 도착 기둥을 인자로 받는 함수이어야 한다
{
	if (num == 1)
	{
		cout << a << " " << b << "\n";
		return;
	}
	//base condition을 정의 
	hanoi(a, 6 - a - b, num - 1);
	cout << a << " " << b << "\n";
	hanoi(6 - a - b, b, num - 1);
	//k-1번째까지 탑을 옮길수 있으면 k번째 타일을 옮기고 탑을 올리면 되니 k번째 탑도 옮길수 있다
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	cout << (1 << n) - 1 << "\n";
	//left shift 비트연산자(1을 비트기준으로 n칸 민다 = 2^n)
	hanoi(1,3,n);

	return 0;
}

#include<iostream>
using namespace std;

void hanoi(int a, int b, int num)
//���� ��հ� ���� ����� ���ڷ� �޴� �Լ��̾�� �Ѵ�
{
	if (num == 1)
	{
		cout << a << " " << b << "\n";
		return;
	}
	//base condition�� ���� 
	hanoi(a, 6 - a - b, num - 1);
	cout << a << " " << b << "\n";
	hanoi(6 - a - b, b, num - 1);
	//k-1��°���� ž�� �ű�� ������ k��° Ÿ���� �ű�� ž�� �ø��� �Ǵ� k��° ž�� �ű�� �ִ�
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	cout << (1 << n) - 1 << "\n";
	//left shift ��Ʈ������(1�� ��Ʈ�������� nĭ �δ� = 2^n)
	hanoi(1,3,n);

	return 0;
}

#include<iostream>
using namespace std;
int N;

void print(int cnt)
{
	while (cnt--)
	{
		cout << "____";
	}
	return;
}

void func(int num)
{
	print(N-num);
	cout << "\"����Լ��� ������?\"\n";
	print(N - num);
	cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
	print(N - num);
	cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
	print(N - num);
	cout<<"���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
	if (num == 1)
	{
		print(N - num+1);
		cout << "\"����Լ��� ������?\"\n";
		print(N - num+1);
		cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
		print(N - num+1);
		cout << "��� �亯�Ͽ���.\n";
		return;
	}

	func(num - 1);
	print(N - num+1);
	cout << "��� �亯�Ͽ���.\n";
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >>	N;
	cout<< "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
	func(N);
	cout<< "��� �亯�Ͽ���.";
	return 0;
}

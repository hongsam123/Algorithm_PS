//n������ �� �� �Ҽ����� n�� ���� �� �ִ� ���� ����ϸ� �ð��ʰ�
//n������ ������ �������� ���� �Ҽ����� ���� Ȯ������ �ʾƵ� �ȴ�
//#include<iostream>
//using namespace std;
//
//int n;
//
////bool isPrime(int n)
////{
////	for (int i = 2; i*i <= n; i++)
////	{
////		if (n % i == 0)
////			return false;
////	}
////	return true;
////}
//
//int main()
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> n;
//
//	if (n == 1) return 0;
//
//	while (n != 1)
//	{
//		for (int i = 2; i <= n; i++)
//		{
//			if (n % i == 0)
//			{
//				n = n / i;
//				cout << i << "\n";
//				break;
//			}
//		}
//	}
//
//	return 0;
//}
//�� �ڵ带 ����ȭ �ؼ� for���� �� ���� ���� �־��� ��� O(rootN)���� �ð����⵵�� ���� �� �ִ�.
#include<iostream>
using namespace std;

int n;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	if (n == 1) return 0;

	for (int i = 2; i*i <= n; i++)
	{
		while (n % i == 0)
		{
			n = n / i;
			cout << i << "\n";
		}
	}
	if (n != 1) cout << n;
	return 0;
}

//n이하의 수 중 소수에서 n을 나눌 수 있는 수를 출력하면 시간초과
//n이하의 나누어 떨어지는 수가 소수인지 굳이 확인하지 않아도 된다
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
//위 코드를 최적화 해서 for문을 더 적게 돌려 최악의 경우 O(rootN)까지 시간복잡도를 줄일 수 있다.
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

//n의 뒤에서부터 처음 0이 아닌 숫자가 나올 때까지 0의 개수가 k라는 것은 
//n이 10^k의 배수이면서 10^k+1의 배수는 아니라는 뜻
//n!을 소인수 분해 했을 때 n! = 2^a * 5^b * etc라면
//뒤에서부터 처음 0이 아닌 숫자가 나올때 까지 0이 min(a,b)개 나온다
//2가 5보다 많이 나오는것은 자명하니 5가 몇개 나오는지만 센다
//n은 최대 500. 1~n중 5의 배수의 갯수, 25의 배수의 갯수, 125의 배수의 갯수를 더한다
//

#include<iostream>
using namespace std;

int n;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	cout << n / 5 + n / 25 + n / 125;
	
	//int cnt = 0;
	//while (n > 0)
	//{
	//	n /= 5;
	//	cnt += n;
	//}
	//cout << cnt;
	////도 동일한 방법

	return 0;
}

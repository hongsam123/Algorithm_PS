////소수 - 소수판정법
//bool isPrime(int n)
//{
//	if (n == 1) return false;
//	for (int i = 2; i < n; i++)
//	{
//		if (n % i == 0)
//			return false;
//	}
//	return true;
//}
//시간복잡도 O(n)의 방법
//그러나 여기서 i(n의 약수 중 제일 작아 가장 처음 만나는 수)는  O(sqrt(n))보다 클수 없다.
//이를 이용하여 반복문을 i^2이 n이하일 때까지 돌리면 시간복잡도를 O(sqrt(N))으로 줄일 수 있다.
//주의) 이때 sqrt함수를 사용하는 것은 실수 오차가 발생할 수 있기 때문에 
//	  i<=sqrt(n)대신 i*i<=n을 사용하자
//bool isPrime2(int n)
//{
//	if (n == 1) return false;
//	for (int i = 2; i*i <= n; i++)
//	{
//		if (n % i == 0)
//			return false;
//	}
//	return true;
//}
//
////소수 - 에라토스테네스의 체
//n이하의 소수를 모두 찾는 알고리즘 중 일반적으로는 1~n까지 위의 소수판정법을 전부 적용할 수 있다.
//하지만 에라토스테네스의 체 알고리즘을 사용하면 위의 방법보다 메모리를 13~40배 절약할 수 있음
//1. n칸짜리 배열을 만든다. 이 배열은 해당 칸의 수가 소수일 경우 true, 소수가 아닐경우 false를 의미한다. 1은 false. 나머지는 true로 초기화.
//2. 2부터 n까지 진행하며 반복한다. 2가아닌 모든 2의 배수를 false로 만든다. 3도 동일.
//3. 4는 false이므로 아무 작업하지 않고 넘어간다
//4. 5는 true이므로 5를 제외한 5의 배수를 모두 false로 만든다
//5. 위의 작업을 n에 도달할 때까지 반복한다. 
//6. 배열에서 남은 true로 남은칸이 곧 소수.
//
//vector<int> allPrime(int n)
//{
//	vector<int> ret;
//
//	int state[n + 1];
//
//	state[1] = 0;
//	for (int i = 2; i <= n; i++) state[i] = 1;
//	for (int i = 2; i <= n; i++)
//	{
//		if (state[i] == 0) continue;
//		for (int j = i * 2; j <= n; j += i) state[j] = 0;
//	}
//	for (int i = 1; i <= n; i++)
//		if (state[i]) ret.push_back(i);
//
//	return ret;
//}
//현재 에라토스테네스의 체는 소수 판정법을 n번 돌리는 방법보다 더 느리다. 
//최적화1) 현재 코드에서는 i가 k일 때 2k,3k,4k...를 모두 false로 두는데
//		이것들은 각각 2,3,4...k-1로 나누어지므로 k보다 작은 소인수가 존재한다.
//		즉 k에서 굳이 신경을 쓰지 않아도 이미 false가 되어있음.
//		그러므로 j가 2i에서 시작이 아니라 i^2부터 시작하면 된다
//최적화2) 위의 최적화에 따라 i^2가 n보다 커지면 더 이상 아무 값도 바꾸지 않으므로
//		i^2이 n이하일 때만 돌린다
//최적화3) state배열을 bool로 바꾼다(메모리 절약 + 공간을 적게써 hit rate를 높여 속도의 개선에 영향을 미친다)
//
////최적화 된 에라토스테네스의 체
//vector<int> allPrime2(int n)
//{
//	vector<int> ret;
//	vector<bool> state(n + 1, true);
//	//n+1만큼 크기를 잡고 true로 초기화 시키며 생성
//	
//	state[1] = false;
//	for (int i = 2; i * i <= n; i++)
//	{
//		if (state[i] == false) continue;
//		for (int j = i * i; j <= n; j += i) state[j] = false;
//	}
//
//	for (int i = 1; i <= n; i++)
//	{
//		if (state[i] == true) ret.push_back(i);
//	}
//	return ret;
//}
//
//= > n이하의 소수를 모두 찾고 싶을 때 각각의 수를 소수 판정하는 것 보다 시간을 절약한다.
//정확한 시간복잡도는 O(nlogn)
//

//boj 1456 거의 소수
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long a, b, ans;
const long long MAX = 10000000 + 1;
bool state[MAX];
vector<long long> prime;

void eratos()	//소수판별
{
	fill(state, state + MAX, true);
	state[1] = false;
	cout << "dpd";

	for (long long i = 2; i*i <= MAX; i++)
	{
		if (state[i] == false) continue;
		for (long long j = i * i; j <= MAX; j += i) state[j] = false;
	}

	for (int i = 2; i < MAX; i++)
	{
		if (state[i]) prime.push_back(i);
	}

	return;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b;

	eratos();

	for (int i = 0; i < prime.size(); i++)
	{
		long long num = prime[i];
		while (prime[i] <= b / num)
			//여기서 if (prime[i] * num <= b) 을 하면 long long 범위를 벗어난다
		{
			cout << "?";
			if (prime[i] * num >= a)
				ans++;
			num *= prime[i];
		}
	}

	cout << ans;

	return 0;
}
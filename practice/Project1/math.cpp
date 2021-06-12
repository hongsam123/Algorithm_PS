﻿////소수 - 소수판정법
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

////소수 - 소인수분해
//n을 소인수분해 하는 알고리즘(n이하의 모든 소수들을 구하고 그 소수들로 n을 나누면 되지만 n이 큰 경우 시간이 초과될 수 있다)
//1. i를 2로 초기화, 소인수 목록을 저장할 배열을 준비한다.
//2. n이 i로 나누어 떨어지는지 확인하고 그렇다면 소인수 목록에 2를 추가, n을 2로 나눈다.
//3. n이 i로 나누어 떨어지지 않을 때까지 이를 반복
//4. 더이상 i로 나누어 떨어지지 않으면 i를 1증가.n이 1일 경우에는 종료
//
//i로 n이 나누어지는지 확인할 때 i가 소수인지 확인하지 않는다. 
//소인수 목록에 적힌 수들이 모두 소수임은 증명 가능
//(n이 4로 또는 6으로 나누어 진다고 해도(소수가 아닌수) i가 2일때부터 나누어 떨어지지 않을때까지 반복하기 때문에 i는 소수일때만 소인수 목록에 저장됨)
//
//void solve(int n)
//{
//	for (int i = 2; n != 1; i++)
//	{
//		while (n % i == 0)
//		{
//			cout << i << "\n";
//			n /= i;
//		}
//	}
//}
//
//위 알고리즘 시간복잡도는 최악의 경우 O(n).최적화를 통해 O(rootN)으로 줄일수 있다.
//앞의 소수 판정법의 최적화와 같이 i ^ 2가 n보다 커지면 n이 소수임을 알 수 있다.
//이를 통해 for문을 i ^ 2가 n이하일때까지 돌리면 O(rootN)으로 시간을 줄일 수 있다
//for (int i = 2; n != 1; i++) 을
//for (int i = 2; i * i <= n; i++) 으로 (단 n이 1 이 되었을 때 출력하지 않도록 주의)

////약수와 최대공약수
//가장 간단한 방법으로 1부터 N까지 모든 수에 대해 N을 나눌수 있는지 확인
//위 방법은 O(N), 최적화로 O(rootN)으로 줄일 수 있다.
//=>> 약수끼리 곱이 N이 되게끔 짝을 지을 수 있다는 성질 이용
//=>> rootN이하의 약수만 구하고 나머지 약수들은 N에서 구해진 약수들을 나누어 구할 수 있다.(단 제곱수인 경우는 중복 주의(ex) 4*4 = 16)
//
//vector<int> divisor(int n)
//{
//	vector<int> ret;
//
//	for (int i = 1; i * i <= n; i++)
//	{
//		if (n % i == 0) ret.push_back(i);
//	}
//	for (int i = ret.size() - 1; i >= 0; i--)
//	{
//		if (ret[i] * ret[i] == n) continue;
//		ret.push_back(n / ret[i]);
//	}
//
//	return ret;
//}

////최대공약수(gcd) : gcd(6,20) = 2
////최소공배수(lcm) : lcm(6,20) = 60
//
//gcd를 구하기 위해 두 수 a, b의 약수 목록을 찾아 공통된 원소를 찾을 수 있지만 유클리드호제법을 사용해  O(lg(max(A, B)))에 구할수 있다
//유클리드 호제법 : 두 수 a, b에 대해 a를 b로 나눈 나머지가 r이라면 gcd(a, b) = gcd(b, r) 임을 이용해 수를 줄여나가 최대 공약수를 구한다
//재귀적으로 구현한 유클리드 호제법
//int gcd(int a, int b)
//{
//	if (a == 0) return b;
//	return gcd(b % a, a);
//}
//include<numeric> 에는 gcd(int a,int b)라는 함수 구현.
//성질 1. 두 수 A, B의 공약수들은 GCD(A, B)의 모든 약수들이다.
//성질 2. 두 수 A, B의 공배수들은 LCM(A, B)의 모든 배수들이다.
//성질 3. A × B = GCD(A, B) × LCM(A, B)
//성질 4. GCD(n, n + 1) = 1

////합동식
//A≡B(mod m)이라는 기호의 의미는 A와 B가 m으로 나눈 나머지가 같다는 의미
//1.A + C ≡ B + C(mod m)
//2.A - C ≡ B - C(mod m)
//3.AC ≡ BC(mod m)
//4.A ÷ C ≡ B ÷ C(mod m)A÷C≡B÷C(modm)은 성립하지 않는다.
//(주로 int overflow를 피하기 위해 특정 값으로 나눈 나머지를 출력한 경우 이를 사용)
//+) 나머지를 구할 경우 몫이 음수면 나머지 또한 음수이다. 이를 처리해야함

////연립합동방정식
//주어진 M, N, x, y에 대해 A ≡ x(mod M), A ≡ y(mod N) 인 A 를 찾는 문제
//
//중국인의 나머지 정리를 사용하면  O(log M + log N)
//다른 방법을 사용해서 풀 때
//
//성질 1. A가 존재한다면 1~LCM(M, N)사이에 유일하게 존재한다
//성질 2. A가 존재할 필요충분조건은 x≡y(mod GCD(M, N))이다
//
//> A에 1부터 LCM(M, N)까지 차례때로 넣어보며 답을 구할 수 있다.LCM(M, N)이 아니고 MN까지 계산해도 결과는 동일.만족하는 A가 없으면 - 1출력
//= > BUT 시간복잡도가 O(MN)이므로 시간초과 확률이 높다
//
//> A ≡ x(mod M)이므로 A는 x * M, x * 2M, ....중 하나. 이런 A에 대해서만 확인한다
//위의 방법으로 시간 복잡도를 O(N)으로 개선
//boj 6064 카잉 달력

//식이 3개인 경우에도 위와 같은 방법으로 O(M+N)으로 줄일 수 있다

////이항계수와 팩토리얼
//색이 다른 공 n개 중에 r개를 순서가 존재하게 뽑는 경우 : 순열
//순서를 무시하고 뽑는 경우 : 조합
//
//n과 k가 10이하인 경우 이항계수(nCk)
//boj 11050 이항 계수 1
//
//n과 k가 1000이하인 경우
//최대 1000!을 int나 long long 에 담을 수 없다
//boj 11051 이항 계수 2
//modular inverse(합동식의 나눗셈)을 사용하면 10007을 이용하여 빠르게 계산할 수 있다. n,k이 최대 1000000이어도 계산 가능
//nCk=n−1Ck+n−1Ck−1 이라는 dp로 문제 해결
//
//boj 1676 팩토리얼 0의 개수
//n의 뒤에서부터 처음 0이 아닌 숫자가 나올 때까지 0의 개수가 k라는 것은 
//n이 10^k의 배수이면서 10^k+1의 배수는 아니라는 뜻
//n!을 소인수 분해 했을 때 n! = 2^a * 5^b * etc라면
//뒤에서부터 처음 0이 아닌 숫자가 나올때 까지 0이 min(a,b)개 나온다
//2가 5보다 많이 나오는것은 자명하니 5가 몇개 나오는지만 센다
//n은 최대 500. 1~n중 5의 배수의 갯수, 25의 배수의 갯수, 125의 배수의 갯수를 더한다

////파스칼의 삼각형
//: 자연수를 삼각형으로 배열한 것



//boj 1456 거의 소수
//boj 11653 소인수분해
//boj 2501 약수 구하기
//boj 9613 GCD 합
//boj 1978 소수 찾기
//boj 1929 소수 구하기
//boj 2407 조합
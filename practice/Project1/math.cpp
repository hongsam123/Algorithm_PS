////�Ҽ� - �Ҽ�������
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
//�ð����⵵ O(n)�� ���
//�׷��� ���⼭ i(n�� ��� �� ���� �۾� ���� ó�� ������ ��)��  O(sqrt(n))���� Ŭ�� ����.
//�̸� �̿��Ͽ� �ݺ����� i^2�� n������ ������ ������ �ð����⵵�� O(sqrt(N))���� ���� �� �ִ�.
//����) �̶� sqrt�Լ��� ����ϴ� ���� �Ǽ� ������ �߻��� �� �ֱ� ������ 
//	  i<=sqrt(n)��� i*i<=n�� �������
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
////�Ҽ� - �����佺�׳׽��� ü
//n������ �Ҽ��� ��� ã�� �˰��� �� �Ϲ������δ� 1~n���� ���� �Ҽ��������� ���� ������ �� �ִ�.
//������ �����佺�׳׽��� ü �˰����� ����ϸ� ���� ������� �޸𸮸� 13~40�� ������ �� ����
//1. nĭ¥�� �迭�� �����. �� �迭�� �ش� ĭ�� ���� �Ҽ��� ��� true, �Ҽ��� �ƴҰ�� false�� �ǹ��Ѵ�. 1�� false. �������� true�� �ʱ�ȭ.
//2. 2���� n���� �����ϸ� �ݺ��Ѵ�. 2���ƴ� ��� 2�� ����� false�� �����. 3�� ����.
//3. 4�� false�̹Ƿ� �ƹ� �۾����� �ʰ� �Ѿ��
//4. 5�� true�̹Ƿ� 5�� ������ 5�� ����� ��� false�� �����
//5. ���� �۾��� n�� ������ ������ �ݺ��Ѵ�. 
//6. �迭���� ���� true�� ����ĭ�� �� �Ҽ�.
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
//���� �����佺�׳׽��� ü�� �Ҽ� �������� n�� ������ ������� �� ������. 
//����ȭ1) ���� �ڵ忡���� i�� k�� �� 2k,3k,4k...�� ��� false�� �δµ�
//		�̰͵��� ���� 2,3,4...k-1�� ���������Ƿ� k���� ���� ���μ��� �����Ѵ�.
//		�� k���� ���� �Ű��� ���� �ʾƵ� �̹� false�� �Ǿ�����.
//		�׷��Ƿ� j�� 2i���� ������ �ƴ϶� i^2���� �����ϸ� �ȴ�
//����ȭ2) ���� ����ȭ�� ���� i^2�� n���� Ŀ���� �� �̻� �ƹ� ���� �ٲ��� �����Ƿ�
//		i^2�� n������ ���� ������
//����ȭ3) state�迭�� bool�� �ٲ۴�(�޸� ���� + ������ ���Խ� hit rate�� ���� �ӵ��� ������ ������ ��ģ��)
//
////����ȭ �� �����佺�׳׽��� ü
//vector<int> allPrime2(int n)
//{
//	vector<int> ret;
//	vector<bool> state(n + 1, true);
//	//n+1��ŭ ũ�⸦ ��� true�� �ʱ�ȭ ��Ű�� ����
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
//= > n������ �Ҽ��� ��� ã�� ���� �� ������ ���� �Ҽ� �����ϴ� �� ���� �ð��� �����Ѵ�.
//��Ȯ�� �ð����⵵�� O(nlogn)
//

//boj 1456 ���� �Ҽ�
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long a, b, ans;
const long long MAX = 10000000 + 1;
bool state[MAX];
vector<long long> prime;

void eratos()	//�Ҽ��Ǻ�
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
			//���⼭ if (prime[i] * num <= b) �� �ϸ� long long ������ �����
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
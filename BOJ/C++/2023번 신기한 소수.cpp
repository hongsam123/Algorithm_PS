#include<iostream>
using namespace std;

int n;

bool isPrime(int num)
{
	if (num == 1) return false;
	for (int i = 2; i*i <= num; i++)
	{
		if (num % i == 0)
			return false;
	}
	return true;
}

void func(int k, int num) {
	if (n == k) {
		cout << num << "\n";
		return;
	}
	for (int i = 1; i <= 9; i++) {
		int x = num * 10 + i;
		if (isPrime(x)) {
			func(k + 1, x);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	func(0, 0);

	return 0;
}

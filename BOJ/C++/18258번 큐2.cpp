#include<iostream>
using namespace std;

const int MX = 2000001;
int dat[MX];
int head = 0, tail = 0;

void pop() {
	head += 1;
}

int front() {
	return dat[head];
}

int back() {
	return dat[tail - 1];
}

int  main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, num;
	cin >> n;

	string input;

	while (n--) {
		cin >> input;
		if (input == "push")
		{
			cin >> num;
			dat[tail++] = num;
		}
		else if (input == "pop")
		{
			if (head == tail)
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << dat[head++] << '\n';
			}
		}
		else if (input == "size")
		{
			cout << tail - head << '\n';
		}
		else if (input == "empty")
		{
			if (head == tail)
				cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (input == "front")
		{
			if (head == tail)
				cout << -1 << '\n';
			else cout << dat[head]<<'\n';
		}
		else
		{
			if (head == tail)
				cout << -1 << '\n';
			else cout << dat[tail-1]<<'\n';
		}
	}

	return 0;
}

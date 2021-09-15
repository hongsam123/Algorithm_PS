```c++
#include<iostream>
using namespace std;

const int mx = 1000005;
int dat[mx];
int head = 0, tail = 0;

void push(int x) {
	//dat[tail] = x;
	//tail += 1;
	dat[tail++] = x;
}

void pop() {
	head += 1;
}

int front() {
	return dat[head];
}

int back() {
	return dat[tail - 1];
}

void test() {
	push(10); push(20); push(30);
	cout << front() << '\n'; // 10
	cout << back() << '\n'; // 30
	pop(); pop();
	push(15); push(25);
	cout << front() << '\n'; // 30
	cout << back() << '\n'; // 25
}

int main(void) {
	test();
}
```

<br/><br/>

```c++
#include<iostream>
#include<queue>
using namespace std;


int  main(void)
{
	queue<int> q;
	q.push(10);
	q.push(20);
	q.push(30);
	cout << q.size() << '\n';

	if (q.empty()) cout << "queue is empty\n";
	else cout << "queue is not empty\n";
	q.pop();
	cout << q.front() << "\n";
	cout << q.back() << '\n';

	q.push(40);
	q.pop();

	cout << q.front() << '\n';
	return 0;
}
```

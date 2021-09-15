```c++
#include<iostream>
using namespace std;

const int mx = 1000005;
int dat[mx];
int pos = 0;

void push(int x)
{
	if (pos != mx)
	{
		dat[pos] = x;
		pos++;
	}
}

void pop()
{
	if (pos != 0)
	{
		pos--;
	}
}

int top()
{
	return dat[pos-1];
}

void test()
{
	push(5); push(4); push(3);
	cout << top() << '\n'; // 3
	pop(); pop();
	cout << top() << '\n'; // 5
	push(10); push(12); 
	cout << top() << '\n'; // 12
	pop();
	cout << top() << '\n'; // 10
}

int main(void)
{
	test();
	return 0;
}
```

<br/><br/>

```c++
#include<iostream>
#include<stack>
using namespace std;

int main(void)
{
	stack<int> s;

	s.push(10);
	s.push(20);
	s.push(30);
	cout << s.size() << '\n';

	if (s.empty()) cout << "stack is empty\n";
	else cout << "stack is not empty\n";

	s.pop();
	cout<<s.top()<<'\n';
	s.pop();
	cout << s.top() << '\n';
	s.pop();

	if (s.empty()) cout << "stack is empty\n";
	else cout << "stack is not empty\n";
}
```
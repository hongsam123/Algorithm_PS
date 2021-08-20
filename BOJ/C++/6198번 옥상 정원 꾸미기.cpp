#include<iostream>
#include<stack>
using namespace std;

stack<long long> s;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	long long x;
	cin >> n;

	long long cnt = 0;

	while (n--)
	{
		cin >> x;

		while (!s.empty() && x >= s.top())
			s.pop();
		cnt += s.size();

		s.push(x);
	}
	cout << cnt;

	return 0;
}

//처음 시도했던 시간초과 나는 코드
//#include<iostream>
//#include<stack>
//using namespace std;
//
//stack<int> s;
//stack<int> tmp;
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int n, x;
//	cin >> n;
//
//	int cnt = 0;
//
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> x;
//
//		while (!s.empty())
//		{
//			if (x < s.top())
//			{
//				cnt++;
//				tmp.push(s.top());
//			}
//			s.pop();
//		}
//
//		while (!tmp.empty())
//		{
//			s.push(tmp.top());
//			tmp.pop();
//		}
//		s.push(x);
//	}
//
//	cout << cnt;
//
//	return 0;
//}
 

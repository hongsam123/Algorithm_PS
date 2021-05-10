#include<iostream>
#include<deque>
using namespace std;

deque<int> dq;
deque<int> dq1;
deque<int> dq2;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, val;
	int cnt = 0;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		dq.push_back(i);

	while (m--)
	{
		int cnt1 = 0, cnt2 = 0;
		cin >> val;
		dq1 = dq;
		dq2 = dq;

		while (dq1.front() != val)		//왼쪽으로 이동시키는 연산 수행 시 최솟값 
		{
			dq1.push_back(dq1.front());
			dq1.pop_front();
			cnt1++;
		}
		dq1.pop_front();

		while (dq2.front() != val)		//오른쪽으로 이동시키는 연산 수행시 최솟값 
		{
			dq2.push_front(dq2.back());
			dq2.pop_back();
			cnt2++;
		}
		dq2.pop_front();
		//cnt2 = dp1.size() - cnt1 으로 간단하게 구할 수 있다 
		//또는 target 값의 index를 찾아 cnt를 구할 수 있음 

		if (cnt1 >= cnt2)				//둘 중 작은 값을 count
		{
			cnt += cnt2;
			dq = dq2;
		}
		else
		{
			cnt += cnt1;
			dq = dq1;
		}
	}
	cout << cnt;

	return 0;
}

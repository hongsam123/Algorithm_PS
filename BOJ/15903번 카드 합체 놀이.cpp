#include<iostream>
#include<queue>
using namespace std;

long long n, m;
priority_queue<long long, vector<long long>, greater<long long>> pq;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (long long i = 0; i < n; i++)
	{
		long long x;
		cin >> x;
		pq.push(x);
	}

	while (m--)
	{
		long long a = pq.top();	pq.pop();
		long long b = pq.top();	pq.pop();

		long long sum = a + b;
		pq.push(sum);
		pq.push(sum);
	}

	long long size = pq.size();
	long long answer = 0;
	for (long long i = 0; i < size; i++)
	{
		long long x = pq.top();
		answer += x;
		pq.pop();
	}

	cout << answer;

	return 0;
}


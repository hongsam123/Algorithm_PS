#include<iostream>
#include<queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		pq.push(x);
	}

	if (pq.size() == 1)
	{
		cout << 0;
		return 0;
	}

	int total = 0;
	while (pq.size() != 1)
	{
		int x = pq.top(); pq.pop();
		int y = pq.top(); pq.pop();
		int sum = x + y;
		total += sum;
		pq.push(sum);
	}

	cout << total;

	return 0;
}

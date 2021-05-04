#include<iostream>
#include<queue>
using namespace std;

priority_queue<long long,vector<long long>,greater<long long>> pq;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	while (n--)
	{
		long long x;
		cin >> x;
		if (x == 0)
		{
			if (pq.empty())
				cout << 0 << "\n";
			else
			{
				long long num = pq.top(); pq.pop();
				cout << num << "\n";
			}
		}
		else
		{
			pq.push(x);
		}
	}

	return 0;
}


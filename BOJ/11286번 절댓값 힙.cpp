#include<iostream>
#include<queue>
#include<map>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
map<int, int> m;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	while (n--)
	{
		int x;
		cin >> x;

		if (x == 0)
		{
			if (pq.empty())
				cout << 0 << "\n";
			else
			{
				int num = pq.top(); pq.pop();
				if (m[num * -1] > 0)
				{
					m[num * -1]--;
					cout << num * -1 << "\n";
				}
				else
				{
					m[num]--;
					cout << num << "\n";
				}

			}
		}
		else
		{
			if (m[x] > 0)
				m[x]++;
			else
				m[x] = 1;
			pq.push(abs(x));
		}
	}

	return 0;
}

#include<iostream>
#include<vector>
using namespace std;

int t, n;

int gcd(int a, int b)
{
	if (a == 0) return b;
	return gcd(b % a, a);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	while (t--)
	{
		cin >> n;
		vector<int> v;

		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			v.push_back(x);
		}

		long long sum = 0;
		for (int i = 0; i < v.size()-1; i++)
		{
			for (int j = i+1; j < v.size(); j++)
			{
				if (i == j) continue;
				sum += gcd(v[i], v[j]);
			}
		}
		cout << sum << "\n";
	}

	return 0;
}

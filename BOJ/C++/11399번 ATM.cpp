#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n;
int person[1002];
vector<int> time;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		time.push_back(t);
	}

	sort(time.begin(), time.end());

	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		for (int j = 0; j <= i; j++)
		{
			sum += time[j];
		}
		person[i] = sum;
	}

	int total = 0;
	for (int i = 0; i < n; i++)
		total += person[i];

	cout << total;

	return 0;
}

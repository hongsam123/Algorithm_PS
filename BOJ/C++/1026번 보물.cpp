//재배열 부등식
//하나의 배열을 오름차순, 다른 배열을 내림차순으로 재배열하고
//순서대로 각각 배열의 원소를 곱해서 더했을 때 합이 최소가 된다
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	
	vector<int> a;
	vector<int> b;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		a.push_back(x);
	}
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		b.push_back(x);
	}

	sort(a.begin(), a.end());
	sort(b.rbegin(), b.rend());

	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += a[i] * b[i];
	}

	cout << sum;

	return 0;
}

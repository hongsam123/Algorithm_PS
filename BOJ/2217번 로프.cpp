//사용할 로프의 개수를 k개로 정해놨다고 생각.
//로프의 최대 중량을 정렬한 후 로프를 k개 고른다면
//w[n-k]*k
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

	vector<int> w;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		w.push_back(x);
	}
	sort(w.begin(), w.end());

	int max_w = 0;
	for (int k = 1; k <= n; k++)
		max_w = max(max_w, w[n - k] * k);

	cout << max_w;

	return 0;
}

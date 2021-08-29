//����� ������ ������ k���� ���س��ٰ� ����.
//������ �ִ� �߷��� ������ �� ������ k�� ���ٸ�
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

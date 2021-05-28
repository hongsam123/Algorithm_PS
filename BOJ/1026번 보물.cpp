//��迭 �ε��
//�ϳ��� �迭�� ��������, �ٸ� �迭�� ������������ ��迭�ϰ�
//������� ���� �迭�� ���Ҹ� ���ؼ� ������ �� ���� �ּҰ� �ȴ�
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

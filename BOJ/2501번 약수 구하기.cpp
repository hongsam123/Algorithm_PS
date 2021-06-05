//#include<iostream>
//using namespace std;
//
//int n, k;
//
//int main()
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> n >> k;
//
//	int cnt = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		if (n % i == 0)
//			cnt++;
//		if (cnt == k)
//		{
//			cout << i;
//			return 0;
//		}
//	}
//	
//	cout << 0;
//
//	return 0;
//}
//�� ����ȭ(�� ���������� �ð� ���̰� ũ�� �ʴ�) 
#include<iostream>
#include<vector>
using namespace std;

int n, k;
vector<int> v;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	int cnt = 0;
	for (int i = 1; i*i <= n; i++)
		if (n % i == 0) v.push_back(i);

	if (k <= v.size())
	{
		cout << v[k - 1];
		return 0;
	}

	for (int i = v.size() - 1; i >= 0; i--)
	{
		if (v[i] * v[i] == n) continue;
		v.push_back(n / v[i]);
	}

	if (k <= v.size())
		cout << v[k - 1];
	else
		cout << 0;

	return 0;
}

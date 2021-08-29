//(merge sort)
//#include<iostream>
//using namespace std;
//
//int n, m;
//int a[1000002];
//int b[1000002];
//int ans[2000004];
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> n >> m;
//
//	for (int i = 0; i < n; i++)
//		cin >> a[i];
//
//	for (int i = 0; i < m; i++)
//		cin >> b[i];
//
//	int i = 0;
//	int j = 0;
//	for (int k = 0; k < n + m; k++)
//	{
//		if (i == n)
//		{
//			ans[k] = b[j];
//			j++;
//			continue;
//		}
//		else if (j == m)
//		{
//			ans[k] = a[i];
//			i++;
//			continue;
//		}
//
//		if (a[i] <= b[j])
//			//merge sort�� stable sort�� ���� �����ϸ�
//			//a[i]�� b[j]�� ���� �� �� ���� ���� a[i]�� ���� ���� ���� ����
//		{
//			ans[k] = a[i];
//			i++;
//		}
//		else
//		{
//			ans[k] = b[j];
//			j++;
//		}
//	}
//	for (int i = 0; i < n + m; i++)
//	{
//		cout << ans[i] << " ";
//	}
//
//	return 0;
//}

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, m;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	vector<int> v;
	for (int i = 0; i < n + m; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(),v.end());

	for (int i = 0; i < n + m; i++)
	{
		cout << v[i] << " ";
	}

	return 0;
}

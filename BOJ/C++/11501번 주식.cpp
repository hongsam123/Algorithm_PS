//ó�� Ǯ�� : ������ �ֽ��� ������ ��ٰ� �ֽ��� �������� ���� �Ǵ�.
//�ùٸ� Ǯ�� : ���� �ְ��� ������ ���� ���� ��ΰ� �� �� �ִ� �� �Ǵ�. 
#include<iostream>
#include<vector>
using namespace std;

int t, n;

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

		int max_n = v.back();
		int pre = v.back();
		long long total = 0;
		for (int i = v.size() - 2; i >= 0; i--)	//�ڿ������� ���� ��
		{
			if (v[i] > pre && max_n < v[i])	//�����ϸ� �ִ밪�� ����
			{
				max_n = v[i];
			}
			else
				//�����ϸ� ���� �ִ밪�� �ֽ��� �Ⱦƾ��ϴ� �ִ밪
			{
				total += max_n - v[i];
			}
			pre = v[i];
		}

		cout << total << "\n";
	}

	return 0;
}

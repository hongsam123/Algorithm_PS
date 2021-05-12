//���� �� �Ÿ��� ��� �ްԼҸ� ����� �׸����� ����������
//���� Ž���� ����ȭ������ ���� ������ Ǯ �� �ִ� �Ķ��Ʈ�� Ž��
//(������ ũ�Ⱑ �۾Ƽ� �̺� Ž���� �� �ؾ��� �ʿ�� ����)
//�̹� �����ϴ� �ްԼ� ���� ������ �Ÿ��� �ΰ� ���ο� �ްԼҸ� ���� ��
//���� �ްԼ��� ������ m���� ���������� �Ѵ�
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> v;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, l;
	cin >> n >> m >> l;

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}
	v.push_back(0);
	v.push_back(l);
	//�Ÿ��� ���۰� ������
	sort(v.begin(), v.end());

	//parameteric search
	int left = 1;
	int right = l - 1;
	int mid = 0;
	while (left <= right)
	{
		mid = (left + right) / 2;	//���� �������� ���� ������ ���� �Ÿ�
		int new_store = 0;
		for (int i = 1; i < v.size(); i++)
		{
			int dist = v[i] - v[i - 1];
			new_store += dist / mid;	//������ �ִ� �� ������ ���� ���� �� �ִ� ������ ����
			if (dist % mid == 0)	//������ �������� ��ġ�� �ϳ��� ���ش�
				new_store--;
		}
		
		if (new_store > m)	//�������� �ʹ� ���� ����
			left = mid + 1;	//������ ���� �Ÿ��� ������ ���δ�
		else
			right = mid - 1;	//�������� �� ������ �Ѵٸ� ������ ������
	}

	cout << left;

	return 0;
}

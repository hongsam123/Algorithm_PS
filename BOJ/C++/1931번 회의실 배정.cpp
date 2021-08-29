//���� : ���� �ּ��� ������ ���� �ʾ��� ��� 
//		�ּ��� ������ ���� �� ���� �� ����� ������ �� ���ٴ� ���� ���δ�
//�׸��� - ���� �ð� t���� �����Ҽ� �ִ� ��� ȸ�� �� ����
//			���� ������ ȸ�Ǹ� ����
//�׸��� ���� - ���� ���� ������ ȸ�Ǹ� �������� �ʾ��� ���
//				����Ǵ� ������ ȸ���� ������
//				���� ���� ������ ȸ�Ǹ� �������� ���
//				����Ǵ� ������ ȸ���� ���� ũ�ų� ���� (���� ����� ����ŭ�� �����ϱ� ������)
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<pair<int, int>> v;

	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v.push_back({ y,x });
	}

	sort(v.begin(), v.end());

	int t = 0;
	int cnt = 0;

	for (int i = 0; i < v.size(); i++)
	{
		if (t > v[i].second) continue;
		cnt++;
		t = v[i].first;
	}

	cout << cnt;

	return 0;
}

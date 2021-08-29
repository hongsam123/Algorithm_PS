#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n;

bool comp(const string& a, const string& b)
//�Լ��� ���ڷ� stl�̳� ����ü ��ü�� �Ǿ ������ �Ͼ�� ���� ���綧����
//�׳� string a, string b�� ������ ���� �ٶ��� ���� �ʴ�(���ʿ��� ���� �߻�)
//�׷��Ƿ� ���� ���� reference�� �����°��� �ٶ���
{
	if (a.length() != b.length()) return a.length() < b.length();
	//���̰� �ٸ��� ó��

	int asum = 0;
	int bsum = 0;
	for (int i = 0; i < a.length(); i++)
		if (0 <= a[i] - '0' && a[i] - '0' <= 9)
			asum += a[i] - '0';
	for (int i = 0; i < b.length(); i++)
		if (0 <= b[i] - '0' && b[i] - '0' <= 9)
			bsum += b[i] - '0';
	if (asum != bsum) return asum < bsum;
	//���� �����϶�, �� �ڸ��� �� ������ �͸� ���� �� ũ������� ó��

	int idx = 0;
	while (1)
	{
		if (idx == a.length()) break;
		if (a[idx] != b[idx]) break;
		idx++;
	}
	if (idx == a.length()) return false;
	else return a[idx] < b[idx];
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	vector<string> v;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		v.push_back(str);
	}

	sort(v.begin(), v.end(),comp);

	for (int i = 0; i < n; i++)
	{
		cout << v[i] << "\n";
	}

	return 0;
}


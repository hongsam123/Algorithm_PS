//���丮���� dp�� ����ؾ���
//long long �� ����ص� ������ ����� ����
//������ ū ���� ���� ���ڹ迭�� �̿��� ����
//�Ľ�Į �ﰢ�� + string ���� ���� �迭 a,b�� �ڿ������� ���ذ��� ���ο� ���ڹ迭 result�� ����� ������ ������
//���� �����ذ��� �ø��� sum�� ������ ������
#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
string comb[102][102];

string bigNumAdd(string n1, string n2)
{
	long long sum = 0;
	string result;

	//�� �ڿ������� ���ϱ� �����Ѵ�

	while (!n1.empty() || !n2.empty() || sum)
	{
		if (!n1.empty())
		{
			sum += n1.back() - '0';
			n1.pop_back();
		}
		if (!n2.empty())
		{
			sum += n2.back() - '0';
			n2.pop_back();
		}
		result.push_back((sum % 10) + '0');
		sum = sum / 10;
	}

	//result�� �������ֱ�
	reverse(result.begin(), result.end());

	return result;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		comb[i][0] = comb[i][i] = "1";
		for (int j = 1; j < i; j++)
		{
			comb[i][j] = bigNumAdd(comb[i - 1][j] , comb[i - 1][j - 1]);
		}
	}

	cout << comb[n][m];


	return 0;
}

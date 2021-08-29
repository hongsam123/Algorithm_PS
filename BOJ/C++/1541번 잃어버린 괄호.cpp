#include<iostream>
#include<vector>
using namespace std;

vector<int> plus_v;
vector<int> minus_v;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str;
	cin >> str;

	string pre_num = "";
	int ans = 0;
	int i = 0;
	bool plus = true;

	while(1)
	{
		if (i >= str.size()) 
		{
			int num = 0;
			int x = 1;
			for (int j = pre_num.size() - 1; j >= 0; j--)
			{
				num += (pre_num[j] - '0') * x;
				x *= 10;
			}
			if (plus)
				plus_v.push_back(num);
			else
				minus_v.push_back(num);
			break;
		}

		if (str[i] - '0' >= 0 && str[i] - '0' <= 9)
		{
			pre_num += str[i];
		}
		else
		{
			int num = 0;
			int x = 1;
			for (int j = pre_num.size() - 1; j >= 0; j--)
			{
				num += (pre_num[j]-'0') * x;
				x *= 10;
			}

			if (str[i] == '-')
			{
				if (plus)
					plus_v.push_back(num);
				else
					minus_v.push_back(num);
				plus = false;
				pre_num = "";
			}
			else
			{
				if (plus)
					plus_v.push_back(num);
				else
					minus_v.push_back(num);
				pre_num = "";
			}
		}
		
		i++;
	}


	for (int i = 0; i < plus_v.size(); i++)
	{
		ans += plus_v[i];
	}
	for (int i = 0; i < minus_v.size(); i++)
	{
		ans -= minus_v[i];
	}

	cout << ans;


	return 0;
}
//�̷��� Ǯ�� �ʰ� 
//���̳ʽ��� ������ ������ ���� ������ 
//���̳ʽ��� ������ �� �� ������ ��� ���ؼ� ����ȴ� 

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, m;
int day[101];
int score[101];
int cnt;	//�Խ��ǿ� �ö�� �ִ� �л� ��

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int x;
		cin >> x;
		//���� �÷���
		if (score[x] > 0)	//�Խ��ǿ� �ö�� ������
		{
			score[x]++;
		}
		else
		{
			if (cnt < n)
			{
				cnt++;
				score[x]++;
			}
			else
			{
				int min_sc = 100001;
				vector<pair<int,int>> min_st;	//�л���ȣ, ���ھ�
				for (int i = 0; i < 101; i++)
				{
					if (score[i] > 0 && min_sc >= score[i])
					{
						min_sc = score[i];
						min_st.push_back({ i,score[i] });
					}
				}

				int long_day = 0;
				int long_st;
				for (auto st:min_st)
				{
					if (st.second != min_sc) continue;
					if (day[st.first] > long_day)
					{
						long_st = st.first;
						long_day = day[st.first];
					}
				}

				score[long_st] = 0;
				day[long_st] = 0;
				score[x]++;
			}
		}

		//�ð� �÷���
		for (int i = 0; i < 101; i++)
		{
			if (score[i] > 0)
				day[i]++;
		}

	}

	for (int i = 0; i < 101; i++)
	{
		if (score[i] > 0)
			cout << i << " ";
	}

	return 0;
}

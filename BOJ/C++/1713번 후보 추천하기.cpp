#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, m;
int day[101];
int score[101];
int cnt;	//게시판에 올라와 있는 학생 수

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int x;
		cin >> x;
		//점수 플러스
		if (score[x] > 0)	//게시판에 올라와 있으면
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
				vector<pair<int,int>> min_st;	//학생번호, 스코어
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

		//시간 플러스
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

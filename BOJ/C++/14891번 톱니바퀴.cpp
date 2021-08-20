#include<iostream>
#include<deque>
#include<vector>
#include<algorithm>
using namespace std;

vector<deque<int>> gear(4);
int dir[4];	// 1:시계방향, -1:반시계방향, 0:회전하지x
int k;
int ans;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 4; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < 8; j++)
		{
			gear[i].push_back(str[j] - '0');
		}
	}

	cin >> k;

	while (k--)
	{
		//방향 초기화
		fill(dir, dir + 4, 0);

		int x, nd;
		cin >> x >> nd;

		//방향 설정
		dir[x-1] = nd;

		if (x == 1)
		{
			if (gear[0][2] != gear[1][6])
				dir[1] = dir[0] * -1;

			if (gear[1][2] != gear[2][6])
				dir[2] = dir[1] * -1;

			if (gear[2][2] != gear[3][6])
				dir[3] = dir[2] * -1;

		}
		else if (x == 2)
		{
			if (gear[0][2] != gear[1][6])
				dir[0] = dir[1] * -1;

			if (gear[1][2] != gear[2][6])
				dir[2] = dir[1] * -1;

			if (gear[2][2] != gear[3][6])
				dir[3] = dir[2] * -1;
		}
		else if (x == 3)
		{
			if (gear[1][2] != gear[2][6])
				dir[1] = dir[2] * -1;

			if (gear[0][2] != gear[1][6])
				dir[0] = dir[1] * -1;

			if (gear[2][2] != gear[3][6])
				dir[3] = dir[2] * -1;
		}
		else
		{
			if (gear[2][2] != gear[3][6])
				dir[2] = dir[3] * -1;

			if (gear[1][2] != gear[2][6])
				dir[1] = dir[2] * -1;

			if (gear[0][2] != gear[1][6])
				dir[0] = dir[1] * -1;
		}

		//돌리기
		for (int i = 0; i < 4; i++)
		{
			if (dir[i] == 1)	//시계 방향
			{
				int pole = gear[i].back();
				gear[i].pop_back();
				gear[i].push_front(pole);
			}

			if (dir[i] == -1)	//반시계 방향
			{
				int pole = gear[i].front();
				gear[i].pop_front();
				gear[i].push_back(pole);
			}
		}
	}

	if (gear[0][0] == 1)
		ans += 1;
	if (gear[1][0] == 1)
		ans += 2;
	if (gear[2][0] == 1)
		ans += 4;
	if (gear[3][0] == 1)
		ans += 8;

	cout << ans;

	return 0;
}

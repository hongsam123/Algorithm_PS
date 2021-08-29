#include<iostream>
#include<queue>
#include<deque>
#include<utility>
using namespace std;

int n, w, l;
queue<int> not_pass;
deque<pair<int,int>> bridge;	//<�ٸ��� �ִ� ���� �ð�,����>

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> w >> l;

	for (int i = 0; i < n; i++)
	{
		int wei;
		cin >> wei;
		not_pass.push(wei);
	}
	
	int time = 0;
	int bri_l = 0;
	int bri_w = 0;

	while (1)
	{
		//�ٸ����� Ʈ�� �̵�
		if (!bridge.empty())
		{ 
			int size = bridge.size();
			bool del = false;
			for (int i=0;i<size;i++)
			{
				pair<int, int> cur = bridge[i];
				if (cur.first == w)	//Ʈ���� �ٸ��� ������ ���
				{
					bri_l -= cur.second;
					bri_w -= 1;
					del = true;
				}
				else
					bridge[i].first += 1;	//�ٸ� ������ �̵�
			}
			if (del)
				bridge.pop_front();
		}

		//�ٸ��� Ʈ���� �ö� �� �ִٸ� �ö󰡱�
		if (!not_pass.empty())
		{
			int e = not_pass.front();
			if (bri_w < w && bri_l + e <= l)
			{
				not_pass.pop();		//��� ť���� ����

				bridge.push_back({ 1,e });	//�ٸ����� �̵�
				bri_l += e;
				bri_w += 1;
			}
		}

		time++;

		if (bridge.empty() && not_pass.empty()) break;	//�ٸ� ��, ��� ť ��� ������� Ż��
	}
	cout << time;

	return 0;
}

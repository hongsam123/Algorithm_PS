#include<iostream>
#include<queue>
#include<deque>
#include<utility>
using namespace std;

int n, w, l;
queue<int> not_pass;
deque<pair<int,int>> bridge;	//<다리에 있던 단위 시간,무게>

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
		//다리에서 트럭 이동
		if (!bridge.empty())
		{ 
			int size = bridge.size();
			bool del = false;
			for (int i=0;i<size;i++)
			{
				pair<int, int> cur = bridge[i];
				if (cur.first == w)	//트럭이 다리를 나가는 경우
				{
					bri_l -= cur.second;
					bri_w -= 1;
					del = true;
				}
				else
					bridge[i].first += 1;	//다리 위에서 이동
			}
			if (del)
				bridge.pop_front();
		}

		//다리에 트럭이 올라갈 수 있다면 올라가기
		if (!not_pass.empty())
		{
			int e = not_pass.front();
			if (bri_w < w && bri_l + e <= l)
			{
				not_pass.pop();		//대기 큐에서 삭제

				bridge.push_back({ 1,e });	//다리위로 이동
				bri_l += e;
				bri_w += 1;
			}
		}

		time++;

		if (bridge.empty() && not_pass.empty()) break;	//다리 위, 대기 큐 모두 비었으면 탈출
	}
	cout << time;

	return 0;
}

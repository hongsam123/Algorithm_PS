#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int n, k;
queue<int> q;
int dist[100002];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	fill(dist, dist + 100001, -1);

	q.push(n);
	dist[n] = 0;

	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		if (cur == k)	//������ ã���� ����
		{
			cout << dist[cur];
			return 0;
		}

		//�����̵�
		int teleport = cur * 2;
		if (teleport <= 100000 && dist[teleport] == -1)
		{
			dist[teleport] = dist[cur];
			q.push(teleport);
		}

		//�������� �ȱ�
		int dleft = cur - 1;
		if (dleft >= 0 && dist[dleft] == -1)	//���ο� ��ġ�� ������ ����� �ʰ� �湮���� �������̶��
		{
			dist[dleft] = dist[cur] + 1;	//�ð��� �����ϰ�
			q.push(dleft);					//ť�� �ֱ�
		}

		//���������� �ȱ�
		int dright = cur + 1;
		if (dright <= 100000 && dist[dright] == -1)
		{
			dist[dright] = dist[cur] + 1;
			q.push(dright);
		}
	}

	return 0;
}

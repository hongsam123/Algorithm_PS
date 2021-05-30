#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int n, k;
queue<int> q;
int dist[100002];
int pre[100002];	//��� ������ �迭
//ó���� ť�� ���� ��θ� ��� ������ ���͸� �ְ� bfs�� ������
//cur.back()���� ��� �� ���������� �� ��Ұ� k���� Ȯ���ߴµ�
//�׷����ϸ� 100000���� 0���� ���� ��� ť�� ���� ���Ϳ� 100000,99999,99998...�� ��� �� �ð��ʰ� 
vector<int> v;

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
			cout << dist[cur] << "\n";

			//���� �������� �Ųٷ� ��� ����
			for (int i = k; i != n; i = pre[i])
				v.push_back(i);
			v.push_back(n);

			//�Ųٷ� ���
			for (int i = v.size() - 1; i >= 0; i--)
				cout << v[i] << " ";
			return 0;
		}

		//�������� �ȱ�
		int dleft = cur - 1;
		if (dleft >= 0 && dist[dleft] == -1)
		{
			dist[dleft] = dist[cur] + 1;
			pre[dleft] = cur;	//���ο� ��ġ�� ���� �� ��� ������ �迭�� ���� ��ġ�� ����
			q.push(dleft);
		}

		//���������� �ȱ�
		int dright = cur + 1;
		if (dright <= 100000 && dist[dright] == -1)
		{
			dist[dright] = dist[cur] + 1;
			pre[dright] = cur;
			q.push(dright);
		}

		//�����̵�
		int teleport = cur * 2;
		if (teleport <= 100000 && dist[teleport] == -1)
		{
			dist[teleport] = dist[cur] + 1;
			pre[teleport] = cur;
			q.push(teleport);
		}
	}

	return 0;
}

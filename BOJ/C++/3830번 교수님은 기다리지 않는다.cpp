#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
int parent[100002];
int dist[100002];

void init()
{
	for (int i = 1; i <= n; i++)
		parent[i] = i;
	fill(dist, dist + n + 1, 0);
}

int find(int a)
{
	//1. root�� ��� ���� unionfind ����
	if (parent[a] == a) return a;
	//2. root�� �ƴ� ��� root���� �Ÿ��� ���ؼ� ����
	int pid = find(parent[a]);
	dist[a] += dist[parent[a]];		//dist[a]�� �ڽ��� �ٷ� �ռ� dist[parent[a]]�� ���ϰ� 
	return parent[a] = find(pid);	//return �� parent[a]�� ����
}

void Union(int a, int b, int dif)
{
	int pa = find(a);
	int pb = find(b);

	//��Ʈ�� ������ �̹� ���� �׷��̹Ƿ� ����(�Ÿ� ����� �Ǿ�����)
	if (pa == pb) return;

	//parent����, ���� ���� ����
	dist[pb] = dist[a] - dist[b] + dif;
	parent[pb] = pa;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (1)
	{
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;

		init();

		while (m--)
		{
			char op;
			int a, b, w;
			cin >> op >> a >> b;
			//���Ը� ��� ��� - �Ǵ� ������ �׷����� union
			if (op == '!')
			{
				cin >> w;
				Union(a, b, w);
			}
			//���Ը� �Ǵ��ϴ� ���
			else
			{
				//���Ը� �Ǵ��� �� ���� ��� (��Ʈ�� �ٸ� ���)
				if (find(a) != find(b))
					cout << "UNKNOWN\n";
				//���Ը� �Ǵ��� �� �ִ� ���
				else
					cout << dist[b] - dist[a] << "\n";
			}
		}
	}


	return 0;
}


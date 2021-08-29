#include<iostream>
#include<algorithm>
#include<vector>
using  namespace std;

int n, m;
vector<int> edge[100002];
int depth[100002];
int parent[20][100001];
int expo;

void initTree(int node, int p = 0)
{
	//depth�� �θ��� ����
	depth[node] = depth[p] + 1;
	parent[0][node] = p;

	//�ش� node dp �ʱ�ȭ
	for (int k = 1; k < expo; k++)
		parent[k][node] = parent[k - 1][parent[k - 1][node]];

	for (auto child : edge[node])
	{
		if (child == p) continue;
		initTree(child, node);
	}
}

int lca(int a, int b)
{
	//���̰� �ٸ����
	if (depth[a] != depth[b])
	{
		if (depth[a] > depth[b]) swap(a, b);	//b�� �� ���� ���
		for (int k = expo; k >= 0; k--)
		{
			//���̰� ���� ��带 ����ø�
			if (depth[a] <= depth[parent[k][b]])
				b = parent[k][b];
		}
	}

	int ans = a;
	if (a != b)	//a�� b�� �ٸ���� �ٽ� ����
	{
		for (int k = expo - 1; k >= 0; k--)
		{
			if (parent[k][a] != parent[k][b])
			{
				a = parent[k][a];
				b = parent[k][b];
			}
			ans = parent[k][a];
		}
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i *= 2)
		expo++;

	for (int i = 1; i < n ; i++)
	{
		int u, v;
		cin >> u >> v;
		
		edge[u].push_back(v);
		edge[v].push_back(u);
	}

	//Ʈ�� �ʱ�ȭ
	initTree(1);

	cin >> m;
	
	while (m--)
	{
		int u, v;
		cin >> u >> v;
		
		cout << lca(u, v) << "\n";
	}

	return 0;
}


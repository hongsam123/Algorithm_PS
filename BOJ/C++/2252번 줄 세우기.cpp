#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int n, m;
int inDegree[32002];
int answer[32002];
vector<int> edge[32002];
int cnt;
queue<int> q;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	//1.��������(inDegree) input
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;

		//a<b
		edge[a].push_back(b);
		inDegree[b]++;
	}

	//2. �������� 0�ξֵ� queue�� �ֱ�
	for (int i = 1; i <= n; i++)
		if (inDegree[i] == 0) q.push(i);

	//3. queue���� 1���� �����鼭 ����� ���� ����
	//string str;
	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		cout << cur<<" ";

		//����� ����
		for (auto e : edge[cur])
		{
			//1)�������� inDegree-1
			inDegree[e]--;
			if (inDegree[e] == 0)
				q.push(e);
		}
	}

	return 0;
}

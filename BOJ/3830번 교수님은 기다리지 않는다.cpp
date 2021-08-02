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
	//1. root인 경우 기존 unionfind 동일
	if (parent[a] == a) return a;
	//2. root가 아닌 경우 root와의 거리를 구해서 갱신
	int pid = find(parent[a]);
	dist[a] += dist[parent[a]];		//dist[a]에 자신의 바로 앞선 dist[parent[a]]를 더하고 
	return parent[a] = find(pid);	//return 시 parent[a]를 갱신
}

void Union(int a, int b, int dif)
{
	int pa = find(a);
	int pb = find(b);

	//루트가 같으면 이미 같은 그룹이므로 종료(거리 계산이 되어있음)
	if (pa == pb) return;

	//parent변경, 무게 차이 갱신
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
			//무게를 재는 경우 - 판단 가능한 그룹으로 union
			if (op == '!')
			{
				cin >> w;
				Union(a, b, w);
			}
			//무게를 판단하는 경우
			else
			{
				//무게를 판단할 수 없는 경우 (루트가 다른 경우)
				if (find(a) != find(b))
					cout << "UNKNOWN\n";
				//무게를 판단할 수 있는 경우
				else
					cout << dist[b] - dist[a] << "\n";
			}
		}
	}


	return 0;
}


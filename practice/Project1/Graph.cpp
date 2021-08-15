////���� ��ķ� ǥ���ϴ� �׷���
////Directed Graph(������ �ִ� �׷���)
//int matrix[10][10];
//int v, e;
//cin >> v >> e;
//for (int i = 0; i < e; i++)
//{
//	int u, v;
//	cin >> u >> v;
//	matrix[u][v] = 1;
//}
////Undirected Graph(������ ���� �׷���)
//for (int i = 0; i < e; i++)
//{
//	int u, v;
//	cin >> u >> v;
//	matrix[u] = 1;
//	matrix[v] = 1;
//}
//
////���� ����Ʈ�� ǥ���ϴ� �׷��� (���׿��� �ַ� ���̻��)
////vector�� ����� �� �ִ�
////Directed Graph
//vector<int> adj[10];
//int v, e;
//cin >> v >> e;
//for (int i = 0; i < e; i++)
//{
//	int u, v;
//	cin >> u >> v;
//	adj[u].push_back(v);
//}
//
////Undirected Graph
//vector<int> adj[10];
//cin >> v >> e;
//for (int i = 0; i < e; i++)
//{
//	int u, v;
//	cin >> u >> v;
//	adj[u].push_back(v);
//	adj[v].push_back(u);
//}
//
////stl�� ������� ���� �� ���� �׷���
//int edge[10][10];
//int deg[10]; //�� ���� outdegree
//int* adj[10];
//int idx[10];	//adj[i]���� ���ο� ������ �߰��� ���� ��ġ
//int main()
//{
//	int v, e;
//	cin >> v >> e;
//	for (int i = 0; i < e; i++)
//	{
//		cin >> edge[i][0] << edge[i][1];
//		deg[edge[i][0]]++;
//	}
//	for (int i = 1; i <= v; i++)
//		adj[i] = new int[deg[i] + 1];
//
//	for (int i = 0; i < e; i++)
//	{
//		int u = edge[i][0], v = edge[i][1];
//		adj[u][idx[u]] = v;
//		idx[u]++;
//	}
//}
//
////stl�� ������� ���� �� ������ �׷���
//int edge[10][10];
//int deg[10]; //�� ���� degree
//int* adj[10];
//int idx[10];	//adj[i]���� ���ο� ������ �߰��� ���� ��ġ
//int main()
//{
//	int v, e;
//	cin >> v >> e;
//	for (int i = 0; i < e; i++)
//	{
//		cin >> edge[i][0] >> edge[i][1];
//		deg[edge[i][0]]++; deg[edge[i][1]]++;
//	}
//	
//	for (int i = 1; i <= v; i++)
//		adj[i] = new int[deg[i] + 1];
//
//	for (int i = 0; i < e; i++)
//	{
//		int u = edge[i][0], v = edge[i][1];
//		adj[u][idx[u]] = v;
//		idx[u]++;
//		adj[v][idx[v]] = u;
//		idx[v]++;
//	}
//}
//
////���� �׷������� bfs��ȸ
//vector<int> adj[10];
//bool visit[10];
//void bfs()
//{
//	queue<int> q;
//	q.push(1);
//	visit[1] = 1;
//	while (!q.empty())
//	{
//		int cur = q.front(); q.pop();
//		cout << cur << " ";
//		for (int i = 0; i < adj[cur].size(); i++)
//			//for(auot nxt : adj[cur])
//		{
//			int nxt = adj[cur][i];
//			if (visit[nxt]) continue;
//			q.push(nxt);
//			visit[nxt] = 1;
//		}
//	}
//}
////visit��� dist�迭�� -1�� ���� �ʱ�ȭ�Ͽ� �Ÿ��� ���� �� �ִ�
//
////���� �׷��������� dfs��ȸ(�Ÿ��� ���� ���� ����) -> ���� ���� �������κ��� �߰��Ǵ� ������ ������ ���������κ��� 1��ŭ �� ������ �ִٴ� ������ �������� �ʴ´�
//vector<int> adj[10];
//bool visit[10];
//void dfs()
//{
//	stack<int> s;
//	s.push(1);
//	visit[1] = 1;
//	while (!s.empty())
//	{
//		int cur = s.top(); s.pop();
//		cout << cur << " ";
//		for (int i = 0; i < adj[cur].size(); i++)
//			//for(auot nxt : adj[cur])
//		{
//			int nxt = adj[cur][i];
//			if (visit[nxt]) continue;
//			s.push(nxt);
//			visit[nxt] = 1;
//		}
//	}
//}
//
////��͸� ����� dfs => ��ͷ� �Լ� ȣ�� ��ü�� ������ �̿��ϹǷ� ������ ������ �ʿ����
//vector<int> adj[10];
//bool visit[10];
//void dfs(int cur)
//{
//	cout << cur << " ";
//	for (int i = 0; i < adj[cur].size(); i++)
//	{
//		int nxt = adj[cur][i];
//		if (visit[nxt]) continue;
//		visit[nxt] = 1;
//		dfs(nxt);
//	}
//}
//

////Dijkstra
//���� ������ ����� ��
//������� ����
//#include<queue>
//#include<vector>
//using namespace std;
//
//int v, e, st;	//st : ���� ������ ��ȣ
//vector<pair<int, int>> adj[20005];	//cost(���� ������ ���), index
//const int INF = 1e9+10;	//������ ������ �Ÿ����� ū ��
//int d[20005];
//void dijkstra()
//{
//	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;	//greater���� ���� min heap���� ����
//	d[st] = 0;
//	pq.push({ d[st],st });	//{�Ÿ�, �̿��� ������ ��ȣ}
//	while (!pq.empty())	//���� ���Ұ� ���� ������ ���Ҹ� ������ ������ �����鿡 ���� d���� ����, ���� �ִ� �۾� �ݺ�
//	{
//		auto cur = pq.top(); pq.pop();
//		int dist = cur.first, idx = cur.second;
//		if (d[idx] != dist) continue;	//�ش� �Ÿ��� d���̺�(�ִ� �Ÿ� ���̺�)�� ����� �Ÿ��� �´��� Ȯ��.
//		//if(d[edx]<dist) continue;�� ����
//		for (auto nxt : adj[idx])
//		{
//			int cost = nxt.first, nidx = nxt.second;
//			if (d[nidx] > dist + cost)
//			{
//				d[nidx] = dist + cost;
//				pq.push({ d[nidx],nidx });
//			}
//		}
//	}
//}
////���ͽ�Ʈ�� ��� ����(pre���̺�) ���
//pre���̺��� ������(st)���� �����Է� �ö� ��� �湮�ߴ��� ����ϴ� ���̺�
//�ִܰŸ� ���̺��� ���ŵ� ������ pre���̺� �����Ѵ�.
//i�� ������ ���õǰ� i������ �̾��� j������ �ִܰŸ� ���� ����� �� pre[j]�� i�� ��ϵȴ�


////Floyd Warshall
//dp�� �̿��ؼ� ���� ������ n�� �϶�
//0~n���� ������ ���� ������ ��� ��� �� �ִ� �Ÿ��� ���ϴ� ���
//�ð� ���⵵�� O(V ^ 3)
//for (int k = 0; k <= n; k++)
//	DP[i][j] = min(DP[i][j], DP[i][k] + DP[k][j]);
////�÷��̵� ��� ����(nxt���̺�) ���
//nxt[s][t]�� ����.������ s���� t���� ���� ��κ��� s���� 1�� ���� ���ٰ� 1���� t�� ���� ��ΰ� �� ȿ������ ��Ȳ��
//nxt[s][t]�� nxt[s][1]������ ��ü�Ѵ�. (s���� 1�� �����ϴ� ���� �ڸ��ϹǷ� s���� t���� �ִܰ�η� ���� ���ؼ��� s���� ����� nxt[s][1]�� �������� �� �� �ִ�.
//������ 1���� t�� ���� �ִ� ��θ� ã�´�.)
//�ִ� ��� ���̺��� �ּҰ����� ���� �ɶ����� ��� ���� ���̺� ���İ� ����� ������ �����Ѵ�.

////���μ� ����(Disjoint Set)
//�ʱ�ȭ : parent �迭�� i���ҿ� ���� �θ� ��� ��ȣ�� ����
//		   ��Ʈ ����� ��� �ڱ� �ڽ��� ��ȣ�� ����
//void init()
//{
//	for (int i = 1; i <= n; i++)
//		parent[i] = i;
//}
//
//Union : �ϳ��� ��Ʈ ��带 �ٸ� ����� �ڽ� ���� �־� �� Ʈ���� ��ģ��
//void union(int a, int b)
//{
//	int aRoot = find(a);
//	int bRoot = find(b);
//
//	parent[aRoot] = bRoot;
//}
//
//Find : �־��� ������ ��Ʈ ��� ��ȣ�� ��ȯ�Ѵ�
//int find(int a)
//{
//	if (parent[a] == a) return a;
//	else  return parent[a] = find(parent[a]);
//	//else return find(parent[a]); ���� ���ݴ� ������
//	//��Ʈ�� �����ϸ鼭 ��ȸ => a�׷쿡 ���Ե� ��� ������ b�� ���� �׷����� ����� ����
//}

////��������(Topological Sort)
//������ �ִ� �׷������� �������� �����ϴ� ���(�پ��� ��� ����)
//	: ���� �׷������� �������� �־��� ���� �� ���İ��踦 �������� �ʵ��� �����ϴ� ����
//���� ) �׷����� ����Ŭ�� �����ؼ��� �ȵȴ� => ���İ��迡 ����� �����
//	   ����Ŭ�� �������� �ʴ� ���� �׷������� ����
//	   DAG(Directed Acyclic Graph)
//indegree //�� ������ ���� ���� //���������� ���� ������ ���� ���� ���;� ��
//���� ���� ����� �߰����� ���� ������ ����ؼ� ���鼭
//���� ������(indegree) 0�� ������ ����� �߰�
//(����Ŭ�� �������� �ʴ� ���� �׷����� indegree�� 0�� ������ �ݵ�� ����)
//==> DAG������ �ش� �˰����� �� �ùٸ� ���� ���� ����� �����ش�
//
//������ ���Ǹ� ���� ����
//1. ������ ������ ������ ���� �ʿ� ���� �̸� indegree�� ������ �����صξ��ٰ�
//�Ź� ������� indegree ���� 1���ҽ��� ������ ����
//2. indegree�� 0�� ������ ���ϱ� ���� �Ź� �������� ��� Ȯ���ϴ� ���
//����� ���� �����ϰ� �ִٰ� ������ ������ �������� ����� �������� �߰�
//(����� queue�� ����(�迭,���õ� ���x))
//
//1. �� ó�� ��� ������ ������ indegree ���̺� ä���
//2. indegree�� 0�� �������� ��� ť�� �ִ´�
//3. ť�� front�� �ִ� ������ ������ ���� ���� ����� �߰�
//4. �ش� �������κ��� ����� ��� ������ indegree���� 1 ���ҽ�Ų��. 
//	�̶� indegree�� 0�� �Ǿ��ٸ� �� ������ ť�� �߰�
//5. ť�� �� ������ 3,4���� �ݺ�
//
//����Ŭ�� �ִ� ��� indegree�� 0�� ���� �ʴ� ������ �����ϰ� �ȴ�.
//����Ŭ�� ���Ե� ������ ���� ť�� �� �� ����(ť�� ��� �˰����� ����� �� ����� ��� ������ ���Ե��� ����)
// ===> �ش� �˰����� ������ �� ����� ��� ������ ���Ե��� �ʴ´ٸ� 
//	  ����Ŭ�� �ִ� �׷������� �� �� �ִ�.
//
//vector<int> adj[10];
//int indeg[10];
//int n;
//void topo_sort() {
//	queue<int> q;
//	vector<int> result;
//	for (int i = 1; i <= n; i++)
//		if (indeg[i] == 0) q.push(i);
//	while (!q.empty()) {
//		int cur = q.front(); q.pop();
//		result.push_back(cur);
//		for (int i = 0; i < adj[cur].size(); i++) {
//			int nxt = adj[cur][i];
//			//for(auto nxt : adj[nxt])
//			indeg[nxt]--;
//			if (indeg[nxt] == 0)
//				q.push(nxt);
//		}
//	}
//	if (resultsize() != n) {
//		cout << "cycle exists";
//		return;
//	}
//
//	for (int i = 0; i < n; i++)
//		cout << result[i]<<" ";
//}
//
//�ð����⵵�� O(V+E)
//�� ������ ť�� �ִ� 1�� ���� indegree�� ���ҽ�Ű�� ������ �� ������ ���� �� 1���� �߻�


//boj5567 ��ȥ��
//boj1753 �ִܰ��
//boj11779 �ּҺ�� ���ϱ� 2
//boj11404 �÷��̵�
//boj11780 �÷��̵� 2
//boj11403 ��� ã��
//boj2665 �̷θ����
//boj6118 ���ٲ���
//boj1717 ������ ǥ��(UnionFind)
//boj2252 �� �����(topology sort)
//boj1043 ������
//boj3830 �������� ��ٸ��� �ʴ´�(UnionFind)
//boj1976 ���� ����(UnionFind)
//boj2623 �������α׷�(topology sort)
//boj1516 ���� ����(topology sort)
//boj1504 Ư���� �ִ� ���(dijkstra)
//boj18223 �����̿� ���� �׸��� �ǿ�(dijkstra)
//boj2458 Ű ����(floyd warshall)
//boj14588 Line Friends (Small) (floyd warshall)
//boj1389 �ɺ� �������� 6�ܰ� ��Ģ
//boj4485 ��� �� ���� �ְ� ������?
//boj1238 ��Ƽ
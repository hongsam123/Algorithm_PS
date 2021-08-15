////트리
//루트와 리프, 부모와 자식으로 이루어진 그래프의 특별한 종류
//트리 : 무방향이면서 사이클이 없는 연결 그래프(Undirected Acyclic Connected Graph)
//임의의 두 점을 연결하는 simple path(정점이 중복해서 나오지 않는 경로)가 유일한 그래프
//V개의 정점을 가지고 V-1개의 간선을 가지는 연결 그래프

////트리의 BFS,DFS
//BFS - 트리에서 bfs는 자신의 자식들을 전부 queue에 넣어주기만 하면 된다
//		루트가 아닌 아무 정점은 인접한 정점들 중 자신의 부모를 제외하고는 전부 자신의 자식이라 
//		아직 방문하지 않았음이 보장된다
//	==> 자신과 이웃한 정점에 대해 부모만 빼고 나머지는 전부 큐에 넣으면 되고,
//		vis배열을 들고갈 필요 없이 부모가 누구인지만 저장하면 됨
//		부모가 누구인지는 bfs를 돌리면서 자식 정점을 큐에 집어 넣을 때 채울 수 있다
//
//vector<int> adj[10];
//int p[10];	//부모를 저장하는 배열
//void bfs(int root)
//{
//	queue<int> q;
//	q.push(root);	//루트의 부모는 자연스럽게 0
//
//	while (!q.empty())
//	{
//		int cur = q.front(); q.pop();
//		cout << cur << " ";
//		for (int i = 0; i < adj[cur].size(); i++)
//		{
//			int nxt = adj[cur][i];
//			if (p[cur] == nxt) continue;
//			q.push(nxt);
//			p[nxt] = cur;
//		}
//	}
//}
//
//p배열을 사용함으로서 "root"번호의 정점을 루트로 두었을 때
//각 정점의 부모 정보를 bfs 한 번으로 알 수 있다.
//
//부모와 depth배열을 같이 채우기
//vector<int> adj[10];
//int p[10];
//int depth[10];
//void bfs(int root)
//{
//	queue<int> q;
//	q.push(root);
//
//	while (!q.empty())
//	{
//		int cur = q.front(); q.pop();
//		cout << cur << " ";
//
//		for (int i = 0; i < adj[cur].size(); i++)
//		{
//			int nxt = adj[cur][i];
//			if (p[cur] == nxt) continue;
//			q.push(nxt);
//			p[nxt] = cur;
//			depth[nxt] = depth[cur] + 1;
//		}
//	}
//}
//
//위의 코드에서 queue 대신 stack을 사용하면 재귀를 사용하지 않는 dfs
// - 재귀를 사용한 dfs(단 스택 메모리 한계를 넘어설 수 있기 때문에 V가 클 때에는 재귀 dfs를 써서는 안된다)
//vector<int> adj[10];
//int p[10];
//int depth[10];
//void dfs(int cur)
//{
//	cout << cur << " ";
//	for (auto nxt : adj[cur])
//	{
//		if (p[cur] == nxt) continue;
//		p[nxt] = cur;
//		depth[nxt] = depth[cur] + 1;
//		dfs(nxt);
//	}
//}
//
//- 단순 순회, 재귀(p배열을 둘 필요 없이 parent를 넘겨준다)
//vector<int> adj[10];
//void dfs(int cur, int par)
//{
//	cout << cur << " ";
//	for (auto nxt : adj[cur].size(); i++)
//	{
//		if (par == nxt) continue;
//		dfs(nxt, cur);
//	}
//}

////이진트리에서의 순회
//이진트리: 각 정점의 자식이 최대 2개인 트리
//왼쪽 자식, 오른쪽 자식을 저장하는 방법으로 구조체, 클래스, ...
//여기서는 간단히 lc, rc배열(left child, right child)
//값이 0이라면 해당 자리(자식)이 비어있음을 의미
//
////레벨순회(Level-order Traversal) : 레벨, 즉 높이 순으로 방문하는 순회
//==> bfs(루트를 시작점으로 두고 bfs)
//
//int lc[9] = { 0,2,4,6,0,0,0,0,0 };
//int rc[9] = { 0,3,5,7,0,8,0,0,0 };
//void bfs()	//root = 1
//{
//	queue<int> q;
//	q.push(1);
//	while (!q.empty())
//	{
//		int cur = q.front(); q.pop();
//		cout << cur << " ";
//		if (lc[cur]) q.push(lc[cur]);	//자식이 있다면 queue에 넣기
//		if (rc[cur]) q.push(rc[cur]);
//	}
//}
//
////전위순회(Preorder Traversal) (재귀) 
//1. 현재 정점을 방문한다.
//2. 왼쪽 서브트리를 전위순회한다.
//3. 오른쪽 서브트리를 전위순회한다
//리프에서 전위순회를 시작할 경우 자기 자신만을 방문 후 종료한다.
//
//int lc[9] = { 0,2,4,6,0,0,0,0,0 };
//int rc[9] = { 0,3,5,7,0,8,0,0,0 };
//void preorder(int cur)
//{
//	cout << cur << " ";
//	if (lc[cur]) preorder(lc[cur]);
//	if (rc[cur]) preorder(rc[cur]);
//}
//
//(dfs와 방문순서가 동일)
//
////중위순회(Inorder Traversal) (재귀)
//1. 왼쪽 서브 트리를 중위 순회한다.
//2. 현재 정점을 방문한다.
//3. 오른쪽 서브 트리를 중위 순회한다.
//
//int lc[9] = { 0,2,4,6,0,0,0,0,0 };
//int rc[9] = { 0,3,5,7,0,8,0,0,0 };
//void preorder(int cur)
//{
//	if (lc[cur]) preorder(lc[cur]);
//	cout << cur << " ";
//	if (rc[cur]) preorder(rc[cur]);
//}
//
////후위 순회(Postorder Traversal) (재귀)
//1. 왼쪽 서브 트리를 후위 순회한다.
//2. 오른쪽 서브 트리를 후위 순회한다.
//3. 현재 정점을 방문한다.
//
//int lc[9] = { 0,2,4,6,0,0,0,0,0 };
//int rc[9] = { 0,3,5,7,0,8,0,0,0 };
//void preorder(int cur)
//{
//	if (lc[cur]) preorder(lc[cur]);
//	if (rc[cur]) preorder(rc[cur]);
//	cout << cur << " ";
//}
//
//서로 다른 트리라고 하더라도 순회 결과가 일치할 수 있다.


////최소 신장 트리(MST;Minimum Spanning Tree)
//신장 트리 : 주어진 방향성이 없는 그래프의 서브 그래프들 중에서 모든 정점을 포함하는 트리
//서브 그래프 : 주어진 그래프에서 일부 정점과 간선만을 택해서 구성한 새로운 그래프
//트리 : 사이클이 없고 연결된 그래프
//
//->트리의 성질로부터 주어진 그래프의 정점이 V개일 때 신장 트리는 V - 1개의 간선을 갖는다
//주어진 그래프가 연결 그래프일 경우에만 신장 트리가 존재한다
//
//최소 신장 트리 : 신장 트리 중에서 간선의 합이 최소인 트리
//최소 신장 트리는 그래프에서 딱 한개로 정해지지 않고 여러개일 수 있다
//
////1. 크루스칼(kruskal) 알고리즘
//- Union Find 알고리즘을 사용한 알고리즘
//- 가장 비용이 낮은 간선부터 시작해 서로 떨어져 있던 정점들을 합쳐나가며 총 V - 1개의 간선을 택하는 알고리즘
//
//1. 간선을 크기의 오름차순으로 정렬하고 제일 낮은 비용의 간선을 선택한다.
//2. 현재 선택한 간선이 정점 u, v를 연결하는 간선이라고 했을 때,
//만약 u, v가 같은 그룹이라면 아무것도 하지 않고 넘어간다.
//u, v가 다른 그룹이라면 같은 그룹으로 만들고 현재 선택한 간선을 최소 신장 트리에 추가한다.
//3. 최소 신장 트리에 V - 1개의 간선을 추가시켰다면 과정을 종료한다.
//그렇지 않다면 그 다음으로 비용이 작은 간선을 선택한 후 2, 3번 과정을 반복한다.
//
//(사이클을 만들어내지 않는 선에서 비용이 작은 간선부터 최소 신장 트리에 편입시키는 그리디 알고리즘)
//
//
//int v, e;
//tuple<int, int, int> edge[100005];
//
//void kruskal()
//{
//	sort(edge, edge + e);
//	int cnt = 0;
//	for (int i = 0; i < e; i++)
//	{
//		int cost, v1, v2;
//		tie(cost, v1, v2) = edge[i];
//		if (!is_diff_group(v1, v2)) continue;
//
//		cout << cost << " " << v1 << " " << v2;
//		cnt++;
//		if (cnt == v - 1) break;
//	}
//}
//
//union find 를 사용한다면 "특정 두 정점이 같은 그룹인지 다른 그룹인지"(is_diff_group)를 상수시간에 확인 가능
//
//이전에는 간선을 vector<int> adj[]에 저장했다면 이제는 간선을 크기순으로 정렬해야함.	//tuple에 저장
//e개의 간선을 크기순으로 살펴보며 해당 간선의 정점 두 개가 다른 그룹인지 같은 그룹인지 확인
//최소신장트리는 v-1개의 간선으로 이루어지므로 cnt가 v-1이 되는 순간 종료
//	
//union find를 사용한 크루스칼 알고리즘 O(ElogE)

////프림(Prim)알고리즘
//한 정점에서 시작해 확장해 나가는 알고리즘
//
//1. 하나의 정점을 선택해 최소 신장 트리에 추가한다.
//2. 최소 신장 트리에 포함된 정점과 최소 신장 트리에 포함되지 않은 정점을 연결하는 간성 중
//비용이 가장 작은 것을 최소 신장 트리에 추가한다. 해당 간선의 최소 신장 트리에 포함되지 않은
//정점 또한 최소 신장 트리에 추가한다. 
//3. 최소 신장 트리에 v-1개의 간선이 추가될 때 까지 2번 과정을 반복한다.
//
//구현)
//1. 하나의 정점을 선택해 최소 신장 트리에 추가하고 해당 정점과 연결된
//모든 간선을 힙에 추가한다.
//2. 힙에서 비용이 가장 작은 간선을 꺼낸다.
//3-1. 만약 해당 간선이 최소 신장 트리에 포함된 두 정점을 연결한다면
//아무 것도 하지 않고 넘어간다.
//3-2. 해당 간선이 최소 신장 트리에 포함된 정점 u와 포함되지 않은 정점 v를
//연결한다면 우선 해당 간선과 정점 v를 최소 신장 트리에 추가한다.
//그리고 정점 v와 최소 신장 트리에 포함되지 않는 정점을 연결하는 
//모든 간선을 힙에 추가한다.
//4. 최소 신장 트리에 v-1개의 간선이 추가될 때까지 2,3번 과정을 반복한다.
//
//#define ti3 tuple<int,int,int>
//int v, e;
//vector<pair<int, int>> adj[100005];	//<cost,idx>
//bool check[100005];	//i번째 정점이 최소 신장 트리에 포함되었는지 여부
//void prim() {
//	int cnt = 0;
//	priority_queue<ti3, vector<ti3>, greater<tie>> pq;	//min heap
//	for (auto nxt : adj[1])
//		pq.push(nxt.first, 1, nxt.second);
//	check[1] = 1;	
//
//	while (1)
//	{
//		int cost, v1, v2;
//		tie(cost, v1, v2) = pq.top(); pq.pop();
//		if (check[v2]) continue;	//현재 보고있는 간선이 최소 신장 트리에 포함된 두 정점을 연걸한 것인지,
//									//최소 신장 트리에 포함된 정점 u와 포함되지 않은 정점 v를 연결한 것인지를 판단
//		
//		cout << cost << " " << v1 << " " << v2 << "\n";
//		check[v2] = 1;
//		cnt++;
//
//		if (cnt == v - 1) break;
//		for (auto nxt : adj[v2])
//		{
//			if (!check[nxt.second])
//				pq.push(nxt.first, v2, nxt.second);
//		}
//	}
//}


////최소공통조상(LCA;Lowest Common Ancestor)
//정점 a와 b가 각각 자신을 포함하여 조상을 따라 거슬러 올라갈 때 처음 공통으로
//만나게 되는 정점
//= > 최상위 조상 정점을 시작으로 DFS(or BFS)를 수행하여 각 정점의 깊이와
//	부모 정점을 저장
//	정점의 부모를 따라 하나씩 올라가 LCA를 찾는다
//트리의 깊이가 H일 때 시간 복잡도는 O(H), 최악의 경우 O(N)
//
////LCA 빠르게 구현
//= > 각 정점의 부모 뿐 아니라 2 ^ k번째 조상까지 저장
//parent[k][v] = parent[k - 1][parent[k - 1][v]];	//정점V의 2^k번째 조상 정점 번호
//- depth[a] != depth[b]
//	diff = depth[a] - depth[b];
//	     = 11
//		 = 2^3 + 2^1 + 2^0
//- depth[a] == depth[b]
//	parent[2][a] != parent[2][b]
//	parent[3][a] == parent[3][b]
//	==> LCA(a,b)는 2^2와 2^3번째 조상 사이에 존재
//
//트리의 깊이가 H일 때 시간 복잡도는 O(logH), 최악의 경우 O(logN)
//
//1) dfs로 모든 정점의 depth를 구한다
//2) 2^n칸씩 올라간다 (dp ->parent[k][v] = parent[k - 1][parent[k - 1][v]];)
//	parent[0][v] - 정점 v의 1번째 조상
//	parent[1][v] - 정점 v의 2번째 조상
//	parent[10][v] - 정점 v의 1024번째 조상
//3) 2^k 최대치로 올라간다
//	3-1) 공통조상이 아니면 더 올린다
//	3-2) 공통조상이면 지금이 답(LCA)이거나, 밑으로 내려야 한다
//			 for (int i = k - 1; i >= 0; i--)
//			 {
//				 if (parent[i][a] != [i][b])
//				 {
//					 a = parent[i][a];
//					 b = parent[i][b];
//				 }
//			 }
//		 parent[0][a];	//답



//boj1991 트리 순회
//boj11725 트리의 부모 찾기
//boj1197 최소 스패닝 트리(크루스칼, 프림)
//boj1922 네트워크 연결
//boj4386 별자리 만들기(크루스칼)
//boj11437 LCA
//boj11438 LCA 2
//boj3584 가장 가까운 공통 조상
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int t, n;
int expo;
vector<int> edge[10002];
int depth[10002];
int parent[20][10002];

void initTree(int node, int p)
{

}

int lca(int a, int b)
{
	if (depth[a] != depth[b])
	{
		if (depth[a] > depth[b]) swap(a, b);
		for (int k = expo; k >= 0; k--)
		{
			if (depth[a] <= depth[parent[k][b]])
				b = parent[k][b];
		}
	}

	int ans = 0;
	if (a != b)
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

	cin >> t;

	while (t--)
	{
		cin >> n;

		for (int i = 1; i <= n; i++)
			edge[i].clear();
		fill(depth, depth + n + 1, 0);
		for (int i = 0; i << 20; i++)
			fill(parent[i], parent[i] + n + 1, 0);

		for (int i = 1; i <= n; i *= 2)
			expo++;

		for (int i = 0; i < n-1; i++)
		{
			int u, v;
			cin >> u >> v;
			edge[u].push_back(v);
		}

		int a, b;
		cin >> a >> b;

		//트리 초기화
		initTree();

		cout << lca(a, b) << "\n";
	}

	return 0;
}
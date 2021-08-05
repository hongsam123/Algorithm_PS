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



//boj1991 트리 순회
//boj11725 트리의 부모 찾기
//boj1197 최소 스패닝 트리
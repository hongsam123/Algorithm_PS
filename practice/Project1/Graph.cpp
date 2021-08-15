////인접 행렬로 표현하는 그래프
////Directed Graph(방향이 있는 그래프)
//int matrix[10][10];
//int v, e;
//cin >> v >> e;
//for (int i = 0; i < e; i++)
//{
//	int u, v;
//	cin >> u >> v;
//	matrix[u][v] = 1;
//}
////Undirected Graph(방향이 없는 그래프)
//for (int i = 0; i < e; i++)
//{
//	int u, v;
//	cin >> u >> v;
//	matrix[u] = 1;
//	matrix[v] = 1;
//}
//
////인접 리스트로 표현하는 그래프 (코테에서 주로 많이사용)
////vector를 사용할 수 있다
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
////stl을 사용하지 않을 때 방향 그래프
//int edge[10][10];
//int deg[10]; //각 정점 outdegree
//int* adj[10];
//int idx[10];	//adj[i]에서 새로운 정점을 추가할 때의 위치
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
////stl을 사용하지 않을 때 무방향 그래프
//int edge[10][10];
//int deg[10]; //각 정점 degree
//int* adj[10];
//int idx[10];	//adj[i]에서 새로운 정점을 추가할 때의 위치
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
////연결 그래프에서 bfs순회
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
////visit대신 dist배열을 -1로 먼저 초기화하여 거리를 구할 수 있다
//
////연결 그래프에서의 dfs순회(거리를 구할 수는 없다) -> 현재 보는 정점으로부터 추가되는 인접한 정점은 시작점으로부터 1만큼 더 떨어져 있다는 성질이 만족되지 않는다
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
////재귀를 사용한 dfs => 재귀로 함수 호출 자체가 스택을 이용하므로 스택을 선언할 필요없다
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
//음의 간선이 없어야 함
//출발지가 고정
//#include<queue>
//#include<vector>
//using namespace std;
//
//int v, e, st;	//st : 시작 정점의 번호
//vector<pair<int, int>> adj[20005];	//cost(연결 간선의 비용), index
//const int INF = 1e9+10;	//실제로 가능한 거리보다 큰 값
//int d[20005];
//void dijkstra()
//{
//	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;	//greater으로 힙을 min heap으로 변경
//	d[st] = 0;
//	pq.push({ d[st],st });	//{거리, 이웃한 정점의 번호}
//	while (!pq.empty())	//힙에 원소가 없을 때까지 원소를 꺼내고 인접한 정점들에 대해 d값을 갱신, 힙에 넣는 작업 반복
//	{
//		auto cur = pq.top(); pq.pop();
//		int dist = cur.first, idx = cur.second;
//		if (d[idx] != dist) continue;	//해당 거리가 d테이블(최단 거리 테이블)에 저장된 거리가 맞는지 확인.
//		//if(d[edx]<dist) continue;와 동일
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
////다익스트라 경로 복원(pre테이블) 방법
//pre테이블은 시작점(st)에서 나에게로 올때 어디를 방문했는지 기록하는 테이블
//최단거리 테이블이 갱신될 때마다 pre테이블도 갱신한다.
//i번 정점이 선택되고 i정점과 이어진 j정점의 최단거리 값이 변경될 때 pre[j]에 i가 기록된다


////Floyd Warshall
//dp를 이용해서 정점 개수가 n개 일때
//0~n개의 정점을 거쳐 갈때의 모든 경로 중 최단 거리를 구하는 방법
//시간 복잡도는 O(V ^ 3)
//for (int k = 0; k <= n; k++)
//	DP[i][j] = min(DP[i][j], DP[i][k] + DP[k][j]);
////플로이드 경로 복원(nxt테이블) 방법
//nxt[s][t]를 갱신.기존의 s에서 t까지 가는 경로보다 s에서 1을 먼저 갔다가 1에서 t로 가는 경로가 더 효율적인 상황에
//nxt[s][t]를 nxt[s][1]값으로 대체한다. (s에서 1로 가야하는 것은 자명하므로 s에서 t까지 최단경로로 가기 위해서는 s에서 출발해 nxt[s][1]을 가야함을 알 수 있다.
//다음은 1에서 t로 가는 최단 경로를 찾는다.)
//최단 경로 테이블이 최소값으로 갱신 될때마다 경로 복원 테이블도 거쳐간 노드의 값으로 변경한다.

////서로소 집합(Disjoint Set)
//초기화 : parent 배열에 i원소에 대한 부모 노드 번호를 저장
//		   루트 노드인 경우 자기 자신의 번호를 저장
//void init()
//{
//	for (int i = 1; i <= n; i++)
//		parent[i] = i;
//}
//
//Union : 하나의 루트 노드를 다른 노드의 자식 노드로 넣어 두 트리를 합친다
//void union(int a, int b)
//{
//	int aRoot = find(a);
//	int bRoot = find(b);
//
//	parent[aRoot] = bRoot;
//}
//
//Find : 주어진 원소의 루트 노드 번호를 반환한다
//int find(int a)
//{
//	if (parent[a] == a) return a;
//	else  return parent[a] = find(parent[a]);
//	//else return find(parent[a]); 보다 조금더 빠르다
//	//루트를 갱신하면서 조회 => a그룹에 포함된 모든 정점을 b와 같은 그룸으로 만들기 위해
//}

////위상정렬(Topological Sort)
//방향이 있는 그래프에서 정점들을 정렬하는 방법(다양한 방법 존재)
//	: 방향 그래프에서 간선으로 주어진 정점 간 선후관계를 위배하지 않도록 나열하는 정렬
//주의 ) 그래프에 사이클이 존재해서는 안된다 => 선후관계에 모순이 생긴다
//	   사이클이 존재하지 않는 방향 그래프에서 정의
//	   DAG(Directed Acyclic Graph)
//indegree //각 정점의 진입 차수 //진입차수가 없는 정점이 가장 먼저 나와야 함
//위상 정렬 결과에 추가되지 않은 정점을 계속해서 돌면서
//진입 차수가(indegree) 0인 정점을 결과에 추가
//(사이클이 존재하지 않는 방향 그래프는 indegree가 0인 정점이 반드시 존재)
//==> DAG에서는 해당 알고리즘이 늘 올바른 위상 정렬 결과를 내어준다
//
//구현의 편의를 위한 성질
//1. 정점과 간선을 실제로 지울 필요 없이 미리 indegree의 갯수를 저장해두었다가
//매번 뻗어나가는 indegree 값을 1감소시켜 과정을 수행
//2. indegree가 0인 정점을 구하기 위해 매번 정점들을 모두 확인하는 대신
//목록을 따로 저장하고 있다가 직전에 제거한 정점에서 연결된 정점들을 추가
//(목록은 queue로 관리(배열,스택도 상관x))
//
//1. 맨 처음 모든 간선을 읽으며 indegree 테이블 채우기
//2. indegree가 0인 정점들을 모두 큐에 넣는다
//3. 큐의 front에 있는 정점을 가져와 위상 정렬 결과에 추가
//4. 해당 정점으로부터 연결된 모든 정점의 indegree값을 1 감소시킨다. 
//	이때 indegree가 0이 되었다면 그 정점을 큐에 추가
//5. 큐가 빌 때까지 3,4번을 반복
//
//사이클이 있는 경우 indegree가 0이 되지 않는 정점이 존재하게 된다.
//사이클에 포함된 정점은 절대 큐에 들어갈 수 없음(큐가 비어 알고리즘이 종료될 때 결과에 모든 정점이 포함되지 않음)
// ===> 해당 알고리즘을 돌렸을 때 결과에 모든 정점이 포함되지 않는다면 
//	  사이클이 있는 그래프임을 알 수 있다.
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
//시간복잡도는 O(V+E)
//각 정점이 큐에 최대 1번 들어가고 indegree를 감소시키는 연산이 각 간선에 대해 딱 1번씩 발생


//boj5567 결혼식
//boj1753 최단경로
//boj11779 최소비용 구하기 2
//boj11404 플로이드
//boj11780 플로이드 2
//boj11403 경로 찾기
//boj2665 미로만들기
//boj6118 숨바꼭질
//boj1717 집합의 표현(UnionFind)
//boj2252 줄 세우기(topology sort)
//boj1043 거짓말
//boj3830 교수님은 기다리지 않는다(UnionFind)
//boj1976 여행 가자(UnionFind)
//boj2623 음악프로그램(topology sort)
//boj1516 게임 개발(topology sort)
//boj1504 특정한 최단 경로(dijkstra)
//boj18223 민준이와 마산 그리고 건우(dijkstra)
//boj2458 키 순서(floyd warshall)
//boj14588 Line Friends (Small) (floyd warshall)
//boj1389 케빈 베이컨의 6단계 법칙
//boj4485 녹색 옷 입은 애가 젤다지?
//boj1238 파티
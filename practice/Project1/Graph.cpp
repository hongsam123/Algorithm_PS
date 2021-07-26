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

//boj5567 결혼식
//boj1753 최단경로
//boj11779 최소비용 구하기 2
//boj11404 플로이드
//boj11780 플로이드 2
//boj11403 경로 찾기
//boj2665 미로만들기
//boj6118 숨바꼭질
//boj1717 집합의 표현
//boj2252 줄 세우기
//#include<iostream>
//#include<stack>
//#include<utility>
//using namespace std;
//#define X first
//#define Y second
//int board[502][502] = {
//		{1,1,1,0,1,0,0,0,0,0},
//		{1,0,0,0,1,0,0,0,0,0},
//		{1,1,1,0,1,0,0,0,0,0},
//		{1,1,0,0,1,0,0,0,0,0},
//		{0,1,0,0,0,0,0,0,0,0},
//		{0,0,0,0,0,0,0,0,0,0},
//		{0,0,0,0,0,0,0,0,0,0} };
//bool visit[502][502];
//int n = 7, m = 10;
//int dx[4] = { 1,0,-1,0 };
//int dy[4] = { 0,1,0,-1 };
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	stack<pair<int, int>> s;
//	visit[0][0] = 1;
//	s.push({ 0,0 });
//
//	while (!s.empty())
//	{
//		pair<int, int> cur = s.top(); s.pop();
//		cout << "(" << cur.X << ", " << cur.Y << ") -> ";
//		for (int dir = 0; dir < 4; dir++)
//		{
//			int nx = cur.X + dx[dir];
//			int ny = cur.Y + dy[dir];
//			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
//			if (visit[nx][ny] || board[nx][ny]!= 1) continue;
//			visit[nx][ny] = 1;
//			s.push({ nx,ny });
//		}
//	}
//}

//dfs는 스택을 써서 다차원 배열의 순회를 처리하는 알고리즘(bfs는 큐)
//flood fill은 bfs와 dfs둘다 가능한데 
//거리측정은 bfs만 가능하다(굳이 dfs를 쓸 일이 없다
//dfs는 그래프와 트리에서 사용

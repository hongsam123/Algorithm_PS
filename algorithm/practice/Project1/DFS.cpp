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

//dfs�� ������ �Ἥ ������ �迭�� ��ȸ�� ó���ϴ� �˰���(bfs�� ť)
//flood fill�� bfs�� dfs�Ѵ� �����ѵ� 
//�Ÿ������� bfs�� �����ϴ�(���� dfs�� �� ���� ����
//dfs�� �׷����� Ʈ������ ���

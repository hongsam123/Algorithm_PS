//pair example

//#include<iostream>
//#include<utility>
//using namespace std;
//
//int main(void)
//{
//	pair<int, int> t1 = make_pair(10, 13);
//	pair<int, int> t2 = { 4,6 };	//C++11 이상
//
//	cout << t2.first << ' ' << t2.second << '\n';
//	if (t2 < t1) cout << "t2 < t1";
//}

//#include<iostream>
//#include<queue>
//#include<utility>
//#define X first
//#define Y second
//using namespace std;
//
//int board[502][502] ={ 
//	{1,1,1,0,1,0,0,0,0,0},
//	{1,0,0,0,1,0,0,0,0,0},
//	{1,1,1,0,1,0,0,0,0,0},
//	{1,1,0,0,1,0,0,0,0,0},
//	{0,1,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0} }; // 1이 파란 칸, 0이 빨간 칸에 대응
//
//bool visit[502][502];	// 해당 칸을 방문했는지 여부를 저장
//int n = 7, m = 10;		// 행과 열의 수
//int dx[4] = { 1,0,-1,0 };
//int dy[4] = { 0,1,0,-1 };	// 상하좌우 네 방향
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	queue<pair<int, int>> q;
//	visit[0][0] = 1;	// (0,0)을 방문했다고 명시
//	q.push({ 0,0 });	// 큐에 시작점인 (0,0)을 삽입.
//
//	while (!q.empty())
//	{
//		pair<int, int> cur = q.front(); q.pop();
//		cout << '(' << cur.X << ', ' << cur.Y << ')->';
//		for (int dir = 0; dir < 4; dir++)	// 상하좌우 값 살피기
//		{
//			int nx = cur.X + dx[dir];
//			int ny = cur.Y + dy[dir];	// nx, ny에 dir에서 정한 인접한 칸의 좌표가 들어감
//			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;	// 범위 밖일 경우 넘어감
//			if (visit[nx][ny] || board[nx][ny] != 1) continue;		// 이미 방문한 칸이거나 파란 칸이 아닐 경우
//			visit[nx][ny] = 1;	// (nx,ny)를 방문했다고 명시
//			q.push({ nx, ny });
//		}
//	}
//}

//stl tuple공부

//boj1926 그림
//boj2178 미로 탐색
//boj7576 토마토
//boj4179 불!
//------------------------------------------------------
//중간에 가장자리에 도달한 경우에는(범위를 벗어났다는 것은)
//탈출에 성공했다는 의미이므로 큐에 거리 순으로 들어가기 때문에 최초에 탈출한 시간을 출력할 수 있다.
//큐가 비어서 반복문을 탈출하면 미로 탈출에 실패했다는 의미. 바로 impossible을 출력할 수 있다.

//but이건 하나의 bfs를 전부 돌고 다른 bfs를 돈 문제. 
//만약 각 bfs가 다른 bfs에 영향을 끼친다면 이런방식으로 할수 없다.
//시간순으로 bfs를 동시에 돌려야함.

//==> 다시 풀어볼 문제
//-------------------------------------------------------
//boj5427 불 (위 문제랑 같이 보기)
//boj1697 숨바꼭질
//boj1325 효율적인 해킹
//(블로그 게시 굿 bfs(시간초과) -> dfs(통과))
//boj1012 유기농 배추
//boj7569 토마토
//boj2583 영역 구하기
//boj9466 텀 프로젝트
//==> 블로그 게시하면서 다시 정리해보기
//boj2667 단지번호붙이기
//boj7562 나이트의 이동
//boj10026 적록색약
//boj11724 연결 요소의 개수
//boj4963 섬의 개수
//boj2468 안전구역
//boj2573 빙산
//==> 골드4 다시 정리해보기
//boj18405 경쟁적 전염
//boj2146 다리 만들기
//boj18352 특정 거리의 도시 찾기
//boj16956 늑대와 양
//boj14502 연구소
//boj2606 바이러스
//boj3184 양
//boj6593 상범 빌딩
//boj16234 인구이동
//boj5014 스타트링크
//boj3187 양치기 꿍
//boj13549 숨바꼭질 3
//boj13565 침투
//boj13913 숨바꼭질 4
//boj12851 숨바꼭질 2
//boj1600 말이 되고픈 원숭이
//boj11967 불켜기
#include<iostream>
#include<vector>
#include<utility>
#include<queue>
#include<algorithm>
#define X first
#define Y second
using namespace std;

int n, m;
vector<pair<int, int>> map[102][102];
bool turnOn[102][102];
int ans;
queue<pair<int, int>> q;
bool visited[102][102];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int x, y, nx, ny;
		cin >> x >> y >> nx >> ny;
		map[x][y].push_back({ nx,ny });
	}

	q.push({ 1,1 });
	turnOn[1][1] = true;
	ans++;
	visited[1][1] = true;

	while (!q.empty())
	{
		auto cur = q.front(); q.pop();

		//불켜기
		if (!map[cur.X][cur.Y].empty())
		{
			for (int dir = 0; dir < map[cur.X][cur.Y].size(); dir++)
			{
				int nx = map[cur.X][cur.Y][dir].X;
				int ny = map[cur.X][cur.Y][dir].Y;
				if (turnOn[nx][ny]) continue;
				turnOn[nx][ny] = true;
				ans++;
			}
			//새롭게 이동할 수 있는 곳이 생겼으니 visited배열 초기화
			for (int i = 0; i <= n; i++)
				fill(visited[i], visited[i] + n + 1, 0);
			visited[cur.X][cur.Y] = true;
			
			map[cur.X][cur.Y].clear();	//불을 처음 키고나면 더 세지 않게 지우기
		}

		//이동
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx <= 0 || nx > n || ny <= 0 || ny > n) continue;
			if (!turnOn[nx][ny] || visited[nx][ny]) continue;
			visited[nx][ny] = true;
			q.push({ nx,ny });
		}
	}

	cout << ans;

	return 0;
}
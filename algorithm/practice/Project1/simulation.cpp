//다시 풀어보기

//boj16236번 아기상어
//boj19236번 청소년상어
//boj15683 감시
//boj18808 스티커 붙이기
//boj3190 뱀
//boj13335 트럭
//boj17144 미세먼지 안녕!
//카카오 기둥과 보 설치
//boj14499 주사위 굴리기
//boj11559 Puyo Puyo
//boj14891 톱니바퀴
//boj14503 로봇 청소기
//프로그래머스 2019카카오블라인드 후보키
//boj14500 테트로미노
//boj17070 파이프 옮기기 1(bfs)
//boj20056 마법사 상어와 파이어볼
//프로그래머스 2020 카카오 블라인드 외벽 점검
//boj17135 캐슬 디펜스
//boj17822 원판 돌리기
//boj21610 마법사 상어와 비바라기
//boj17140 이차원 배열과 연산
//boj16235 나무 재테크
//boj20057 마법사 상어와 토네이도
//boj20055 컨베이어 벨트 위의 로봇
//boj20058 마법사 상어와 파이어스톰
//boj21611 마법사 상어와 블리자드
//boj19238 스타트 택시

//구현
//boj3085 사탕게임
//boj10799 쇠막대기
//boj15686 치킨 배달
//프로그래머스 월간코드챌린지 시즌1 삼각 달팽이
//프로그래머스 월간코드챌린지 시즌1 3진법 뒤집기
//프로그래머스 2020 카카오 인턴십 수식 최대화
//boj21608 상어 초등학교
//1107 리모컨

#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#define pii pair<int,int>
#define X first
#define Y second
using namespace std;

int n, m;
int board[21][21];
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1, 0 };
int fuel;
int x, y;
vector<pii> dest;
int dist[21][21];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> fuel;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> board[i][j];
			if (board[i][j]) board[i][j] = -1;
		}
	}

	cin >> x >> y;
	dest.push_back({ 0,0 });
	for (int i = 1; i <= m; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		board[a][b] = i;
		dest.push_back({ c,d });
	}

	while (m--) {
		//태울 승객 고르기(현재 위치에서 최단 거리가 가장 짧은 승객
		int guest = 0;
		queue<pii> q;
		
		for (int i = 0; i <= n; i++)
			fill(dist[i], dist[i] + n+1, -1);

		dist[x][y] = 0;
		q.push({ x,y });

		while (!q.empty()) {
			auto cur = q.front(); q.pop();
			if (board[cur.X][cur.Y]>0) {
				guest = board[cur.X][cur.Y];
				board[cur.X][cur.Y] = 0;
				fuel -= dist[cur.X][cur.Y];
				x = cur.X;
				y = cur.Y;
				break;
			}

			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if (nx <= 0 || nx > n || ny <= 0 || ny > n) continue;
				if (board[nx][ny] == -1) continue;
				if (dist[nx][ny] != -1) continue;
				dist[nx][ny] = dist[cur.X][cur.Y] + 1;
				q.push({ nx,ny });
			}
		}

		if (fuel <= 0 || guest==0) {
			cout << -1;
			return 0;
		}
		
		//손님 데려다 주기
		int dest_x = dest[guest].X;
		int dest_y = dest[guest].Y;

		queue<pii> q2;
		int tax = -1;

		for (int i = 0; i <= n; i++)
			fill(dist[i], dist[i] + n+1, -1);

		dist[x][y] = 0;
		q2.push({ x,y });

		while (!q2.empty()) {
			auto cur = q2.front(); q2.pop();
			if (cur.X==dest_x && cur.Y==dest_y) {
				tax = 2 * dist[cur.X][cur.Y];
				fuel -= dist[cur.X][cur.Y];
				x = cur.X;
				y = cur.Y;
				break;
			}

			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if (nx <= 0 || nx > n || ny <= 0 || ny > n) continue;
				if (board[nx][ny] == -1) continue;
				if (dist[nx][ny] != -1) continue;
				dist[nx][ny] = dist[cur.X][cur.Y] + 1;
				q2.push({ nx,ny });
			}
		}
		if (fuel < 0||tax==-1) {
			cout << -1;
			return 0;
		}

		fuel += tax;
	}

	cout << fuel;

	return 0;
}
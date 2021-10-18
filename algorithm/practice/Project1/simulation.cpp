//�ٽ� Ǯ���

//boj16236�� �Ʊ���
//boj19236�� û�ҳ���
//boj15683 ����
//boj18808 ��ƼĿ ���̱�
//boj3190 ��
//boj13335 Ʈ��
//boj17144 �̼����� �ȳ�!
//īī�� ��հ� �� ��ġ
//boj14499 �ֻ��� ������
//boj11559 Puyo Puyo
//boj14891 ��Ϲ���
//boj14503 �κ� û�ұ�
//���α׷��ӽ� 2019īī������ε� �ĺ�Ű
//boj14500 ��Ʈ�ι̳�
//boj17070 ������ �ű�� 1(bfs)
//boj20056 ������ ���� ���̾
//���α׷��ӽ� 2020 īī�� ����ε� �ܺ� ����
//boj17135 ĳ�� ���潺
//boj17822 ���� ������
//boj21610 ������ ���� ��ٶ��
//boj17140 ������ �迭�� ����
//boj16235 ���� ����ũ
//boj20057 ������ ���� ����̵�
//boj20055 �����̾� ��Ʈ ���� �κ�
//boj20058 ������ ���� ���̾��
//boj21611 ������ ���� ���ڵ�
//boj19238 ��ŸƮ �ý�

//����
//boj3085 ��������
//boj10799 �踷���
//boj15686 ġŲ ���
//���α׷��ӽ� �����ڵ�ç���� ����1 �ﰢ ������
//���α׷��ӽ� �����ڵ�ç���� ����1 3���� ������
//���α׷��ӽ� 2020 īī�� ���Ͻ� ���� �ִ�ȭ
//boj21608 ��� �ʵ��б�
//1107 ������

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
		//�¿� �°� ����(���� ��ġ���� �ִ� �Ÿ��� ���� ª�� �°�
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
		
		//�մ� ������ �ֱ�
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
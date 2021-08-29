#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct fireball
{
	int x, y, m, s, d;
};

int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0,1,1,1,0,-1,-1,-1 };
int N, M, K;
int ans;
vector<fireball> board[52][52];

void moveFireballs()
{
	//�̵��� ���̾ �ӽ� ����
	vector<fireball> tmp[52][52];

	for (int i = 1; i<=N;i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (board[i][j].empty()) continue;
			for (int z = 0;z< board[i][j].size();z++)
			{
				fireball  fb = board[i][j][z];

				int nx = fb.x;
				int ny = fb.y;
				for (int n = 0; n < fb.s; n++)
				{
					nx += dx[fb.d];
					ny += dy[fb.d];
					//1���� N�� ��, ���� ����Ǿ��ִ�
					if (nx <= 0) nx = N;
					if (nx >= N + 1) nx = 1;
					if (ny <= 0) ny = N;
					if (ny >= N + 1) ny = 1;

				}
				tmp[nx][ny].push_back({ nx,ny,fb.m,fb.s,fb.d });
			}
			//�̵� �� ���̾ ����
			board[i][j].clear();
		}
	}

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			if (!tmp[i][j].empty())
				for (auto fb : tmp[i][j])
					board[i][j].push_back(fb);

	return;
}

void unionDevide()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			//2�� �̻��� ���̾�� �ִ°�
			if(board[i][j].size() < 2) continue;

			int num = board[i][j].size();
			int nm = 0;
			int ns = 0;
			bool isSame = true;
			for (int z = 0; z<board[i][j].size(); z++)
			{
				nm += board[i][j][z].m;
				ns += board[i][j][z].s;
				if (z == 0) continue;
				if ((board[i][j][z].d)%2 != (board[i][j][z - 1].d)%2) isSame = false;
			}

			board[i][j].clear();

			//������ 0�̶�� �Ҹ�
			if (nm / 5 == 0) continue;

			//�ƴ϶�� 4���� ���̾�� devide
			for (int z = 0; z < 4; z++)
			{
				if (isSame)
					board[i][j].push_back({ i,j,nm / 5,ns / num,z * 2 });
				else
					board[i][j].push_back({ i,j,nm / 5,ns / num,(z * 2) + 1 });
			}
		}
	}

	return;
}

void addM()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (board[i][j].size() == 0) continue;
			for (auto fb : board[i][j])
				ans += fb.m;
		}
	}

	return;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> K;
	for (int i = 0; i < M; i++)
	{
		int x, y, m, s, d;
		cin >> x >> y >> m >> s >> d;
		board[x][y].push_back({ x,y,m,s,d });
	}

	while (K--)
	{
		//���̾ �̵�(1)
		moveFireballs();

		//2�� �̻� ���̾ ó��
		unionDevide();
	}

	//���� ���̾ ���� ���ϱ�
	addM();

	cout << ans;

	return 0;
}

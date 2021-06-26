#include<iostream>
#include<vector>
using namespace std;

int n, m, x, y, k;
int board[22][22];
vector<int> dice(6); //(위, 아래, 상, 하, 좌, 우)

bool moveXY(int order)
{
	int nx = x;
	int ny = y;
	if (order == 1)	//동
		ny++;
	else if (order == 2)	//서
		ny--;
	else if (order == 3)	//북
		nx--;
	else
		nx++;	//남

	if (nx < 0 || nx >= n || ny < 0 || ny >= m) return false;
	else
	{
		x = nx;
		y = ny;
		return true;
	}
}

void roll(int order)
{
	vector<int> tmp = dice;

	if (order == 1)	//동
	{
		dice[0] = tmp[4];	//좌 -> 위
		dice[1] = tmp[5];	//우 -> 아래
		dice[4] = tmp[1];	//아래 -> 좌
		dice[5] = tmp[0];	//위 -> 우
	}
	else if (order == 2)	//서
	{
		dice[0] = tmp[5];
		dice[1] = tmp[4];
		dice[4] = tmp[0];
		dice[5] = tmp[1];
	}
	else if (order == 3)	//북
	{
		dice[0] = tmp[3];
		dice[1] = tmp[2];
		dice[2] = tmp[0];
		dice[3] = tmp[1];
	}
	else
	{						//남
		dice[0] = tmp[2];
		dice[1] = tmp[3];
		dice[2] = tmp[1];
		dice[3] = tmp[0];
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> x >> y >> k;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}

	int order;
	while (k--)
	{
		cin >> order;

		//범위 검사 및 좌표 이동
		if (!moveXY(order)) continue;
		
		//주사위 굴리기
		roll(order);

		if (board[x][y])	//0이 아니라면
		{
			dice[1] = board[x][y];	//칸의 쓰여있는 수가 주사위 바닥면(1)으로 복사
			board[x][y] = 0;		//칸의 수는 0
		}
		else
							//0이라면
		{
			board[x][y] = dice[1];	//칸에 주사위의 바닥면 수 쓰기
		}

		cout << dice[0]<<"\n";		//주사위의 상단에 쓰여있는 수 출력
	}

	return 0;
}

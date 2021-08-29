#include<iostream>
#include<utility>
using namespace std;

int n, m, k;
int note[42][42];
int sticker[12][12];
int r, c;

void rotate()
//��ƼĿ�� ������ �Լ�(���� ���̿� ��ǥ�� ���� ������ Ȯ�ΰ���)
{
	int tmp[12][12];
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			tmp[i][j] = sticker[i][j];

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			sticker[j][r-1-i] = tmp[i][j];

	swap(r, c);
}

bool pastable(int x, int y)
//��Ʈ���� (x,y)�ڸ��� ��ƼĿ�� (0,0)�� �ö󰡰� ��ƼĿ�� ���� �� �ִ���
//Ȯ���ϰ� �����ϴٸ� ���̱�
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (note[x + i][y + j] == 1 && sticker[i][j] == 1)
			{
				return false;
			}
		}
	}

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (sticker[i][j] == 1)
				note[x + i][y + j] = 1;
		}
	}
	return true;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	while (k--)
	{
		cin >> r >> c;
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				cin >> sticker[i][j];
			}
		}

		for (int rot = 0; rot < 4; rot++)
			//���� �� �ִ��� Ȯ���� �Ŀ� ���� �� ���� �� ������ �ϹǷ�
		{
			bool is_paste = false;	//���ϼ� �ִ��� ������ Ȯ���ϴ� ����
			for (int x = 0; x <= n - r; x++)
			{
				if (is_paste) break;
				for (int y = 0; y <= m - c; y++)
				{
					is_paste = pastable(x, y);
					if (is_paste) break;
				}
			}
			if (is_paste) break;
			rotate();
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (note[i][j]) cnt++;
		}
	}

	cout << cnt;

	return 0;
}

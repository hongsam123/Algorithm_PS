//15683����(������� ���� ������ �ٽ� Ǯ���)
//#include<iostream>
//#include<vector>
//#include<queue>
//#include<utility>
//#define X first
//#define Y second
//using namespace std;
//
//int n, m;
//int board[10][10];
//int tmp[10][10];
//int dx[4] = { 1,0,-1,0 };
//int dy[4] = { 0,1,0,-1 };
//vector<pair<int, int>> cctv;
//
////cctv�� ��ǥ�� cctv�� ������ ���ڷ� �Ѿ���� �� �ش� cctv�� 
////�����ϴ� ���!! ������ 7�� �ٲٴ� �Լ�
////dir�� 0�� ���� ��,1�� �� ��, 2�� �� ��, 3�� �� ��(dx,dy)
//void upd(int x, int y, int dir) {
//	dir = dir % 4;
//	while (1)
//	{
//		x += dx[dir];
//		y += dy[dir];
//		if (x < 0 || x >= n || y < 0 || y >= m) return;	//������ ����� return
//		if (tmp[x][y] == 6) return;		//���� ������ return
//		if (tmp[x][y] != 0) continue;	//�ٸ� cctv�� ���������� �Ѿ
//		tmp[x][y] = 7;			//������ �������, ���� ��������, �ٸ� cctv�� �ƴϾ����� �����Ѵٴ� ǥ��
//	}
//}
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> n >> m;
//	int mn = 0;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			cin >> board[i][j];
//			if (board[i][j] != 0 && board[i][j] != 6)
//				cctv.push_back({ i,j });
//			if (board[i][j] == 0) mn++;
//		}
//	}
//
//	for (int a = 0; a < (1 << (2*cctv.size())); a++)
//		//cctv����(=4(�����¿�))^cctv���� - 1
//		//��ŭ cctv�� ���� ��� ����� ��ĭ ���� ���ϱ�
//	    //(��� ����� ���� �ش��ϴ� �κ�)
//	{
//		for (int i = 0; i < n; i++)
//			for (int j = 0; j < m; j++)
//				tmp[i][j] = board[i][j];
//		
//		int brute = a;
//		
//		for (int i = 0; i < cctv.size(); i++)
//		{
//			int dir = brute % 4;
//			brute /= 4;
//			//brute�� ������ ������ %, / ������ ���� 4���� ������ �̾Ƴ���
//			//���� cctv������ŭ �ݺ�
//			int x = cctv[i].X;
//			int y = cctv[i].Y;
//			//cctv��ġ ������ �ް� �ؿ��� ������� Ȯ��
//
//			if (board[x][y] == 1)
//			{
//				upd(x, y, dir);
//			}
//			else if (board[x][y] == 2)
//			{
//				upd(x, y, dir);
//				upd(x, y, dir + 2);
//				//upd�Լ����� dir = dir%4�� �ϱ� ������ 4�̻��� ���� �Ѿ�� ������� 
//			}
//			else if (board[x][y] == 3)
//			{
//				upd(x, y, dir);
//				upd(x, y, dir + 1);
//			}
//			else if (board[x][y] == 4)
//			{
//				upd(x, y, dir);
//				upd(x, y, dir + 1);
//				upd(x, y, dir + 2);
//			}
//			else
//			{
//				upd(x, y, dir);
//				upd(x, y, dir + 1);
//				upd(x, y, dir + 2);
//				upd(x, y, dir + 3);
//			}
//		}
//		int val = 0;
//		for (int i = 0; i < n; i++)
//			for (int j = 0; j < m; j++)
//				val += (tmp[i][j] == 0);
//		//cctv�� ���� ��� ���ð� ���� �ʿ��� �簢����(0)�� ĭ�� ������ ����
//
//		mn = min(val, mn);
//	}
//
//	cout << mn;
//
//	return 0;
//}

//boj18808
//#include<iostream>
//#include<utility>
//using namespace std;
//
//int n, m, k;
//int note[42][42];
//int sticker[12][12];
//int r, c;
//
//void rotate()
////��ƼĿ�� ������ �Լ�(���� ���̿� ��ǥ�� ���� ������ Ȯ�ΰ���)
//{
//	int tmp[12][12];
//	for (int i = 0; i < r; i++)
//		for (int j = 0; j < c; j++)
//			tmp[i][j] = sticker[i][j];
//
//	for (int i = 0; i < r; i++)
//		for (int j = 0; j < c; j++)
//			sticker[j][r-1-i] = tmp[i][j];
//
//	swap(r, c);
//}
//
//bool pastable(int x, int y)
////��Ʈ���� (x,y)�ڸ��� ��ƼĿ�� (0,0)�� �ö󰡰� ��ƼĿ�� ���� �� �ִ���
////Ȯ���ϰ� �����ϴٸ� ���̱�
//{
//	for (int i = 0; i < r; i++)
//	{
//		for (int j = 0; j < c; j++)
//		{
//			if (note[x + i][y + j] == 1 && sticker[i][j] == 1)
//			{
//				return false;
//			}
//		}
//	}
//
//	for (int i = 0; i < r; i++)
//	{
//		for (int j = 0; j < c; j++)
//		{
//			if (sticker[i][j] == 1)
//				note[x + i][y + j] = 1;
//		}
//	}
//	return true;
//}
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> n >> m >> k;
//	while (k--)
//	{
//		cin >> r >> c;
//		for (int i = 0; i < r; i++)
//		{
//			for (int j = 0; j < c; j++)
//			{
//				cin >> sticker[i][j];
//			}
//		}
//
//		for (int rot = 0; rot < 4; rot++)
//			//���� �� �ִ��� Ȯ���� �Ŀ� ���� �� ���� �� ������ �ϹǷ�
//		{
//			bool is_paste = false;	//���ϼ� �ִ��� ������ Ȯ���ϴ� ����
//			for (int x = 0; x <= n - r; x++)
//			{
//				if (is_paste) break;
//				for (int y = 0; y <= m - c; y++)
//				{
//					is_paste = pastable(x, y);
//					if (is_paste) break;
//				}
//			}
//			if (is_paste) break;
//			rotate();
//		}
//	}
//
//	int cnt = 0;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			if (note[i][j]) cnt++;
//		}
//	}
//
//	cout << cnt;
//
//	return 0;
//}

//13335Ʈ��
//#include<iostream>
//#include<queue>
//using namespace std;
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int n, w, l;
//	cin >> n >> w >> l;
//
//	queue<int> notpass;
//	queue<int> bridge;
//	
//	for (int i = 0; i < n; i++)
//	{
//		int x;
//		cin >> x;
//		notpass.push(x);
//	}
//
//	
//
//
//	return 0;
//}


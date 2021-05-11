//15683감시(상어문제들과 같이 다음에 다시 풀어보기)
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
////cctv의 좌표와 cctv의 방향이 인자로 넘어왔을 때 해당 cctv가 
////감시하는 모든!! 공간을 7로 바꾸는 함수
////dir이 0일 때는 하,1일 때 우, 2일 때 상, 3일 때 좌(dx,dy)
//void upd(int x, int y, int dir) {
//	dir = dir % 4;
//	while (1)
//	{
//		x += dx[dir];
//		y += dy[dir];
//		if (x < 0 || x >= n || y < 0 || y >= m) return;	//범위를 벗어나면 return
//		if (tmp[x][y] == 6) return;		//벽을 만나도 return
//		if (tmp[x][y] != 0) continue;	//다른 cctv를 만났을때는 넘어감
//		tmp[x][y] = 7;			//범위를 벗어나지도, 벽을 만나지도, 다른 cctv가 아니었으면 감시한다는 표시
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
//		//cctv방향(=4(상하좌우))^cctv개수 - 1
//		//만큼 cctv를 돌려 모든 경우의 빈칸 개수 구하기
//	    //(모든 경우의 수에 해당하는 부분)
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
//			//brute로 가져온 방향을 %, / 연산을 통해 4진수 값으로 뽑아낸다
//			//위를 cctv개수만큼 반복
//			int x = cctv[i].X;
//			int y = cctv[i].Y;
//			//cctv위치 정보를 받고 밑에서 몇번인지 확인
//
//			if (board[x][y] == 1)
//			{
//				upd(x, y, dir);
//			}
//			else if (board[x][y] == 2)
//			{
//				upd(x, y, dir);
//				upd(x, y, dir + 2);
//				//upd함수에서 dir = dir%4를 하기 때문에 4이상의 수가 넘어가도 상관없다 
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
//		//cctv에 의해 모두 감시가 끝난 맵에서 사각지대(0)인 칸의 개수를 센다
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
////스티커를 돌리는 함수(직접 종이에 좌표를 적어 돌려서 확인가능)
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
////노트북의 (x,y)자리에 스티커의 (0,0)가 올라가게 스티커를 붙일 수 있는지
////확인하고 가능하다면 붙이기
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
//			//붙일 수 있는지 확인한 후에 붙일 수 없을 때 돌려야 하므로
//		{
//			bool is_paste = false;	//붙일수 있는지 없는지 확인하는 변수
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

//13335트럭
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


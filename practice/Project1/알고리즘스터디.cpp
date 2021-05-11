//boj 16236번 아기상어
//#include<iostream>
//#include<queue>
//#include<utility>
//#include<algorithm>
//#define X first
//#define Y second
//#define max_int 22
//#define max_dist 401
//using namespace std;
//
//int board[22][22];
//int visited[22][22];
//int dx[4] = { 0,0,1,-1 };
//int dy[4] = { -1,1,0,0 };
//int n;
//int min_x, min_y,min_dist;
//int shark_size,cnt,result;
//
//void init()
//{
//	min_x = max_int;
//	min_y = max_int;
//	min_dist = max_dist;
//	for (int i = 0; i < n; i++)
//		fill(visited[i], visited[i] + n + 1, -1);
//}
//
//void bfs(int x, int y)		//먹을수 있는 물고기의 위치를 결정
//{
//	queue<pair<int, int>> q;
//	visited[x][y] = 0;
//	q.push({ x,y });
//
//	while (!q.empty())
//	{
//		pair<int, int> cur = q.front(); q.pop();
//
//		for (int dir = 0; dir < 4; dir++)
//		{
//			int nx = cur.X + dx[dir];
//			int ny = cur.Y + dy[dir];
//			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
//			//범위 밖인 경우
//			if (board[nx][ny] > shark_size || visited[nx][ny] != -1) continue;
//			//이미 방문 했거나 상어 크기보다 큰경우
//			visited[nx][ny] = visited[cur.X][cur.Y] + 1;
//			if (board[nx][ny] < shark_size && board[nx][ny] > 0)
//				//먹을 수 있는 경우
//			{
//				if (min_dist > visited[nx][ny])	
//				//현재까지 최소 이동거리보다 짧은경우
//				{
//					min_x = nx;
//					min_y = ny;
//					min_dist = visited[nx][ny];
//				}
//				else if (min_dist == visited[nx][ny])
//				//이동 거리가 현재까지의 최소 이동거리와 같은 경우
//				{
//					if (min_x == nx)
//					{
//						if (min_y > ny){
//							min_x = nx;
//							min_y = ny;
//						}
//					}
//					else if(min_x > nx)
//					{
//						min_x = nx;
//						min_y = ny;
//					}
//				}
//			}
//			q.push({ nx,ny });
//		}
//	}
//}
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int shark_x, shark_y;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < n; j++)
//		{
//			cin >> board[i][j];
//			if (board[i][j] == 9)
//			{
//				board[i][j] = 0;
//				shark_x = i;
//				shark_y = j;
//			}
//		}
//
//	shark_size = 2;
//	cnt = 0;
//
//	while (1)
//	{
//		init();
//
//		bfs(shark_x, shark_y);
//
//		if (min_x != max_int && min_y != max_int)	//먹을수 있는 물고기가 있는 경우
//		{
//			board[min_x][min_y] = 0;
//			cnt++;
//			if (cnt == shark_size)
//			{
//				shark_size++;
//				cnt = 0;
//			}
//			result += visited[min_x][min_y];
//			shark_x = min_x;
//			shark_y = min_y;
//		}
//		else
//			break;
//	}	
//
//	cout << result;
//
//	return 0;
//}


//boj 19236번 청소년상어
//#include<iostream>
//using namespace std;
//
//struct info
//{
//	int x, y, dir;
//};
//info fish[17];
//int dx[8] = { -1,-1,0,1,1,1,0,-1 };
//int dy[8] = { 0,-1,-1,-1,0,1,1,1 };
//int result;
//int arr[4][4];	//물고기 배열
//				//1~16 : 물고기, 0 : 상어, -1: 죽은 물고기
//
//void fish_move()
//{
//	for (int i = 1; i <= 16; i++)
//	{
//		int x = fish[i].x;
//		int y = fish[i].y;
//		int dir = fish[i].dir;
//
//		if (dir == -1) continue;	//죽은 물고기
//		
//		int nx, ny;
//		int ndir = dir;
//		for (int j = 0; j < 8; j++)
//		{
//			nx = x + dx[ndir];
//			ny = y + dy[ndir];
//			if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4)
//				ndir = (ndir + 1) % 8;
//			else
//			{
//				int idx = arr[nx][ny];
//				if (idx == 0)	//상어라면
//				{
//					ndir = (ndir + 1) % 8;
//					continue;
//				}
//				//물고기 자리 교환
//				arr[nx][ny] = i;
//				fish[i].x = nx;
//				fish[i].y = ny;
//				fish[i].dir = ndir;
//
//				arr[x][y] = idx;
//				fish[idx].x = x;
//				fish[idx].y = y;
//				break;
//			}
//		}
//	}
//}
//
//
//void dfs(int x, int y, int dir, int sum)
//{
//	info dup_fish[17];
//	int dup_arr[4][4];
//
//	for (int i = 1; i < 17; i++)
//		dup_fish[i] = fish[i];
//
//	for (int i = 0; i < 4; i++)
//		for (int j = 0; j < 4; j++)
//			dup_arr[i][j] = arr[i][j];
//	//물고기 정보와 위치 정보 복사
//
//	fish_move();
//	//물고기 이동
//
//	//상어 이동
//	int nx = x;
//	int ny = y;
//	while (1)
//	{
//		nx += dx[dir];
//		ny += dy[dir];
//		if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) break;
//		else
//		{
//			int idx = arr[nx][ny];
//			if (idx == -1) continue;	//이동한 자리에 물고기가 없는 경우
//			
//			int new_dir = fish[idx].dir;
//			fish[idx].dir = -1;		//물고기 죽음
//			arr[x][y] = -1;			//물고기 없음
//			arr[nx][ny] = 0;		//상어 이동
//			dfs(nx, ny, new_dir, sum + idx);
//
//			//원래대로 복구
//			fish[idx].dir = new_dir;
//			arr[x][y] = 0;
//			arr[nx][ny] = idx;
//		}
//	}
//	result = max(result, sum);
//
//	//원래대로 복구
//	for (int i = 0; i < 4; i++)
//		for (int j = 0; j < 4; j++)
//			arr[i][j] = dup_arr[i][j];
//
//	for (int i = 0; i < 17; i++)
//		fish[i] = dup_fish[i];
//
//	return;
//}
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int a, b, val;
//	for (int i = 0; i < 4; i++)
//		for (int j = 0; j < 4; j++)
//		{
//			cin >> a >> b;
//			arr[i][j] = a;
//			fish[a].x = i;
//			fish[a].y = j;
//			fish[a].dir = b-1;
//		}
//	val = arr[0][0];
//	int start_dir = fish[val].dir;
//	arr[0][0] = 0;
//	fish[val].dir = -1;
//
//	dfs(0, 0, start_dir, val);
//
//	cout << result;
//
//	return 0;
//}


// p.178 위에서 아래로
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//bool comp(int a, int b)
//{
//	return a > b;
//}
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	vector<int> v;
//	int n,x;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> x;
//		v.push_back(x);
//	}
//	
//	// 1. reverse 함수 사용
//	/*sort(v.begin(), v.end());
//	reverse(v.begin(), v.end());*/
//
//	//2. rbegin(), rend()
//	/*sort(v.rbegin(), v.rend());*/
//
//	//3. 비교함수 인수로 넘기기
//	sort(v.begin(), v.end(), comp);
//
//	for (int i = 0; i < n; i++)
//		cout << v[i] << " ";
//	
//	return 0;
//}

// p.180 성적이 낮은 순서로 학생 출력하기
//#include<iostream>
//#include<vector>
//#include<utility>
//#include<algorithm>
//using namespace std;
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int n;
//	cin >> n;
//
//	vector<pair<int, string>> v;
//	string str;
//	int idx;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> str >> idx;
//		v.push_back({ idx,str });
//	}
//
//	sort(v.begin(), v.end());
//
//	for (int i = 0; i < n; i++)
//	{
//		cout << v[i].second << " ";
//	}
//
//	return 0;
//}

//p.182 두 배열의 원소교체
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int n, k;
//	cin >> n >> k;
//	
//	int x;
//	vector<int> v1;
//	vector<int> v2;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> x;
//		v1.push_back(x);
//	}
//	for (int i = 0; i < n; i++)
//	{
//		cin >> x;
//		v2.push_back(x);
//	}
//
//	sort(v1.begin(), v1.end());
//	sort(v2.rbegin(), v2.rend());
//
//	int tmp;
//	for (int i = 0; i < k; i++)
//	{
//		if (v1[i] > v2[i]) break;
//		tmp = v1[i];
//		v1[i] = v2[i];
//		v2[i] = tmp;
//	}
//
//	int sum = 0;
//	for (int i = 0; i < n; i++)
//	{
//		sum += v1[i];
//	}
//
//	cout << sum;
//
//	return 0;
//}


//p.322 문자열재정렬
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	string str;
//	cin >> str;
//
//	vector<char> v;
//	int total = 0;
//
//	for (int i = 0; i < str.size(); i++)
//	{
//		if (str[i] - '0' >= 0 && str[i] - '0' <= 9)	//숫자라면
//			total += str[i] - '0';
//		else
//		{
//			v.push_back(str[i]);
//		}
//	}
//	sort(v.begin(), v.end());
//
//	for (int i = 0; i < v.size(); i++)
//		cout << v[i];
//	cout << total;
//
//	return 0;
//}

//p.217 1로 만들기
//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//int dp[30002];
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int n;
//	cin >> n;
//
//	dp[1] = 0;
//	
//	for (int i = 2; i <= n; i++)
//	{
//		dp[i] = dp[i - 1] + 1;
//		if (i % 2 == 0)
//		{
//			dp[i] = min(dp[i / 2]+1, dp[i]);
//		}
//		else if (i % 3 == 0)
//		{
//			dp[i] = min(dp[i], dp[i / 3] + 1);
//		}
//		else if (i % 5 == 0)
//		{
//			dp[i] = min(dp[i], dp[i / 5]+1);
//		}
//	}
//
//	cout << dp[n];
//	return 0;
//}

//p.220 개미전사
//1. 테이블 정의
//dp[i] = i번째 식량창고에 왔을 때 얻을 수 있는 최대 식량의 양
//2. 점화식 찾기
//dp[i] = max(dp[i - 1], dp[i - 2]+arr[i])
//3.초기값 정의
//dp[1] = arr[1]
//dp[2] = arr[2]
//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//int arr[102];
//int dp[102];
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int n;
//	cin >> n;
//
//	for (int i = 1; i <= n; i++)
//		cin >> arr[i];
//
//	dp[1] = arr[1];
//	dp[2] = arr[2];
//
//	for (int i = 3; i <= n; i++)
//	{
//		dp[i] = max(dp[i - 2], dp[i - 3]) + arr[i];
//	}
//
//	cout << max(dp[n], dp[n - 1]);
//
//
//	return 0;
//}
//dp[i] = i번째 식량 창고에 도달했을 때 최대 턴 식량의 양
//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//int arr[102];
//int dp[102];
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int n;
//	cin >> n;
//
//	for (int i = 1; i <= n; i++)
//		cin >> arr[i];
//
//	dp[1] = arr[1];
//	dp[2] = max(arr[1],arr[2]);
//
//	for (int i = 3; i <= n; i++)
//	{
//		dp[i] = max(dp[i - 1], dp[i - 2] + arr[i]);
//	}
//
//	cout << dp[n];
//
//
//	return 0;
//}

//p.223 바닥공사
//1. 테이블 정의하기
//dp[i] = 2 * i크기의 직사각형을 채우는 방법의 수
//2. 점화식 찾기
//1) 맨 왼쪽 위 타일이 1 * 2 타일 일 때 남은 칸을 채우는 방법의 수 = > dp[i - 2]
//2) 맨 왼쪽 위 타일이 2 * 1 타일 일 때 남은 칸을 채우는 방법의 수 = > dp[i - 1]
//3) 맨 왼쪽 위 타일이 2 * 2 타일 일 때 남은 칸을 채우는 방법의 수 = > dp[i - 2]
//dp[i] = dp[i - 1] + 2 * (dp[i - 2])
//3. 초기값 정의하기
//dp[1] = 1
//dp[2] = 3
//
//#include<iostream>
//using namespace std;
//
//int dp[1002];
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int n;
//	cin >> n;
//	
//	dp[1] = 1;
//	dp[2] = 3;
//	for (int i = 3; i <= n; i++)
//	{
//		dp[i] =( dp[i - 1] + 2 * (dp[i - 2]) )%796796;
//		/*마지막에만 10007로 나누면 int overflow발생.
//		중간중간 나누어 저장해야한다*/
//	}
//
//	cout << dp[n];
//
//	return 0;
//}


//boj3190 뱀
//#include<iostream>
//#include<utility>
//#include<deque>
//#include<queue>
//#define X first
//#define Y second
//using namespace std;
//
//int board[102][102];	//0 : 비어있음, 1 : 뱀, 2 : 사과
//int n, k, l;
//int dx[4] = { 0,1,0,-1 };	
//int dy[4] = { 1,0,-1,0 };
////우, 하, 좌, 상 방향 표시
//
//int turn(int dir,char op)
//{
//	if (op == 'D')	//오른쪽 90도 회전
//	{
//		dir++;
//		if (dir == 4) dir = 0;
//	}
//	else
//		//왼쪽으로 90도 회전
//	{
//		dir--;
//		if (dir < 0) dir = 3;
//	}
//
//	return dir;
//}
//
//int main()
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> n >> k;
//	for (int i = 0; i < k; i++)
//	{
//		int x, y;
//		cin >> x >> y;
//		board[x-1][y-1] = 2;
//	}
//	
//	queue<pair<int, char>> dir_change;
//	cin >> l;
//	for (int i = 0; i < l; i++)
//	{
//		int t;
//		char d;
//		cin >> t >> d;
//		dir_change.push({ t,d });
//	}
//
//	deque<pair<int, int>> snake;
//	snake.push_back({ 0,0 });
//	board[0][0] = 1;
//
//	int time = 0;
//	int dir = 0;	//처음 보고 있는 방향은 오른쪽
//	while (1)
//	{
//		time++;
//
//		pair<int, int> pre_head = snake.front();
//		pair<int, int> new_head = { pre_head.X + dx[dir],pre_head.Y + dy[dir] };
//		if (new_head.X < 0 || new_head.X >= n || new_head.Y < 0 || new_head.Y >= n) break;	//벽에 부딪히면 게임 끝
//		if (board[new_head.X][new_head.Y] == 1) break;	//자기 몸에 부딪히면 게임 끝
//		if (board[new_head.X][new_head.Y] != 2)	//사과가 없다면
//		{
//			pair<int, int> tail = snake.back();
//			snake.pop_back();
//			board[tail.X][tail.Y] = 0;
//			//꼬리를 줄이고 board에 빈칸으로 표시
//		}	//사과가 있다면 꼬리는 그대로 두고 머리만 추가
//		snake.push_front({ new_head.X,new_head.Y });
//		board[new_head.X][new_head.Y] = 1;
//
//		//time초의 게임이 지나고
//		if (!dir_change.empty())
//		{
//			pair<int, char> dc = dir_change.front();
//			if (time == dc.X)	//방향을 바꿀 시간이면
//			{
//				dir_change.pop();
//				dir = turn(dir, dc.Y);	//새로운 방향 정보
//			}
//		}
//	}
//
//	cout << time;
//
//	return 0;
//}
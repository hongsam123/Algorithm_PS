//재귀 문제==>> 절차지향적 사고를 버리고 귀납적으로만 생각! 
//1. 함수의 정의
//2. base condition
//3. 재귀 식

//#include<iostream>
//using namespace std;
////int sum;
//
//void func1(int num)
//{
//	/*if (num >= 1)
//	{
//		cout << num << " ";
//		func1(num - 1);
//	}	*/
//	if (num == 0) return;
//	//base condition을 잡고
//	cout << num << " ";
//	//k번째 연산을 토대로
//	func1(num-1);
//	//k+1번째 연산을 수행
//}
//
//int  func2(int num)
//{
//	/*sum += num;
//	if (num > 1)
//	{
//		func2(num - 1);
//	}
//	else
//		return 1;*/
//	if (num == 0) return 0;
//	//base condition을 잡고
//	return num + func2(num - 1);
//	//k번째까지 계산을 했다면 k+1번째 계산도 수행할 수 있음
//}
//
//int main(void)
//{
//	int n;
//	cin >> n;
//	func1(n);
//	cout << "\n";
//	//func2(n);
//	//cout << sum;
//	cout << func2(n);
//
//	return 0;
//}
//
//#include<iostream>
//using namespace std;
//using ll = long long;
//
//ll func(ll a, ll b, ll m)
//{
//	if (b == 1) return a % m;
//	//base condition을 잡고
//	ll val = func(a, b / 2, m);
//	//k승의 결과를 토대로
//	val = val * val % m;
//	if (b % 2 == 0) return val;
//	//2k승의 결과를 계산할 수 있다
//	return val * a % m;
//	//(2k+1)승의 결과도 계산할 수 있다.
//}
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	ll a, b, m;
//	cin >> a >> b >> m;
//	cout << func(a, b, m);
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//void hanoi(int a, int b, int num)
////시작 기둥과 도착 기둥을 인자로 받는 함수이어야 한다
//{
//	if (num == 1)
//	{
//		cout << a << " " << b << "\n";
//		return;
//	}
//	//base condition을 정의 
//	hanoi(a, 6 - a - b, num - 1);
//	cout << a << " " << b << "\n";
//	hanoi(6 - a - b, b, num - 1);
//	//k-1번째까지 탑을 옮길수 있으면 k번째 타일을 옮기고 탑을 올리면 되니 k번째 탑도 옮길수 있다
//}
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int n;
//	cin >> n;
//	cout << (1 << n) - 1 << "\n";
//	//left shift 비트연산자(1을 비트기준으로 n칸 민다 = 2^n)
//	hanoi(1,3,n);
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//int func(int num, int r, int c)
//{
//	if (num == 0) return 0;
//	//base condition
//	int half = 1 << (num - 1);
//	//한변 길이의 절반, 즉 2^n-1
//	if (r < half && c < half) return func(num - 1, r, c);
//	if (r < half && c >= half) return half * half + func(num - 1, r, c - half);
//	if (r >= half && c < half) return 2 * half * half + func(num - 1, r - half, c);
//	return 3 * half * half + func(num - 1, r - half, c - half);
//}
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int n, r, c;
//	cin >> n >> r >> c;
//	cout<<func(n, r, c);
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int N;
//
//void print(int cnt)
//{
//	while (cnt--)
//	{
//		cout << "____";
//	}
//	return;
//}
//
//void func(int num)
//{
//	print(N-num);
//	cout << "\"재귀함수가 뭔가요?\"\n";
//	print(N - num);
//	cout << "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n";
//	print(N - num);
//	cout << "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n";
//	print(N - num);
//	cout<<"그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n";
//	if (num == 1)
//	{
//		print(N - num+1);
//		cout << "\"재귀함수가 뭔가요?\"\n";
//		print(N - num+1);
//		cout << "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";
//		print(N - num+1);
//		cout << "라고 답변하였지.\n";
//		return;
//	}
//
//	func(num - 1);
//	print(N - num+1);
//	cout << "라고 답변하였지.\n";
//}
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >>	N;
//	cout<< "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
//	func(N);
//	cout<< "라고 답변하였지.";
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int board[130][130];
//int white;
//int blue;
//
//void func(int x, int y, int num)
//{
//	int tmp = 0;
//	for(int i=x;i<x+num;i++)
//		for (int j = y; j < y + num; j++)
//		{
//			if (board[i][j] == 1)
//				tmp++;
//		}
//	if (tmp == 0) white++;
//	else if (tmp == num * num) blue++;
//	else
//	{
//		func(x, y, num / 2);
//		func(x, y + num / 2, num / 2);
//		func(x + num / 2, y, num / 2);
//		func(x + num / 2, y + num / 2, num / 2);
//	}
//	return;
//}
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < n; j++)
//			cin >> board[i][j];
//
//	func(0,0,n);
//	cout << white << "\n" << blue;
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int board[2188][2188];
//int count[3];
//
//void func(int num, int r, int c)
//{
//	if (num == 1)
//	{
//		count[board[r][c] + 1]++;
//		return;
//	}
//	bool posi = true;
//	int tmp = board[r][c];
//	for (int i = r; i < r + num; i++)
//	{
//		for (int j = c; j < c + num; j++)
//		{
//			if (tmp != board[i][j])
//			{
//				posi = false;
//				for (int a = r; a < r + num; a += num / 3)
//				{
//					for (int b = c; b < c + num; b += num / 3)
//					{
//						func(num / 3, a, b);
//					}
//				}
//				break;
//			}
//			tmp = board[i][j];
//		}
//		if (posi == false) break;
//	}
//
//	if (posi)
//	{
//		count[(board[r][c] + 1)]++;
//		return;
//	}
//	return;
//}
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int n;
//	cin >> n;
//
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < n; j++)
//			cin >> board[i][j];
//
//	func(n, 0, 0);
//
//	for (int i = 0; i < 3; i++)
//		cout << count[i] << "\n";
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int board[65][65];
//
//void func(int num, int r, int c)
//{
//	if (num == 1)
//	{
//		if (board[r][c] == 1)
//			cout << 1;
//		else cout << 0;
//		return;
//	}
//
//	bool posi = true;
//	int tmp = board[r][c];
//	for (int i = r; i < r + num; i++)
//	{
//		for (int j = c; j < c + num; j++)
//		{
//			if (tmp != board[i][j])
//			{
//				posi = false;
//				cout << "(";
//				func(num / 2, r, c);
//				func(num / 2, r, c + (num / 2));
//				func(num / 2, r + (num / 2), c);
//				func(num / 2, r + (num / 2), c + (num / 2));
//				cout << ")";
//				break;
//			}
//			tmp = board[i][j];
//		}
//		if (posi == false)
//			break;
//	}
//	if (posi)
//	{
//		if (tmp) cout << 1;
//		else cout << 0;
//
//		return;
//	}
//
//	return;
//}
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int n;
//	cin >> n;
//
//	string str;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> str;
//		for (int j = 0; j < str.size(); j++)
//			board[i][j] = str[j]-'0';
//	}
//
//	func(n, 0, 0);
//	
//	return 0;
//}

//#include<iostream>
//#include<algorithm>
//using namespace std;
//char board[1025][1025];
//
//void func(int num,int r, int c)
//{
//	if (num == 1)
//	{
//		board[r][c] = '*';
//		return;
//	}
//
//	func(num / 2, r, c);
//	func(num / 2, r, c + num / 2);
//	func(num / 2, r + num / 2, c);
//
//}
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int n;
//	cin >> n;
//
//	for (int i = 0; i < (1 << n); i++)
//	{
//		fill(board[i], board[i] + (1 << n), ' ');
//	}
//
//	func(1<<n,0,0);
//
//	for (int i = 0; i < (1 << n); i++)
//	{
//		for (int j = 0; j < (1 << n)-i ; j++)
//		{
//			cout << board[i][j];
//		}
//		cout << "\n";
//	}
//	return 0;
//}

//#include<iostream>
//#include<algorithm>
//using namespace std;
//char board[6562][6562];
//
//void func(int num, int r, int c)
//{
//	if (num == 3)
//	{
//		for (int i = 0; i < 3; i++)
//		{
//			for (int j = 0; j < 3; j++)
//			{
//				if (i == 1 && j == 1) continue;
//				board[r + i][c + j] = '*';
//			}
//		}
//		return;
//	}
//	int cnt = 0;
//	for (int i = r; i < r+num; i = i + num/3)
//	{
//		for (int j = c; j < c+num; j = j + num / 3)
//		{
//			cnt++;
//			if (cnt == 5) continue;
//			func(num / 3, i, j);
//		}
//	}
//}
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int n;
//	cin >> n;
//
//	for (int i = 0; i < n; i++)
//		fill(board[i], board[i] + n, ' ');
//
//	func(n, 0, 0);
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//			cout << board[i][j];
//		cout << "\n";
//	}
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//char board[3073][6145];
//char DB[][7] =
//{ "  *   ",
//  " * *  ",
//  "***** " };
//
//void func(int num, int r, int c)
//{
//	if (num == 3)
//	{
//		for (int i = 0; i < 3; i++)
//		{
//			for (int j = 0; j < 6; j++)
//			{
//				board[r + i][c + j] = DB[i][j];
//			}
//		}
//		return;
//	}
//
//	func(num / 2, r, c + num / 2);
//	func(num / 2, r + num / 2, c);
//	func(num / 2, r + num / 2, c + num);
//}
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int n;
//	cin >> n;
//
//	for (int i = 0; i < n; i++)
//		fill(board[i], board[i] + 2*n, ' ');
//
//	func(n,0,0);
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < 2 * n; j++)
//			cout << board[i][j];
//		cout << "\n";
//	}
//	return 0;
//}
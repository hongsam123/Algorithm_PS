//N�� M(1)
//#include<iostream>
//using namespace std;
//
//int n, m;
//int arr[10];
//bool isused[10];
//
//void func(int k)
//{
//	if (k == m)
//	{
//		for (int i = 0; i < m; i++)
//			cout << arr[i] << " ";
//		cout << "\n";
//		return;
//	}
//	
//	for (int i = 1; i <= n; i++)
//	{
//		if (!isused[i])
//		{
//			arr[k] = i;
//			isused[i] = 1;
//			func(k + 1);
//			isused[i] = 0;
//		}
//	}
//}
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> n >> m;
//	func(0);
//
//	return 0;
//}

//N�� M(2)
//#include<iostream>
//using namespace std;
//
//int n, m;
//int arr[10];
//bool isused[10];
//
//void func(int k)
//{
//	if (k == m)
//	{
//		for (int i = 0; i < m; i++)
//			cout << arr[i] << " ";
//		cout << "\n";
//		return;
//	}
//	
//	for (int i = 1; i <= n; i++)
//	{
//		if (!isused[i])
//		{
//			if (k == 0)
//			{
//				arr[k] = i;
//				isused[i] = 1;
//				func(k + 1);
//				isused[i] = 0;
//			}
//			else
//				if (arr[k - 1] < i)
//				{
//					arr[k] = i;
//					isused[i] = 1;
//					func(k + 1);
//					isused[i] = 0;
//				}
//		}
//	}
//}
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> n >> m;
//	func(0);
//
//	return 0;
//}
//
// N�� M(3)
//#include<iostream>
//using namespace std;
//
//int n, m;
//int arr[10];
////bool isused[10];
//
//void func(int k)
//{
//	if (k == m)
//	{
//		for (int i = 0; i < m; i++)
//			cout << arr[i] << " ";
//		cout << "\n";
//		return;
//	}
//	
//	for (int i = 1; i <= n; i++)
//	{
//		//if (!isused[i])
//		{
//			arr[k] = i;
//			//isused[i] = 1;
//			func(k + 1);
//			//isused[i] = 0;
//		}
//	}
//}
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> n >> m;
//	func(0);
//
//	return 0;
//}

// N�� M(4)
//#include<iostream>
//using namespace std;
//
//int n, m;
//int arr[10];
////bool isused[10];
//
//void func(int k)
//{
//	if (k == m)
//	{
//		for (int i = 0; i < m; i++)
//			cout << arr[i] << " ";
//		cout << "\n";
//		return;
//	}
//	
//	for (int i = 1; i <= n; i++)
//	{
//		//if (!isused[i])
//		{
//			if (k == 0)
//			{
//				arr[k] = i;
//				//isused[i] = 1;
//				func(k + 1);
//				//isused[i] = 0;
//			}
//			else
//				if (arr[k - 1] <= i)
//				{
//					arr[k] = i;
//					//isused[i] = 1;
//					func(k + 1);
//					//isused[i] = 0;
//				}
//		}
//	}
//}
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> n >> m;
//	func(0);
//
//	return 0;
//}

// N�� M(5)
//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//int n, m;
//int board[10];
//int arr[10];
//bool isused[10002];
//
//void func(int k)
//{
//	if (k == m)
//	{
//		for (int i = 0; i < m; i++)
//			cout << arr[i] << " ";
//		cout << "\n";
//		return;
//	}
//	
//	for (int i = 0; i < n; i++)
//	{
//		int x = board[i];
//		if (isused[x]) continue;
//		arr[k] = x;
//		isused[x] = 1;
//		func(k + 1);
//
//		isused[x] = 0;
//	}
//}
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> n >> m;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> board[i];
//	}
//
//	sort(board, board + n);
//
//	func(0);
//
//	return 0;
//}

//N�� M(6) (next_permutation)
//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//
//int n,m;
//int arr[10002];
//int tmp[10002];
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> n >> m;
//
//	for (int i = 0; i < n; i++)
//	{
//		cin >> arr[i];
//	}
//
//	for (int i = m; i < n; i++)
//	{
//		tmp[i] = 1;
//	}
//	
//	sort(arr, arr + n);
//
//	do
//	{
//		for (int i = 0; i < n; i++)
//		{
//			if (tmp[i] == 0)
//			{
//				cout << arr[i] << " ";
//			}
//		}
//		cout << "\n";
//	} while (next_permutation(tmp, tmp + n));
//
//
//	return 0;
//}

//boj 9663
//#include<iostream>
//using namespace std;
//
//int n;
//bool isused1[16];	//��(y)
//bool isused2[32];	//������� �밢��(x+y)
//bool isused3[32];	//�»���� �밢��(x-y+n-1) => ������ �Ǵ� �ε����� ���ֱ� ���ؼ�
//int cnt;
//
//void func(int cur)	//cur���� ���� ��ġ�� ���ϴ� �Լ�
//{
//	if (cur == n )
//	{
//		cnt++;
//		return;
//	}
//	for (int i = 0; i < n; i++)
//	{
//		if (isused1[i] || isused2[cur + i] || isused3[cur - i + n - 1]) continue;
//		isused1[i] = true;
//		isused2[cur + i] = true;
//		isused3[cur - i + n - 1] = true;
//		func(cur + 1);
//
//		isused1[i] = false;
//		isused2[cur + i] = false;
//		isused3[cur - i + n - 1] = false;
//	}
//}
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	
//	cin >> n;
//	func(0);
//
//	cout << cnt;
//
//	return 0;
//}

//boj1182
//#include<iostream>
//using namespace std;
//
//int n, s;
//int cnt;
//bool isused[22];
//int arr[22];
//int sum;
//
//void func(int nx,int x)
//{
//	if (nx == n) return;
//
//	if (sum == s && nx != 0)		
//	{
//		cnt++;
//		//return;	//return �ϸ� sum�� s ���������� �� ���� ������ ������ �ʰ� return �ع�����
//	}
//
//	for (int i = 0 ; i < n; i++)
//	{
//		if (isused[i] || x>i) continue;		// �̹� ���� ���ߴ� �κм����� ������� ����
//
//		isused[i] = true;
//		sum += arr[i];
//		func(nx + 1,i);
//
//		isused[i] = false;
//		sum -= arr[i];
//	}
//}
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> n >> s;
//	for (int i = 0 ; i < n; i++)
//		cin >> arr[i];
//
//	func(0,0);
//
//	cout << cnt;
//
//	return 0;
//}

// boj 1182 ��ŷ��
// �� ���� ������ ������ ����ϸ� ��� �κм����� �� ���°��� Ʈ���� �׸��ٰ� ����
// �ð� ���⵵�� O(n^2) (�� �ڵ庸�� ������)
//#include<iostream>
//using namespace std;
//
//int n, s;
//int arr[22];
//int cnt;
//
//void func(int cur, int tot)
//{
//	if (cur == n)
//	{
//		if (tot == s)	// �� ���� ������ �ȵ����� ��� ����� ��(cur==n)�� ���ϴ� ���̹Ƿ�
//						// ���� s�� return;
//		{
//			cnt++;
//		}
//		return;
//	}
//	func(cur + 1, tot);
//	func(cur + 1, tot + arr[cur]);
//}
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> n >> s;
//	for (int i = 0; i < n; i++)
//		cin >> arr[i];
//
//	func(0, 0);
//
//	if (s == 0) cnt--;	//s�� 0�϶��� ������ �϶��� ���(-1)
//	cout << cnt;
//
//	return 0;
//}

//next_permutation
//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//int main(void)
//{
//	int a[3] = { 1,1,3 };
//	//next_permutation�� �̿��� ����
//	//
//	//nest_permutation�� ������ ������ ���������� �������� �� 
//	//���� ������ ����� true�� return�Ѵ�
//	//���� ������ ������ ���������� �������� �� ����
//	//������ �����̶�� false�� return
//	do {
//		for (int i = 0; i < 3; i++)
//		{
//			cout << a[i];
//		}
//		cout << "\n";
//	} while (next_permutation(a, a + 3));
//
//	cout << "\n";
//
//	//next_permutation�� �̿��� ����
//	int b[4] = { 0,0,1,1 };
//	do {
//		for (int i = 0; i < 4; i++)
//		{
//			if (b[i] == 0)
//				cout << i + 1;
//		}
//		cout << "\n";
//	} while (next_permutation(b, b + 4));
//	//���� 5���߿� 3���� ������ ���Ѵٸ�
//	//a[5] = {0,0,0,1,1}�� �迭�� ���� �� �ִ�
//
//	return 0;
//}


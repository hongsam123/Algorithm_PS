#include<iostream>
using namespace std;

int n, s;
int cnt;
bool isused[22];
int arr[22];
int sum;

void func(int nx,int x)
{
	if (nx == n) return;

	if (sum == s && nx != 0)		
	{
		cnt++;
		//return;	//return �ϸ� sum�� s ���������� �� ���� ������ ������ �ʰ� return �ع�����
	}

	for (int i = 0 ; i < n; i++)
	{
		if (isused[i] || x>i) continue;		// �̹� ���� ���ߴ� �κм����� ������� ����

		isused[i] = true;
		sum += arr[i];
		func(nx + 1,i);

		isused[i] = false;
		sum -= arr[i];
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s;
	for (int i = 0 ; i < n; i++)
		cin >> arr[i];

	func(0,0);

	cout << cnt;

	return 0;
}

// (�ٸ�Ǯ��)
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

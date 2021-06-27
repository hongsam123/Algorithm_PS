////�̺� Ž��(Binary Search)
//Ư�� �����͸� ã������ �����͸� ���������� Ȯ���ϴ´��
//Ž�� ������ �������� �ٿ����� ã�� Ž�� ���
//
//st�� en�� target�� �ִ� �ε����� ������ ������ ��Ÿ����.�ش� ������ ����ؼ� �پ���
//mid��(st + en) / 2�� ��� c��� Ư���� �������� ������
//- a[mid] < target : ��� mid���� �ε������� target�� ����.st = mid + 1
//- a[mid] > target : ��� mid�̻� �ε������� target�� ����.en = mid - 1
//������ ������ �Ŀ��� mid = (st + en) / 2 �� ����� ���������� mid�� ���Ӱ� ���
//target�� �ʱ� �ε��� ���� ���� ���� ��� �� ����� ��� �����ϴ� ���� st�� en�� �����ȴ�.
//
//�ð� ���⵵�� ������ ������ �� �ݺ������� ��� �������� �پ��Ƿ� O(log N)
//
//int a[10] = {2,3,3,5,6,7,4,2,4,5};
//int len = 10;
//
//int BinarySearch(int target, int len)
//{
//	int st = 0;
//	int en = len - 1;
//	
//	while (st <= en)
//	{
//		int mid = (st + en) / 2;
//		if (a[mid] < target)
//			st = mid + 1;
//		else if (a[mid] > target)
//			en = mid - 1;
//		else
//			return mid;
//	}
//	return -1;	//st>en�� ��� while�� Ż��
//}

//���ĵ� �迭�� �̺�Ž������ �������� ������ �����Ǵ� ���� ����/������ �ε����� ���̰� �ش� �迭 ���� target�� ���� Ƚ��
//���� ���� ���Խ� �������� ������ �����Ǵ� ���� ������ �ε����� ���ϴ� �Լ�

//int lower_idx(int target, int len)
//{
//	int st = 0;
//	int en = len;	//len-1�� �ƴ϶� len���� ���� : en�� mid-1�� �ƴ϶� mid�� ���� ������
//	while (st < en)
//	{
//		int mid = (st + en) / 2;
//		if (arr[mid] >= target) en = mid;
//		else st = mid + 1;	//target�� ũ�ٸ� mid+1;
//	}
//	return st;	//st == en���� ������ �ĺ��� 1���� Ȯ��� ��� while �� Ż��
//}

//int upper_idx(int target, int len)
//{
//	int st = 0;
//	int en = len;
//	while (st < en)
//	{
//		int mid = (st + en) / 2;
//		if (arr[mid] <= target) st = mid + 1;
//		else en = mid;
//	}
//	return st;	//st == en���� ������ �ĺ��� 1���� Ȯ��� ��� while �� Ż��
//}

//p. 197 ��ǰ ã��
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
//	int n, m;
//	cin >> n;
//
//	vector<int> v1;
//	for (int i = 0; i < n; i++)
//	{
//		int x;
//		cin >> x;
//		v1.push_back(x);
//	}
//	sort(v1.begin(), v1.end());
//
//	cin >> m;
//
//	vector<int> v2;
//	for (int j = 0; j < m; j++)
//	{
//		int x;
//		cin >> x;
//		v2.push_back(x);
//	}
//
//	for (int i = 0; i < v2.size(); i++)
//	{
//		int target = v2[i];
//		int start = 0;
//		int end = v1.size();
//		int mid = (start + end) / 2;
//		bool posi = false;
//		while (1)
//		{
//			if (v1[mid] == target)
//			{
//				posi = true;
//				break;
//			}
//			if (start + 1 >= end) break;
//			if (target < v1[mid])
//			{
//				end = mid - 1;
//				mid = (start + end) / 2;
//			}
//			else
//			{
//				start = mid + 1;
//				mid = (start + end) / 2;
//			}
//		}
//		if (posi)
//			cout << "yes" << " ";
//		else
//			cout << "no" << " ";
//	}
//
//	return 0;
//}

//p. 201 ������ �� �����
//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int n, target;
//	cin >> n >> target;
//
//	vector<int> v;
//	for (int i = 0; i < n; i++)
//	{
//		int x;
//		cin >> x;
//		v.push_back(x);
//	}
//
//	sort(v.begin(), v.end());
//
//	int result =0;
//	int start = 0;			//ù��° �� ����
//	int end = v[v.size() - 1];	//������ �� ����
//	int mid = (start + end) / 2;//�� ����
//
//	while (1)
//	{
//		if (start > end) break;
//		int sum = 0;
//		int i = v.size() - 1;		//������ �� �ε���
//
//		while (1)
//		{
//			if (v[i] <= mid||i<=0) break;
//			sum += v[i] - mid;
//			i--;
//		}
//		if (sum < target)
//			end = mid - 1;
//		else
//		{
//			result = mid;
//			start = mid + 1;
//		}
//		mid = (start + end) / 2;
//	}
//
//	cout << result;
//
//	return 0;
//}


//boj 2110 ������ ��ġ
//boj 1477 �ްԼ� ����� (�ٽ� Ǯ��� ���� ����� ����)
//���� �� �Ÿ��� ��� �ްԼҸ� ����� �׸����� ����������
//���� Ž���� ����ȭ������ ���� ������ Ǯ �� �ִ� �Ķ��Ʈ�� Ž��
//(������ ũ�Ⱑ �۾Ƽ� �̺� Ž���� �� �ؾ��� �ʿ�� ����)
//�̹� �����ϴ� �ްԼ� ���� ������ �Ÿ��� �ΰ� ���ο� �ްԼҸ� ���� ��
//���� �ްԼ��� ������ m���� ���������� �Ѵ�
//boj 1920 �� ã��
//boj 10816 ���� ī�� 2
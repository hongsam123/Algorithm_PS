////��������
//int arr[10] = { 3,2,7,116,62,235,1,23,55,77 };
//int n = 10;
//for (int i = n-1; i > 0; i++)
//{
//	int mxidx = 0;
//	for (int j = 1; j < n - i; j++)
//	{
//		if (arr[mxidx] < arr[j]) mxidx = j;
//	}
//	swap(arr[mxidx], arr[i]);
//}
//
////stl�� �̿��� ���
//int arr[10] = { 3,2,7,116,62,235,1,23,55,77 };
//int n = 10;
//for (int i = n - 1; i > 0; i++)
//{
//	swap(*max_element(arr, arr + i + 1), arr[i]);
//	//max_element(arr,arr+k)�� arr[0]...arr[k-1] �߿��� 
//	//�ִ��� ������ �ּҸ� ��ȯ
//	//k = max_element(arr,arr+n) - arr �ϸ�
//	//k���� ��ü �迭���� ���� ū ���Ұ� ����ִ� �ε����� ����
//}
//
////��������
//int arr[5] = { -2,2,4,6,13 };
//int n = 5;
//for (int i = 0; i < n; i++)
//{
//	for (int j = 0; j < n - i - 1; j++)
//	{
//		if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
//	}
//}
//
//// ���� �� ���� + ���������� ��� O(N^2)�� �ð����⵵

//merge sort
//1. �־��� ����Ʈ�� 2���� ������.
//2. ���� ����Ʈ 2���� �����Ѵ�. (�̶� ��͸� ���)
//3. ���ĵ� �� ����Ʈ�� ��ģ��.

//#include<iostream>
//using namespace std;
//
//int n = 10;
//int arr[1000001] = { 15, 25, 22, 357, 16, 23, -53, 12, 46, 3 };
//int tmp[1000001];
//
//void merge(int st, int en)
//{
//	int mid = (st + en) / 2;
//
//	int a = st;
//	int b = mid;
//	for (int i = st; i < en; i++)
//	{
//		if (a == mid) tmp[i] = arr[b++];
//		else if (b == en) tmp[i] = arr[a++];
//		else if (arr[a] <= arr[b]) tmp[i] = arr[a++];
//		else tmp[i] = arr[b++];
//	}
//	for (int i = st; i < en; i++)
//		arr[i] = tmp[i];
//
//	return;
//}
//
//void merge_sort(int st, int en)
//{
//	if (st+1 == en) return;
//	int mid = (st + en) / 2;
//	merge_sort(st, mid);
//	merge_sort(mid, en);
//	merge(st, en);
//}
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	merge_sort(0, n);
//	for (int i = 0; i < n; i++) cout << arr[i] << " ";
//
//	return 0;
//}

////Stable Sort
//�켱 ������ ���� ���Ұ� ������ �϶��� ������ ����� �������� ���� �� �ִ�.
//�� �� �켱������ ���� ���ҵ鳢���� ������ ������ ���󰡵��� �ϴ� ����
//merge sort�� stable sort

////quick sort
//���� ���̺귯���� ������ ��κ� quick sort
//but!!!!!! ���� �ڵ��׽�Ʈ���� ���̺귯���� ���� ���ϰ� ���� ���ĸ� �����ؾ��� ��
//���� x 6 quick sort ���� merge sort(�ƴϸ� heap sort)
//quick sort�� �ּ��� ��� O(NlogN)������ �־��� ��� O(N^2)�̴�

//quick sort�� ������ �߰����� ������ �ʿ����� �ʴ� => in-place sort
//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//int n = 10;
//int arr[1000001] = { 15, 25, 22, 357, 16, 23, -53, 12, 46, 3 };
//
//void quick_sort(int st, int en)
//{
//	if (en <= st + 1) return;
//	int pivot = arr[st];
//	int l = st + 1;
//	int r = en - 1;
//	while(1)
//	{
//		while (l <= r && arr[l] <= pivot) l++;
//		while (l <= r && pivot <= arr[r]) r--;
//		if (r < l) break;
//		swap(arr[l], arr[r]);
//	}
//	swap(arr[st], arr[r]);
//	quick_sort(st, r);
//	quick_sort(r + 1, en);
//}
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	quick_sort(0, n);
//	for (int i = 0; i < n; i++) cout << arr[i] << ' ';
//	
//	return 0;
//}

////counting sort
//���� ������ ������� �������� �� �����ϴ�
//���� ������ õ�� ����(10000000)�϶��� counting sort�� ���� �ִ�.

////radix sort(�������)
//�����ڸ����� �ڸ������� ������ ��迭�� ������ �� ���Ľ�Ų��
//but �޸� ������ ���� ���ϴ�(stl�� ��߸��� ������ ����)
//=>�׷��ٿ� sort�� ������... �׷��� ������ �� ���� ����!

//����, ����, ����Ʈ�� ���ҵ鳢�� ũ�� �񱳸� �ϴ� comparison sort
//ī����, ��� ��Ʈ�� ���ҵ鳢�� ũ�� �񱳸� ���� �ʴ� non-comparison sort

//but ���׿��� ���� �ڵ带 ¥�� ������ ���!
//stl sort�� �־��� ��쿡�� O(NlogN), but stable sort�� �ݵ�� �ʿ��� ��쿡�� stable_sort ��� ����� ����
//pair,tuple�� �տ������� ������� ũ�� �񱳸� �ؼ� ����

////���Լ��� ���ؼ� �Ѱ��ִ°��� ����
//bool comp(int a, int b)
////a�� b�� �տ� �;��� �� true, �׷��� ���� �� false
//{
//	if (a % 5 != b % 5) return a % 5 < b % 5;
//	return a < b;
//}
//
//int a[7] = { 1,2,3,4,5,6,7 };
//sort(a, a + 7, comp);

//boj1431 �ø��� ��ȣ
//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//
//int n;
//
//bool comp(const string& a, const string& b)
////�Լ��� ���ڷ� stl�̳� ����ü ��ü�� �Ǿ ������ �Ͼ�� ���� ���綧����
////�׳� string a, string b�� ������ ���� �ٶ��� ���� �ʴ�(���ʿ��� ���� �߻�)
////�׷��Ƿ� ���� ���� reference�� �����°��� �ٶ���
//{
//	if (a.length() != b.length()) return a.length() < b.length();
//	//���̰� �ٸ��� ó��
//
//	int asum = 0;
//	int bsum = 0;
//	for (int i = 0; i < a.length(); i++)
//		if (0 <= a[i] - '0' && a[i] - '0' <= 9)
//			asum += a[i] - '0';
//	for (int i = 0; i < b.length(); i++)
//		if (0 <= b[i] - '0' && b[i] - '0' <= 9)
//			bsum += b[i] - '0';
//	if (asum != bsum) return asum < bsum;
//	//���� �����϶�, �� �ڸ��� �� ������ �͸� ���� �� ũ������� ó��
//
//	int idx = 0;
//	while (1)
//	{
//		if (idx == a.length()) break;
//		if (a[idx] != b[idx]) break;
//		idx++;
//	}
//	if (idx == a.length()) return false;
//	else return a[idx] < b[idx];
//}
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> n;
//	vector<string> v;
//
//	for (int i = 0; i < n; i++)
//	{
//		string str;
//		cin >> str;
//		v.push_back(str);
//	}
//
//	sort(v.begin(), v.end(),comp);
//
//	for (int i = 0; i < n; i++)
//	{
//		cout << v[i] << "\n";
//	}
//
//	return 0;
//}


//boj11728 �迭 ��ġ�� + merge
//boj2751 �� �����ϱ�2 + merge
//boj10989 �� �����ϱ�3 + counting
//boj15688 �� �����ϱ�4 + counting
//boj10814 ���̼� ����
//boj11651 ��ǥ �����ϱ�2

//������ ����
//boj11652 ī��
//boj1181�� �ܾ� ����
//boj11656 ���̻� �迭
//boj2910 �� ����	
//comp�Լ� ���� pair(?) �ȵ�(?) �ٽ��ѹ�����
//boj7795 ���� ���ΰ� ���� ���ΰ�
//boj1015 ���� ����
//boj1764 �躸��
//boj1715 ī�� �����ϱ�
//�켱���� ť ���(�� �Լ��� ���� �ڵ����� ���ĵǴ� ť)
//boj11279 �ִ���
//boj1927 �ּ���
//boj7662 ���� �켱���� ť
//map ���
//boj10825 ������
//boj5648 ������ ����
//boj18870 ��ǥ ����
//boj18310 ���׳�
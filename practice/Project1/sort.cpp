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

// boj 11728(merge sort)
//#include<iostream>
//using namespace std;
//
//int n, m;
//int a[1000002];
//int b[1000002];
//int ans[2000004];
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> n >> m;
//
//	for (int i = 0; i < n; i++)
//		cin >> a[i];
//
//	for (int i = 0; i < m; i++)
//		cin >> b[i];
//
//	int i = 0;
//	int j = 0;
//	for (int k = 0; k < n + m; k++)
//	{
//		if (i == n)
//		{
//			ans[k] = b[j];
//			j++;
//			continue;
//		}
//		else if (j == m)
//		{
//			ans[k] = a[i];
//			i++;
//			continue;
//		}
//
//		if (a[i] <= b[j])
//			//merge sort�� stable sort�� ���� �����ϸ�
//			//a[i]�� b[j]�� ���� �� �� ���� ���� a[i]�� ���� ���� ���� ����
//		{
//			ans[k] = a[i];
//			i++;
//		}
//		else
//		{
//			ans[k] = b[j];
//			j++;
//		}
//	}
//	for (int i = 0; i < n + m; i++)
//	{
//		cout << ans[i] << " ";
//	}
//
//	return 0;
//}
//
//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//
//int n, m;
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> n >> m;
//
//	vector<int> v;
//	for (int i = 0; i < n + m; i++)
//	{
//		int x;
//		cin >> x;
//		v.push_back(x);
//	}
//
//	sort(v.begin(),v.end());
//
//	for (int i = 0; i < n + m; i++)
//	{
//		cout << v[i] << " ";
//	}
//
//	return 0;
//}

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

// boj 2751(�� �ڵ� ����) �� �����ϱ�2


//Stable Sort
//�켱 ������ ���� ���Ұ� ������ �϶��� ������ ����� �������� ���� �� �ִ�.
//�� �� �켱������ ���� ���ҵ鳢���� ������ ������ ���󰡵��� �ϴ� ����
//merge sort�� stable sort

//quick sort
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

//counting sort
//���� ������ ������� �������� �� �����ϴ�
//���� ������ õ�� ����(10000000)�϶��� counting sort�� ���� �ִ�.

// boj 10989(counting sort)
//#include<iostream>
//using namespace std;
//
//int n;
//int cnt[10002];
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> n;
//	int x;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> x;
//		cnt[x]++;
//	}
//
//	int total = 0;
//	int a = 1;
//	while (1)
//	{
//		if (total == n ) break;
//		if (cnt[a])
//		{
//			cout << a << "\n";
//			cnt[a]--;
//			total++;
//		}
//		else
//		{
//			a++;
//		}
//	}
//
//	return 0;
//}

//boj15688(counting sort)
//#include<iostream>
//using namespace std;
//
//int n;
//int cnt[2000004];
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> n;
//	int x;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> x;
//		cnt[x + 1000000]++;
//	}
//
//	int total = 0;
//	int a = 0;
//	while (1)
//	{
//		if (total == n) break;
//		if (cnt[a])
//		{
//			cout << a-1000000 << "\n";
//			cnt[a]--;
//			total++;
//		}
//		else
//		{
//			a++;
//		}
//	}
//
//	return 0;
//}

//radix sort(�������)
//�����ڸ����� �ڸ������� ������ ��迭�� ������ �� ���Ľ�Ų��
//but �޸� ������ ���� ���ϴ�(stl�� ��߸��� ������ ����)
//=>�׷��ٿ� sort�� ������... �׷��� ������ �� ���� ����!

//����, ����, ����Ʈ�� ���ҵ鳢�� ũ�� �񱳸� �ϴ� comparison sort
//ī����, ��� ��Ʈ�� ���ҵ鳢�� ũ�� �񱳸� ���� �ʴ� non-comparison sort

//but ���׿��� ���� �ڵ带 ¥�� ������ ���~!
//stl sort�� �־��� ��쿡�� O(NlogN), but stable sort�� �ݵ�� �ʿ��� ��쿡�� stable_sort ��� ����� ����
//pair,tuple�� �տ������� ������� ũ�� �񱳸� �ؼ� ����

//���Լ��� ���ؼ� �Ѱ��ִ°��� ����
//bool comp(int a, int b)
////a�� b�� �տ� �;��� �� true, �׷��� ���� �� false
//{
//	if (a % 5 != b % 5) return a % 5 < b % 5;
//	return a < b;
//}
//
//int a[7] = { 1,2,3,4,5,6,7 };
//sort(a, a + 7, comp);

// boj 1431��
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

//boj 10814��
//#include<iostream>
//#include<vector>
//#include<tuple>
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
//	vector<tuple<int,int, string>> v;
//	string str;
//	int idx;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> idx >> str;
//		v.push_back({ idx,i,str });
//	}
//
//	sort(v.begin(), v.end());
//
//	for (int i = 0; i < n; i++)
//	{
//		cout << get<0>(v[i]) << " " << get<2>(v[i]) << "\n";
//	}
//
//	return 0;
//}

// boj 11651
//#include<iostream>
//#include<vector>
//#include<utility>
//#include<algorithm>
//using namespace std;
//
//int n;
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cin >> n;
//
//	vector<pair<int, int>> v;
//	for (int i = 0; i < n; i++)
//	{
//		int x, y;
//		cin >> x >> y;
//		v.push_back({ y,x });
//	}
//
//	sort(v.begin(), v.end());
//
//	for (int i = 0; i < n; i++)
//		cout << v[i].second << " " << v[i].first << "\n";
//
//	return 0;
//}

// boj10989
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int n;
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cin >> n;
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
//	for (int i = 0; i < n; i++)
//		cout << v[i] << "\n";
//
//	return 0;
//}

//������ ����

////boj 11652��
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
//	int n;
//	cin >> n;
//	
//	vector<long long> v;
//	for (int i = 0; i < n; i++)
//	{
//		long long x;
//		cin >> x;
//		v.push_back(x);
//	}
//	sort(v.begin(), v.end());
//
//	int max_cnt = 1;
//	long long num = v[0];
//	int cnt = 1;
//	long long pre = v[0];
//
//	if (v.size() > 1)
//	{
//		for (int i = 1; i < v.size(); i++)
//		{
//			if (v[i] == pre)
//			{
//				cnt++;
//				if (cnt > max_cnt)
//				{
//					max_cnt = cnt;
//					num = v[i];
//				}
//			}
//			else
//			{
//				cnt = 1;
//			}
//			pre = v[i];
//		}
//	}
//
//	cout << num;
//
//	return 0;
//}

//boj 1181��
//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//
//bool comp(string a, string b)
//{
//	if (a.size() != b.size()) return a.size() < b.size();
//	return a < b;
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
//	vector<string> v;
//	for (int i = 0; i < n; i++)
//	{
//		string str;
//		cin >> str;
//		
//		bool posi = true;
//		for (int i = 0; i < v.size(); i++)
//		{
//			if (v[i] == str)
//			{
//				posi = false;
//				break;
//			}
//		}
//		if(posi)
//			v.push_back(str);
//	}
//
//	sort(v.begin(), v.end(),comp);
//
//	for (int i = 0; i < v.size(); i++)
//		cout << v[i] << "\n";
//
//	return 0;
//}

// boj 11656��
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
//	string str;
//	cin >> str;
//
//	string str_new = "";
//	vector<string> v;
//	for (int i = str.size()-1; i >= 0 ; i--)
//	{
//		str_new = str[i] + str_new;
//		v.push_back(str_new);
//	}
//
//	sort(v.begin(), v.end());
//
//	for (int i = 0; i < v.size(); i++)
//		cout << v[i] << "\n";
//
//	return 0;
//}


//boj2910

//#include<iostream>
//#include<algorithm>
//#include<vector>
//#include<utility>
//using namespace std;
//
//bool comp(pair<int, int> a, pair<int, int> b)
//{
//	return a.first > b.first;
//}
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int n;
//	int c;
//	cin >> n >> c;
//
//	vector<pair<int, int>> v;
//	for (int i = 0; i < n; i++)
//	{
//		int x;
//		bool isused = false;
//		cin >> x;
//		if (v.empty()) 
//		{
//			v.push_back({ 1,x });
//			isused = true;
//		}
//		else
//		{
//			for (int j = 0; j < v.size(); j++)
//			{
//				if (v[j].second == x)
//				{
//					v[j].first++;
//					isused = true;
//					//break;
//				}
//			}
//		}
//		if (!isused)
//			v.push_back({ 1,x });
//	}
//
//	sort(v.begin(), v.end(), comp);
//
//	for (int i = 0; i < v.size(); i++)
//	{
//		for (int j = 0; j < v[i].first; j++)
//		{
//			cout << v[i].second << " ";
//		}
//	}
//
//	return 0;
//}

//#include<iostream>
//#include<algorithm>
//#include<vector>
//#include<utility>
//using namespace std;
//
//struct info
//{
//	int idx, num, cnt;
//};
//
//bool comp(info a, info b)
//{
//	if(a.cnt!=b.cnt) return a.cnt > b.cnt;
//	return a.idx < b.idx;
//}
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int n;
//	int c;
//	cin >> n >> c;
//
//	vector<info> v;
//	for (int i = 0; i < n; i++)
//	{
//		int x;
//		bool isused = false;
//		cin >> x;
//		if (v.empty())
//		{
//			v.push_back({ i,x,1 });
//			isused = true;
//		}
//		else
//		{
//			for (int j = 0; j < v.size(); j++)
//			{
//				if (v[j].num == x)
//				{
//					v[j].cnt++;
//					isused = true;
//					break;
//				}
//			}
//		}
//		if (!isused)
//			v.push_back({ i,x,1 });
//	}
//
//	sort(v.begin(), v.end(), comp);
//
//	for (int i = 0; i < v.size(); i++)
//	{
//		for (int j = 0; j < v[i].cnt; j++)
//		{
//			cout << v[i].num << " ";
//		}
//	}
//
//	return 0;
//}

//...����...? �� �� Ǯ�̴� �׾ Ʋ����...?
//�� �̹����� �ѽð��� Ǯ���� comp�Լ��� �����ΰͰ���

//boj7795
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
//	int test;
//	cin >> test;
//
//	while (test--)
//	{
//		int n, m;
//		cin >> n >> m;
//
//		vector<int> a;
//		vector<int> b;
//
//		int x;
//		for (int i = 0; i < n; i++)
//		{
//			cin >> x;
//			a.push_back(x);
//		}
//		for (int i = 0; i < m; i++)
//		{
//			cin >> x;
//			b.push_back(x);
//		}
//
//		sort(a.rbegin(), a.rend());
//		sort(b.begin(), b.end());
//
//		int cnt = 0;
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = 0; j < m; j++)
//			{
//				if (a[i] > b[j]) cnt++;
//				else break;
//			}
//		}
//		cout << cnt << "\n";
//	}
//
//	return 0;
//}

//boj 1015
//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//int arr[52];
//int tmp[52];
//bool check[52];
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
//	{
//		cin >> arr[i];
//		tmp[i] = arr[i];
//	}
//
//	sort(tmp, tmp + n);
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if (arr[i] == tmp[j] && check[j] == false)
//			{
//				cout << j << " ";
//				check[j] = true;
//				break;
//			}
//		}
//	}
//
//	return 0;
//}

//boj1764
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
//	int n, m;
//	cin >> n >> m;
//
//	vector<vector<string>> v(27);
//	string str;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> str;
//		v[str[0] - 'a'].push_back(str);
//	}
//
//	vector<string> ans;
//	for (int i = 0; i < m; i++)
//	{
//		cin >> str;
//		int x = str[0] - 'a';
//		for (int j = 0; j < v[x].size(); j++)
//		{
//			if (v[x][j] == str)
//				ans.push_back(str);
//		}
//	}
//
//	sort(ans.begin(), ans.end());
//
//	cout << ans.size() << "\n";
//	for (int i = 0; i < ans.size(); i++)
//		cout << ans[i] << "\n";
//
//	return 0;
//}
//�ð� �ʰ�.. ���� �ϸ� ���� ���� �׻� �پ��ְ� �ȴ�
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
//	int n, m;
//	cin >> n >> m;
//
//	vector<string> v;
//	string str;
//	for (int i = 0; i < n + m; i++)
//	{
//		cin >> str;
//		v.push_back(str);
//	}
//
//	sort(v.begin(), v.end());
//
//	vector<string> ans;
//	string pre = v[0];
//	for (int i = 1; i < v.size(); i++)
//	{
//		if (v[i] == pre) ans.push_back(v[i]);
//		pre = v[i];
//	}
//
//	cout << ans.size() << "\n";
//	for (string e : ans)
//		cout << e << "\n";
//
//	return 0;
//}

//boj 1715 ī�� �����ϱ�
//�켱���� ť ���(�� �Լ��� ���� �ڵ����� ���ĵǴ� ť)
//#include<iostream>
//#include<queue>
//using namespace std;
//
//priority_queue<int, vector<int>, greater<int>> pq;
//
//int main()
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		int x;
//		cin >> x;
//		pq.push(x);
//	}
//
//	if (pq.size() == 1)
//	{
//		cout << 0;
//		return 0;
//	}
//
//	int total = 0;
//	while (pq.size() != 1)
//	{
//		int x = pq.top(); pq.pop();
//		int y = pq.top(); pq.pop();
//		int sum = x + y;
//		total += sum;
//		pq.push(sum);
//	}
//	pq.
//
//	cout << total;
//
//	return 0;
//}

//boj 11279 �ִ���
//boj 1927 �ּ���
//boj 7662 ���� �켱���� ť
//#include<iostream>
//#include<map>
//#include<queue>
//using namespace std;
//
//int main()
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int test;
//	cin >> test;
//	while (test--)
//	{
//		int n;
//		cin >> n;
//		
//		int cnt = 0;				//ť�� ����ִ� ���� ����
//		map<int, int> num_count;	//<���� ����, ���� ����>
//		priority_queue<int> pq_d;	//�������� �켱���� ť
//		priority_queue<int, vector<int>, greater<int>> pq_a; //�������� �켱���� ť
//		while (n--)
//		{
//			char ch;
//			int x;
//			cin >> ch >> x;
//
//			if (ch == 'I')
//			{
//				cnt++;
//				pq_d.push(x);
//				pq_a.push(x);
//				if (num_count.find(x) != num_count.end())
//					num_count[x]++;
//				else num_count[x] = 1;
//			}
//			else
//			{
//				if (cnt == 0) continue;
//				if (x == 1)	//���� ū�� ����
//				{
//					while (1)
//					{
//						if (!num_count[pq_d.top()])
//						{
//							pq_d.pop();
//						}
//						else
//						{
//							num_count[pq_d.top()]--;
//							cnt--;
//							break;
//						}
//					}
//				}
//				else
//					���� ���� �� ����
//				{
//					while (1)
//					{
//						if (!num_count[pq_a.top()])
//						{
//							pq_a.pop();
//						}
//						else
//						{
//							num_count[pq_a.top()]--;
//							cnt--;
//							break;
//						}
//					}
//				}
//			}
//		}
//		if (cnt==0)
//		{
//			cout << "EMPTY"<<"\n";
//		}
//		else
//		{
//			int max_num, min_num;
//			while (1)
//			{
//				if (num_count[pq_d.top()])
//				{
//					max_num = pq_d.top();
//					break;
//				}
//				else
//				{
//					pq_d.pop();
//				}
//			}
//			while (1)
//			{
//				if (num_count[pq_a.top()])
//				{
//					min_num = pq_a.top();
//					break;
//				}
//				else
//				{
//					pq_a.pop();
//				}
//			}
//			cout << max_num << " " << min_num << "\n";
//		}
//	}
//	return 0;
//}
//map���θ� �ٽ� Ǯ��
//#include<iostream>
//#include<map>
//using namespace std;
//
//int main()
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int test;
//	cin >> test;
//	while (test--)
//	{
//		int n;
//		cin >> n;
//
//		map<int, int> m;	//<���� ����, ���� ����>
//		
//		while (n--)
//		{
//			char ch;
//			int x;
//			cin >> ch >> x;
//
//			if (ch == 'I')
//			{
//				m[x] += 1;
//			}
//			else
//			{
//				if (m.empty()) continue;
//
//				if (x == 1)	//���� ū�� ����
//				{
//					if (m.rbegin()->second == 1)
//						m.erase(--m.end());
//					else
//						m.rbegin()->second -= 1;
//				}
//				else
//					//���� ���� �� ����
//				{
//					if (m.begin()->second == 1)
//						m.erase(m.begin());
//					else
//						m.begin()->second -= 1;
//				}
//			}
//		}
//		if (m.empty())
//		{
//			cout << "EMPTY" << "\n";
//		}
//		else
//		{
//			cout << m.rbegin()->first << " " << m.begin()->first << "\n";
//		}
//	}
//	return 0;
//}

//boj10825 ������
//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//
//struct info {
//	string name;
//	int korean;
//	int english;
//	int math;
//};
//vector<info> student;
//
//bool comp(info& a, info& b)
//{
//	if (a.korean != b.korean) return a.korean > b.korean;
//	if (a.english != b.english) return a.english < b.english;
//	if (a.math != b.math) return a.math > b.math;
//	return a.name < b.name;
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
//	{
//		string str;
//		int a, b, c;
//		cin >> str >> a >> b >> c;
//		student.push_back({ str,a,b,c });
//	}
//
//	sort(student.begin(), student.end(), comp);
//
//	for (int i = 0; i < n; i++)
//	{
//		cout << student[i].name << "\n";
//	}
//
//	return 0;
//}

////boj 5648�� ������ ����
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
//	int n;
//	cin >> n;
//
//	vector<long long> v;
//	for (int i = 0; i < n; i++)
//	{
//		string str;
//		cin >> str;
//
//		long long new_num = 0;
//		long long x = 1;
//		for (int j = 0; j < str.size(); j++)
//		{
//			new_num += (str[j] - '0') * x;
//			x *= 10;
//		}
//		v.push_back(new_num);
//	}
//	sort(v.begin(), v.end());
//
//	for (int i = 0; i < n; i++)
//		cout << v[i] << "\n";
//
//	return 0;
//}
//

////boj 18870 ��ǥ ����
//#include<iostream>
//#include<utility>
//#include<algorithm>
//#include<vector>
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
//	vector<pair<int, int>> v;
//	for (int i = 0; i < n; i++)
//	{
//		int x;
//		cin >> x;
//		v.push_back({ x,i });
//	}
//
//	sort(v.begin(), v.end());
//
//	vector<pair<int, int>> v1;
//	int prev = v[0].first;
//	
//	v1.push_back({ v[0].second,0 });
//
//	int val = 0;
//
//	if (v.size() > 1)
//	{
//		for (int i = 1; i < n; i++)
//		{
//			if (v[i].first == prev)
//			{
//				v1.push_back({ v[i].second,val });
//			}
//			else
//			{
//				val++;
//				v1.push_back({ v[i].second,val });
//			}
//			prev = v[i].first;
//		}
//	}
//	sort(v1.begin(), v1.end());
//
//	for (int i = 0; i < v1.size(); i++)
//	{
//		cout << v1[i].second << " ";
//	}
//
//	return 0;
//}

//boj18310 ���׳�

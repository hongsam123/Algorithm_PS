////선택정렬
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
////stl을 이용한 방법
//int arr[10] = { 3,2,7,116,62,235,1,23,55,77 };
//int n = 10;
//for (int i = n - 1; i > 0; i++)
//{
//	swap(*max_element(arr, arr + i + 1), arr[i]);
//	//max_element(arr,arr+k)는 arr[0]...arr[k-1] 중에서 
//	//최댓값인 원소의 주소를 반환
//	//k = max_element(arr,arr+n) - arr 하면
//	//k에는 전체 배열에서 가장 큰 원소가 들어있는 인덱스가 들어간다
//}
//
////버블정렬
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
//// 위의 두 정렬 + 삽입정렬은 모두 O(N^2)의 시간복잡도

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
//			//merge sort의 stable sort를 위해 가능하면
//			//a[i]와 b[j]가 같을 때 맨 앞의 원소 a[i]가 먼저 들어가는 것이 좋다
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
//1. 주어진 리스트를 2개로 나눈다.
//2. 나눈 리스트 2개를 정렬한다. (이때 재귀를 사용)
//3. 정렬된 두 리스트를 합친다.

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

// boj 2751(위 코드 변형) 수 정렬하기2


//Stable Sort
//우선 순위가 같은 원소가 여러개 일때는 정렬한 결과가 유일하지 않을 수 있다.
//이 때 우선순위가 같은 원소들끼리는 원래의 순서를 따라가도록 하는 정렬
//merge sort는 stable sort

//quick sort
//각종 라이브러리의 정렬은 대부분 quick sort
//but!!!!!! 만약 코딩테스트에서 라이브러리를 쓰지 못하고 직접 정렬를 구현해야할 시
//절대 x 6 quick sort 말고 merge sort(아니면 heap sort)
//quick sort는 최선의 경우 O(NlogN)이지만 최악의 경우 O(N^2)이다

//quick sort의 장점은 추가적인 공간이 필요하지 않다 => in-place sort
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
//수의 범위가 어느정도 한정적일 때 유리하다
//수의 범위가 천만 이하(10000000)일때는 counting sort를 쓸수 있다.

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

//radix sort(기수정렬)
//일의자리부터 자리수별로 수열을 재배열해 수열을 총 정렬시킨다
//but 메모리 공간의 낭비가 심하다(stl을 써야만이 구현이 용이)
//=>그럴바엔 sort를 쓰겠지... 그래서 구현을 할 일이 없다!

//버블, 머지, 퀵소트는 원소들끼리 크기 비교를 하는 comparison sort
//카운팅, 라딕스 소트는 원소들끼리 크기 비교를 하지 않는 non-comparison sort

//but 코테에서 정렬 코드를 짜고 있으면 흑우~!
//stl sort는 최악의 경우에도 O(NlogN), but stable sort가 반드시 필요한 경우에는 stable_sort 사용 방법은 동일
//pair,tuple은 앞에서부터 순서대로 크기 비교를 해서 정렬

//비교함수를 정해서 넘겨주는것이 가능
//bool comp(int a, int b)
////a가 b의 앞에 와야할 때 true, 그렇지 않을 때 false
//{
//	if (a % 5 != b % 5) return a % 5 < b % 5;
//	return a < b;
//}
//
//int a[7] = { 1,2,3,4,5,6,7 };
//sort(a, a + 7, comp);

// boj 1431번
//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//
//int n;
//
//bool comp(const string& a, const string& b)
////함수의 인자로 stl이나 구조체 객체를 실어서 보내면 일어나는 값의 복사때문에
////그냥 string a, string b로 보내는 것은 바람직 하지 않다(불필요한 연산 발생)
////그러므로 위와 같이 reference를 보내는것이 바람직
//{
//	if (a.length() != b.length()) return a.length() < b.length();
//	//길이가 다를때 처리
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
//	//같은 길이일때, 각 자리수 중 숫자인 것만 더해 그 크기순으로 처리
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

//boj 10814번
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

//정렬의 응용

////boj 11652번
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

//boj 1181번
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

// boj 11656번
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

//...왜지...? 왜 위 풀이는 죽어도 틀렸지...?
//하 이문제만 한시간을 풀었다 comp함수가 문제인것같다

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
//시간 초과.. 정렬 하면 같은 것은 항상 붙어있게 된다
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

//boj 1715 카드 정렬하기
//우선순위 큐 사용(비교 함수에 따라 자동으로 정렬되는 큐)
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

//boj 11279 최대힙
//boj 1927 최소힙
//boj 7662 이중 우선순위 큐
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
//		int cnt = 0;				//큐에 들어있는 정수 개수
//		map<int, int> num_count;	//<들어온 정수, 들어온 개수>
//		priority_queue<int> pq_d;	//내림차순 우선순위 큐
//		priority_queue<int, vector<int>, greater<int>> pq_a; //오름차순 우선순위 큐
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
//				if (x == 1)	//가장 큰수 삭제
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
//					가장 작은 수 삭제
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
//map으로만 다시 풀기
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
//		map<int, int> m;	//<들어온 정수, 들어온 개수>
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
//				if (x == 1)	//가장 큰수 삭제
//				{
//					if (m.rbegin()->second == 1)
//						m.erase(--m.end());
//					else
//						m.rbegin()->second -= 1;
//				}
//				else
//					//가장 작은 수 삭제
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

//boj10825 국영수
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

////boj 5648번 역원소 정렬
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

////boj 18870 좌표 압축
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

//boj18310 안테나

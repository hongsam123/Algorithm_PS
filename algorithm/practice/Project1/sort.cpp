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

////Stable Sort
//우선 순위가 같은 원소가 여러개 일때는 정렬한 결과가 유일하지 않을 수 있다.
//이 때 우선순위가 같은 원소들끼리는 원래의 순서를 따라가도록 하는 정렬
//merge sort는 stable sort

////quick sort
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

////counting sort
//수의 범위가 어느정도 한정적일 때 유리하다
//수의 범위가 천만 이하(10000000)일때는 counting sort를 쓸수 있다.

////radix sort(기수정렬)
//일의자리부터 자리수별로 수열을 재배열해 수열을 총 정렬시킨다
//but 메모리 공간의 낭비가 심하다(stl을 써야만이 구현이 용이)
//=>그럴바엔 sort를 쓰겠지... 그래서 구현을 할 일이 없다!

//버블, 머지, 퀵소트는 원소들끼리 크기 비교를 하는 comparison sort
//카운팅, 라딕스 소트는 원소들끼리 크기 비교를 하지 않는 non-comparison sort

//but 코테에서 정렬 코드를 짜고 있으면 흑우!
//stl sort는 최악의 경우에도 O(NlogN), but stable sort가 반드시 필요한 경우에는 stable_sort 사용 방법은 동일
//pair,tuple은 앞에서부터 순서대로 크기 비교를 해서 정렬

////비교함수를 정해서 넘겨주는것이 가능
//bool comp(int a, int b)
////a가 b의 앞에 와야할 때 true, 그렇지 않을 때 false
//{
//	if (a % 5 != b % 5) return a % 5 < b % 5;
//	return a < b;
//}
//
//int a[7] = { 1,2,3,4,5,6,7 };
//sort(a, a + 7, comp);

//boj1431 시리얼 번호
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


//boj11728 배열 합치기 + merge
//boj2751 수 정렬하기2 + merge
//boj10989 수 정렬하기3 + counting
//boj15688 수 정렬하기4 + counting
//boj10814 나이순 정렬
//boj11651 좌표 정렬하기2

//정렬의 응용
//boj11652 카드
//boj1181번 단어 정렬
//boj11656 접미사 배열
//boj2910 빈도 정렬	
//comp함수 인자 pair(?) 안됨(?) 다시한번참고
//boj7795 먹을 것인가 먹힐 것인가
//boj1015 수열 정렬
//boj1764 듣보잡
//boj1715 카드 정렬하기
//우선순위 큐 사용(비교 함수에 따라 자동으로 정렬되는 큐)
//boj11279 최대힙
//boj1927 최소힙
//boj7662 이중 우선순위 큐
//map 사용
//boj10825 국영수
//boj5648 역원소 정렬
//boj18870 좌표 압축
//boj18310 안테나
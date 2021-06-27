////이분 탐색(Binary Search)
//특정 데이터를 찾기위해 데이터를 순차적으로 확인하는대신
//탐색 범위를 절반으로 줄여가며 찾는 탐색 방법
//
//st와 en은 target이 있는 인덱스로 가능한 범위를 나타낸다.해당 범위는 계속해서 줄어든다
//mid는(st + en) / 2로 계산 c언어 특성상 나머지는 버린다
//- a[mid] < target : 적어도 mid이하 인덱스에는 target이 없다.st = mid + 1
//- a[mid] > target : 적어도 mid이상 인덱스에는 target이 없다.en = mid - 1
//범위를 변경한 후에는 mid = (st + en) / 2 로 변경된 범위에서의 mid를 새롭게 계산
//target이 초기 인덱스 범위 내에 없는 경우 위 방법을 계속 진행하다 보면 st와 en이 역전된다.
//
//시간 복잡도는 구간의 범위가 매 반복문마다 계속 절반으로 줄어드므로 O(log N)
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
//	return -1;	//st>en일 경우 while문 탈출
//}

//정렬된 배열의 이분탐색에서 오름차순 순서가 유지되는 제일 왼쪽/오른쪽 인덱스의 차이가 해당 배열 내에 target의 등장 횟수
//같은 수를 삽입시 오름차순 순서가 유지되는 제일 왼쪽의 인덱스를 구하는 함수

//int lower_idx(int target, int len)
//{
//	int st = 0;
//	int en = len;	//len-1이 아니라 len임을 주의 : en에 mid-1이 아니라 mid가 들어가기 때문에
//	while (st < en)
//	{
//		int mid = (st + en) / 2;
//		if (arr[mid] >= target) en = mid;
//		else st = mid + 1;	//target이 크다면 mid+1;
//	}
//	return st;	//st == en으로 가능한 후보가 1개로 확장될 경우 while 문 탈출
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
//	return st;	//st == en으로 가능한 후보가 1개로 확장될 경우 while 문 탈출
//}

//p. 197 부품 찾기
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

//p. 201 떡볶이 떡 만들기
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
//	int start = 0;			//첫번째 떡 길이
//	int end = v[v.size() - 1];	//마지막 떡 길이
//	int mid = (start + end) / 2;//떡 높이
//
//	while (1)
//	{
//		if (start > end) break;
//		int sum = 0;
//		int i = v.size() - 1;		//마지막 떡 인덱스
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


//boj 2110 공유기 설치
//boj 1477 휴게소 세우기 (다시 풀어보기 위와 비슷한 문제)
//가장 긴 거리의 가운데 휴게소를 세우는 그리디라고 생각했지만
//이진 탐색과 최적화문제를 결정 문제로 풀 수 있는 파라메트릭 탐색
//(문제의 크기가 작아서 이분 탐색을 꼭 해야할 필요는 없음)
//이미 존재하는 휴게소 사이 일정한 거리를 두고 새로운 휴게소를 세울 때
//세운 휴게소의 갯수가 m값과 같을때까지 한다
//boj 1920 수 찾기
//boj 10816 숫자 카드 2
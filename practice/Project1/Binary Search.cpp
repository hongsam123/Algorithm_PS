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


//boj 2110
//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//
//int a[200002];
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int n, c;
//	cin >> n >> c;
//
//	vector<int> v;
//	for (int i = 0; i < n; i++)
//	{
//		int x;
//		cin >> x;
//		v.push_back(x);
//	}
//	sort(v.begin(), v.end());
//
//	for (int i = 0; i < c; i++)
//		a[i] = 0;
//	for (int j = c; j < n; j++)
//		a[j] = 1;
//
//	int answer = 0;
//
//	do{
//		vector<int> tmp;
//		for (int i = 0; i < n; i++)
//		{
//			if (a[i] == 0)
//			{
//				tmp.push_back(v[i]);
//			}
//		}
//
//		int pre = tmp[0];
//		int min_size = tmp[1] - tmp[0];
//		for (int i = 1; i < tmp.size(); i++)
//		{
//			min_size = min(min_size, tmp[i] - pre);
//			pre = tmp[i];
//		}
//
//		answer = max(answer, min_size);
//
//	} while (next_permutation(a, a + n));
//
//	cout << answer;
//
//
//	return 0;
//}
//
//==> 시간 초과 (이분 탐색으로 푸는 문제)
//공유기 사이 최대 거리의 범위를 줄여나가며 찾는 이분 탐색
//mid값이 답이 될수 있는가??를 확인하며 범위 좁혀나가기
//
//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//
//int a[200002];
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int n, c;
//	cin >> n >> c;
//
//	vector<int> v;
//	for (int i = 0; i < n; i++)
//	{
//		int x;
//		cin >> x;
//		v.push_back(x);
//	}
//	sort(v.begin(), v.end());
//
//	int start = 1;	//공유기 사이 거리 최소값
//	int end = v[v.size() - 1] - v[0];	//공유기 사이 거리 최대값
//	int mid = (end + start) / 2;	//가능한 공유기 사이 거리의 범위중 중간값
//									//mid 값을 변경시켜가며 찾는다
//	int answer = 0;
//	while (start <= end)
//	{
//		int house = v[0];	//맨 처음 집부터 세웠을 때
//		int cnt = 1;	//공유기를 세울수 있는 집 개수
//		for (int i = 1; i < n; i++)
//		{
//			if (house + mid <= v[i])	//집을 세울 수 있다면
//			{
//				house = v[i];	//세우고
//				cnt++;			//공유기가 세워진 집 개수 +1
//			}
//		}
//		if (cnt < c)	//공유기를 c개만큼 세울수 없다면
//						//(공유기 사이 거리값인 mid가 너무 크다)
//		{
//			end = mid - 1;	//범위를 좁혀서 더 작은 거리일때를 조사
//		}
//		else
//			//공유기를 c개 이상 세울 수 있다면
//		{
//			start = mid + 1;	//범위를 넓혀서 더 넓은 거리일때도 가능한지 검사
//			answer = mid;	//현재 최적의 답을 저장
//		}
//
//		mid = (start + end) / 2;
//	}
//
//	cout << answer;
//
//	return 0;
//}

//boj1477번 휴게소 세우기 (다시 풀어보기 위와 비슷한 문제)
//가장 긴 거리의 가운데 휴게소를 세우는 그리디라고 생각했지만
//이진 탐색과 최적화문제를 결정 문제로 풀 수 있는 파라메트릭 탐색
//(문제의 크기가 작아서 이분 탐색을 꼭 해야할 필요는 없음)
//이미 존재하는 휴게소 사이 일정한 거리를 두고 새로운 휴게소를 세울 때
//세운 휴게소의 갯수가 m값과 같을때까지 한다

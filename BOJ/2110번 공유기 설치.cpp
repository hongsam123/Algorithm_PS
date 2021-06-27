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
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int a[200002];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, c;
	cin >> n >> c;

	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());

	int start = 1;	//공유기 사이 거리 최소값
	int end = v[v.size() - 1] - v[0];	//공유기 사이 거리 최대값
	int mid = (end + start) / 2;	//가능한 공유기 사이 거리의 범위중 중간값
									//mid 값을 변경시켜가며 찾는다
	int answer = 0;
	while (start <= end)
	{
		int house = v[0];	//맨 처음 집부터 세웠을 때
		int cnt = 1;	//공유기를 세울수 있는 집 개수
		for (int i = 1; i < n; i++)
		{
			if (house + mid <= v[i])	//집을 세울 수 있다면
			{
				house = v[i];	//세우고
				cnt++;			//공유기가 세워진 집 개수 +1
			}
		}
		if (cnt < c)	//공유기를 c개만큼 세울수 없다면
						//(공유기 사이 거리값인 mid가 너무 크다)
		{
			end = mid - 1;	//범위를 좁혀서 더 작은 거리일때를 조사
		}
		else
			//공유기를 c개 이상 세울 수 있다면
		{
			start = mid + 1;	//범위를 넓혀서 더 넓은 거리일때도 가능한지 검사
			answer = mid;	//현재 최적의 답을 저장
		}

		mid = (start + end) / 2;
	}

	cout << answer;

	return 0;
}

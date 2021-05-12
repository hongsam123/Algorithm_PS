//가장 긴 거리의 가운데 휴게소를 세우는 그리디라고 생각했지만
//이진 탐색과 최적화문제를 결정 문제로 풀 수 있는 파라메트릭 탐색
//(문제의 크기가 작아서 이분 탐색을 꼭 해야할 필요는 없음)
//이미 존재하는 휴게소 사이 일정한 거리를 두고 새로운 휴게소를 세울 때
//세운 휴게소의 갯수가 m값과 같을때까지 한다
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> v;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, l;
	cin >> n >> m >> l;

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}
	v.push_back(0);
	v.push_back(l);
	//거리의 시작과 끝지점
	sort(v.begin(), v.end());

	//parameteric search
	int left = 1;
	int right = l - 1;
	int mid = 0;
	while (left <= right)
	{
		mid = (left + right) / 2;	//새로 편의점을 세울 편의점 사이 거리
		int new_store = 0;
		for (int i = 1; i < v.size(); i++)
		{
			int dist = v[i] - v[i - 1];
			new_store += dist / mid;	//기존에 있는 두 편의점 사이 세울 수 있는 편의점 개수
			if (dist % mid == 0)	//나누어 떨어지면 겹치니 하나를 빼준다
				new_store--;
		}
		
		if (new_store > m)	//편의점을 너무 많이 세움
			left = mid + 1;	//편의점 사이 거리의 간격을 늘인다
		else
			right = mid - 1;	//편의점을 더 세워야 한다면 간격을 좁힌다
	}

	cout << left;

	return 0;
}

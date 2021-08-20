//증명 : 현재 최선의 선택을 하지 않았을 경우 
//		최선의 선택을 했을 때 보다 더 결과가 좋아질 수 없다는 것을 보인다
//그리디 - 현재 시간 t에서 시작할수 있는 모든 회의 중 가장
//			빨리 끝나는 회의를 선택
//그리디 증명 - 가장 빨리 끝나는 회의를 선택하지 않았을 경우
//				보장되는 가능한 회의의 수보다
//				가장 빨리 끝나는 회의를 선택했을 경우
//				보장되는 가능한 회의의 수가 크거나 같다 (위의 경우의 수만큼은 보장하기 때문에)
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<pair<int, int>> v;

	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v.push_back({ y,x });
	}

	sort(v.begin(), v.end());

	int t = 0;
	int cnt = 0;

	for (int i = 0; i < v.size(); i++)
	{
		if (t > v[i].second) continue;
		cnt++;
		t = v[i].first;
	}

	cout << cnt;

	return 0;
}

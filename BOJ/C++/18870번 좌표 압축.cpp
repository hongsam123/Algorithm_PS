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

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int x[1000005];
vector<int> uni;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
		uni.push_back(x[i]);
	}

	sort(uni.begin(), uni.end());
	uni.erase(unique(uni.begin(), uni.end()), uni.end());
	//unique => 중복 제거를 수행해주는 함수
	//정렬된 배열에서 중복된 원소들을 앞으로 모아주고 뒤쪽에는 쓰레기값을 채운다
	//쓰레기 값이 시작되는 구간 return 
	//vector의 erase로 뒤쪽을 날린다

	for (int i = 0; i < n; i++) {
		cout << lower_bound(uni.begin(), uni.end(), x[i]) - uni.begin() << " ";
	}

	return 0;
}

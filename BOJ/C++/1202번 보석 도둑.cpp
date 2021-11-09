//가장 가격이 높은 보석 부터 확인하며 해당 보석을 담을 수 있는 
//가방 중 최대 무게가 가장 작은 가방을 이용해 보석을 담는 것이 이득
#include<iostream>
#include<queue>
#include<utility>
#include<set>
#define pii pair<long long,long long>
using namespace std;

long long  n, k;
priority_queue<pii> pq;	//<보석의가격, 무게>	: 가격으로 내림차순 정렬
long long ans;
multiset<long long> bag;	//<가방에 담을 수 있는 최대 무게, 가방의 갯수>

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	
	for (long long i = 0; i < n; i++) {
		long long m, v;
		cin >> m >> v;
		pq.push({ v,m });
	}

	for (long long i = 0; i < k; i++) {
		long long x;
		cin >> x;
		bag.insert(x);
	}

	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		long long curV = cur.first;
		long long curM = cur.second;

		auto iter = bag.lower_bound(curM);

		if(iter != bag.end()) {
			ans += curV;
			bag.erase(iter);
		}
	}

	cout << ans;

	return 0;
}

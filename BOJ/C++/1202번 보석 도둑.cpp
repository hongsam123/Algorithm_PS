//���� ������ ���� ���� ���� Ȯ���ϸ� �ش� ������ ���� �� �ִ� 
//���� �� �ִ� ���԰� ���� ���� ������ �̿��� ������ ��� ���� �̵�
#include<iostream>
#include<queue>
#include<utility>
#include<set>
#define pii pair<long long,long long>
using namespace std;

long long  n, k;
priority_queue<pii> pq;	//<�����ǰ���, ����>	: �������� �������� ����
long long ans;
multiset<long long> bag;	//<���濡 ���� �� �ִ� �ִ� ����, ������ ����>

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

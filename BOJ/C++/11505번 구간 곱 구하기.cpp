#include<iostream>
#define ll long long
using namespace std;

int n, m, k;
ll num[1000002];
ll tree[4000008];

ll init(int left, int right, int node) {
	if (left != right) {
		int mid = (left + right) / 2;
		init(left, mid, node * 2);
		init(mid + 1, right, node * 2 + 1);
		tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % 1000000007;
		return tree[node];
	}
	else //리프노드일 경우
	{
		tree[node] = num[left];
		return tree[node];
	}
}

ll query(int left, int right, int node, int queryLeft, int queryRight)
{
	//노드가 쿼리 범위 밖
	if (queryRight<left || queryLeft>right)
		return 1;
	else if (queryLeft <= left && right <= queryRight)	//노드가 쿼리 범위 안에 들어옴(판단 가능)
		return tree[node];
	else //노드가 쿼리 범위에 걸쳐있음(판단 불가)
	{
		int mid = (left + right) / 2;
		return (query(left, mid, node * 2, queryLeft, queryRight) * query(mid + 1, right, node * 2 + 1, queryLeft, queryRight))% 1000000007;
	}
}

ll update(int left, int right, int node, int target, ll val)
{
	//구하려는 범위가 밖에 있는 경우 해당 노드의 값을 돌려준다
	//부모 노드의 곱을 구해야 하기 때문에
	if (target<left || target>right) return tree[node];

	//리프노드 업데이트
	if (left == right)
		return tree[node] = val;
	//cout << tree[node] << "\n";

	int mid = (left + right) / 2;
	ll leftResult = update(left, mid, node * 2, target, val);
	ll rightResult = update(mid + 1, right, node * 2 + 1, target, val);
	return tree[node] = (leftResult * rightResult) % 1000000007;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
	}

	init(1, n, 1);

	for (int i = 0; i < m + k; i++) {
		int a, b;
		ll c;
		cin >> a >> b >> c;
		if (a == 1) {
			num[b] = c;
			update(1, n, 1, b, c);
		}
		else
			cout << query(1, n, 1, b, c) << "\n";
	}

	return 0;

}

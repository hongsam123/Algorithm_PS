//캐싱을 해서 빠르게 답을 구하고 싶은데
//데이터가 중간에 바뀐다==> 인덱스 트리로 해결
#include<iostream>
#define ll long long
#define S 1000000
using namespace std;

int tree[4000008];
int n;

ll query(int left, int right, int node, ll count)
{
	//리프에 도착
	if (left == right)
		return left;

	int mid = (left + right) / 2;
	if (tree[node * 2] >= count)
		return query(left, mid, node * 2, count);
	else
		return query(mid + 1, right, node * 2 + 1, count - tree[node * 2]);

}

void update(int left, int right, int node, int target, ll diff)
{
	//루트부터 시작 update
	if (target >= left && target <= right)
	{
		tree[node] += diff;
		if (left != right)
		{
			int mid = (left + right) / 2;
			update(left, mid, node * 2, target, diff);
			update(mid + 1, right, node * 2 + 1, target, diff);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		if (a == 1)
		{
			int index = query(1, S, 1, b);
			update(1, S, 1, index, -1);
			cout << index << "\n";
		}
		else
		{
			int c;
			cin >> c;
			update(1, S, 1, b, c);
		}
	}

	return 0;
}

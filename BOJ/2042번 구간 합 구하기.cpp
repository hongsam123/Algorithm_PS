#include<iostream>
#define ll long long
using namespace std;

int n, m, k;
ll num[1000002];
ll tree[4000008];

ll init(int left,int right, int node)
{
	//���� ����� ���
	if (left != right)
	{
		int mid = (left + right) / 2;
		init(left, mid, node * 2);
		init(mid + 1, right, node * 2 + 1);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
		return tree[node];
	}
	else //��������� ���
	{
		tree[node] = num[left];
		return tree[node];
	}
}

ll query(int left, int right, int node, int queryLeft, int queryRight)
{
	//��尡 ���� ���� ��
	if (queryRight<left || queryLeft>right)
		return 0;
	else if ( queryLeft<=left&& right<=queryRight)	//��尡 ���� ���� �ȿ� ����(�Ǵ� ����)
		return tree[node];
	else //��尡 ���� ������ ��������(�Ǵ� �Ұ�)
	{
		int mid = (left + right) / 2;
		return query(left, mid, node * 2, queryLeft, queryRight) + query(mid+1,right,node*2+1,queryLeft,queryRight);
	}
}

void update(int left, int right, int node, int target, ll diff)
{
	//��Ʈ���� ���� update
	if (target<left || target>right) return;

	tree[node] += diff;

	if (left != right)
	{
		int mid = (left + right) / 2;
		update(left, mid, node * 2, target, diff);
		update(mid + 1, right, node * 2 + 1, target, diff);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> num[i];
	}

	init(1, n, 1);

	for (int i = 0; i < m+k; i++)
	{
		int a, b;
		ll c;
		cin >> a >> b >> c;
		if (a == 1)
		{
			ll diff = c - num[b];
			num[b] = c;
			update(1, n, 1, b, diff);
		}
		else
			cout<<query(1, n, 1, b, c)<<"\n";
	}


	return 0;
}

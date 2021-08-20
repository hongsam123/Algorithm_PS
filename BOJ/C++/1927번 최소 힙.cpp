#include<iostream>
#include<queue>
using namespace std;

priority_queue<long long,vector<long long>,greater<long long>> pq;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	while (n--)
	{
		long long x;
		cin >> x;
		if (x == 0)
		{
			if (pq.empty())
				cout << 0 << "\n";
			else
			{
				long long num = pq.top(); pq.pop();
				cout << num << "\n";
			}
		}
		else
		{
			pq.push(x);
		}
	}

	return 0;
}

//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//int heap[100005];
//int sz = 0;	//heap size
//
//void add(int x)
//{
//	sz++;
//	heap[sz] = x;
//	int idx = sz;
//	while (idx != 1)
//	{
//		int par = idx / 2;
//		if (heap[par] < heap[idx]) break;
//		swap(heap[par], heap[idx]);
//		idx = par;
//	}
//}
//
//int top()
//{
//	if (sz == 0) return 0;
//	return heap[1];
//}
//
//void pop()
//{
//	if (sz == 0) return;
//	swap(heap[1], heap[sz]);
//	sz--;
//	int idx = 1;
//	while (2 * idx <= sz)	//2*idx가 sz보다 크면 idx가 leaf노드
//	{
//		int min_child;
//		if (heap[idx * 2]<heap[idx * 2 + 1] or 2 * idx + 1>sz)	//왼쪽 자식값이 더 작거나 왼쪽 자식밖에 없는 경우
//			min_child = 2 * idx;
//		else
//			min_child = 2 * idx + 1;
//		if (heap[min_child] > heap[idx]) break;
//		swap(heap[min_child], heap[idx]);
//		idx = min_child;
//	}
//}
//
//int main()
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int n;
//	cin >> n;
//
//	while (n--)
//	{
//		int x;
//		cin >> x;
//		if (x == 0)
//		{
//			cout << top() << "\n";
//			pop();
//		}
//		else
//			add(x);
//	}
//
//	return 0;
//}

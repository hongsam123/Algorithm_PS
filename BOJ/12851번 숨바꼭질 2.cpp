//#include<iostream>
//#include<algorithm>
//#include<queue>
//using namespace std;
//
//int dist[100002];
//int cnt[100002];	//////////////////////
//queue<int> q;
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int n, k;
//	cin >> n >> k;
//
//	if (n == k)
//	{
//		cout << 0<<"\n"<<1;	///////////////////
//		return 0;
//	}
//
//	fill(dist, dist + 100002, -1);
//
//	dist[n] = 0;
//	cnt[n] = 1;
//	q.push(n);
//
//	while (!q.empty())
//	{
//		int cur = q.front(); q.pop();
//		if (cur == k)	//������ ã���� ��
//			break;
//		for (int n : {cur + 1, cur - 1, cur * 2})
//		{
//			if (n < 0 || n>100000) continue;
//			if (dist[n] != -1)	//�湮 �ߴ� ���̸�
//			{
//				if (dist[cur] + 1 == dist[n])
//					cnt[n]++;	/////////////////////////
//				continue;
//			}
//			dist[n] = dist[cur] + 1;	//�ִ� �Ÿ� ����
//			cnt[n] = cnt[cur];			//ó�� �� ���
//			q.push(n);
//		}
//	}
//	cout << dist[k] << "\n" << cnt[k];
//
//	return 0;
//}

#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int dist[100002];
int cnt[100002];
queue<int> q;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	if (n == k)
	{
		cout << 0 <<"\n"<<1;
		return 0;
	}

	fill(dist, dist + 100002, -1);

	dist[n] = 0;
	cnt[n] = 1;
	q.push(n);

	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		for (int nx : {cur + 1, cur - 1, cur * 2})
		{
			if (nx < 0 || nx>100000) continue;
			if (dist[nx] != -1)	//�湮 �ߴ� ���̸�
			{
				if (dist[cur] + 1 == dist[nx])//�ִ� �Ÿ��� ���� ���
					cnt[nx] += cnt[cur];
			}
			else
				//�湮�� ó�� �ߴٸ�
			{
				dist[nx] = dist[cur] + 1;	//�ִ� �Ÿ� ����
				cnt[nx] = cnt[cur];			//ó�� �� ���
				q.push(nx);
			}
		}
	}

	cout << dist[k] << "\n" << cnt[k];

	return 0;
}

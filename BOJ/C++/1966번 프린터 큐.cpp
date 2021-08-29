#include<iostream>
#include<queue>
#include<utility>
using namespace std;

int check[12];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int test;
	cin >> test;

	while (test--)
	{
		int n, m;
		int cnt = 0;
		cin >> n >> m;

		fill(check, check + 10 , 0);

		queue<pair<int, int>> q;
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			check[x]++;
			if (i == m)
			{
				q.push({ x, 1 });
			}
			else
			{
				q.push({ x,0 });
			}
		}

		
		int priority = 9;
		while (1)
		{
			pair<int, int> cur = q.front(); q.pop();
			while (1)
				//���� ������ �� ���� ���� �켱���� ����
			{
				if (check[priority])
					break;
				priority--;
			}
			if (cur.first == priority)
				//���� ������ �켱������ ���� ���� ��� ���,
				//�� ������ Ȯ���ϰ� ���� ������� Ż��
			{
				check[priority]--;
				cnt++;
				if (cur.second)
					break;
			}
			else
				//���� ���� �켱������ �ƴѰ��
				//�ٽ� �� �ڷ� ���ġ
			{
				q.push({ cur.first,cur.second });
			}
		}

		cout << cnt << "\n";
	}

	return 0;
}

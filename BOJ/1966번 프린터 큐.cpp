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
				//현재 문서들 중 가장 높은 우선순위 결정
			{
				if (check[priority])
					break;
				priority--;
			}
			if (cur.first == priority)
				//현재 문서가 우선순위가 가장 높을 경우 출력,
				//그 문서가 확인하고 싶은 문서라면 탈출
			{
				check[priority]--;
				cnt++;
				if (cur.second)
					break;
			}
			else
				//가장 높은 우선순위가 아닌경우
				//다시 맨 뒤로 재배치
			{
				q.push({ cur.first,cur.second });
			}
		}

		cout << cnt << "\n";
	}

	return 0;
}

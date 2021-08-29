#include<iostream>
#include<queue>
#include<map>
#include<utility>
using namespace std;

int n;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;	//<���۽ð�, ����ð�>
int nclass;
priority_queue<int, vector<int>, greater<int>> Class;	//<������ �ð�>

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int s, t;
		cin >> s >> t;
		pq.push({ s,t });
	}

	while (!pq.empty())
	{
		auto cur = pq.top(); pq.pop();
		int s = cur.first;
		int t = cur.second;

		if (Class.empty())
		{
			nclass = 1;
			Class.push(t);
		}
		else
		{
			int cur = Class.top();
			//���ǽ� ����
			if (cur <= s)
			{
				Class.pop();
				Class.push(t);
			}
			else //���ǽ� ����
			{
				nclass++;
				Class.push(t);	
			}
		}
	}

	cout << nclass;


	return 0;
}

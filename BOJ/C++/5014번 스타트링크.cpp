//#include<iostream>
//using namespace std;
//
//int f, s, g, u, d;
//
//int main(void)
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> f >> s >> g >> u >> d;
//	int  answer = 0;
//
//	if (s > g && d == 0)
//		cout << "use the stairs";
//	else if (s < g && u == 0)
//		cout << "use the stairs";
//	else if (u != 0 && abs(s - g) % u != 0 && d == 0)
//		cout << "use the stairs";
//	else if (d != 0 && abs(s - g) % d != 0 && u == 0)
//		cout << "use the stairs";
//	else if (u != 0 && abs(s - g) % u != 0 && d == u)
//		cout << "use the stairs";
//	else if (d != 0 && abs(s - g) % d != 0 && u == d)
//		cout << "use the stairs";
//	else if (u != 0 && abs(s - g) % u != 0 && d > f)
//		cout << "use the stairs";
//	else if (d != 0 && abs(s - g) % d != 0 && u > f)
//		cout << "use the stairs";
//	else if (u != 0 && abs(s - g) % u != 0 && abs(s - g) % d != 0)
//		cout << "use the stairs";
//	else if (d != 0 && abs(s - g) % d != 0 && abs(s - g) % u != 0)
//		cout << "use the stairs";
//	else
//	{
//		while (s != g)
//		{
//			while (s < g)
//			{
//				if (s + u > f)
//				{
//					s -= d;
//					answer++;
//				}
//				s += u;
//				answer++;
//			}
//			while (s > g)
//			{
//				if (s - d <= 0)
//				{
//					s += u;
//					answer++;
//				}
//				s -= d;
//				answer++;
//			}
//		}
//		cout << answer;
//	}
//
//	return 0;
//}

//bfs로 다시 풀이
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int f, s, g, u, d;
int dist[1000002];
queue<int> q;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> f >> s >> g >> u >> d;

	fill(dist, dist + f + 1, -1);
	q.push(s);
	dist[s] = 0;

	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		if (cur == g)
		{
			break;
		}

		for (int a = 1; a <= 2; a++)
		{
			if (a == 1)		//올라가기
			{
				int nx = cur + u;
				if (nx > f || dist[nx] >= 0) continue;
				dist[nx] = dist[cur] + 1;
				q.push(nx);
			}
			else //내려가기
			{
				int nx = cur - d;
				if (nx < 1 || dist[nx] >= 0) continue;
				dist[nx] = dist[cur] + 1;
				q.push(nx);
			}
		}
	}

	if (dist[g] >= 0)
		cout << dist[g];
	else
		cout<<"use the stairs";

	return 0;
} 

//#include<iostream>
//#include<map>
//#include<queue>
//using namespace std;
//
//int main()
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int test;
//	cin >> test;
//	while (test--)
//	{
//		int n;
//		cin >> n;
//		
//		int cnt = 0;				//큐에 들어있는 정수 개수
//		map<int, int> num_count;	//<들어온 정수, 들어온 개수>
//		priority_queue<int> pq_d;	//내림차순 우선순위 큐
//		priority_queue<int, vector<int>, greater<int>> pq_a; //오름차순 우선순위 큐
//		while (n--)
//		{
//			char ch;
//			int x;
//			cin >> ch >> x;
//
//			if (ch == 'I')
//			{
//				cnt++;
//				pq_d.push(x);
//				pq_a.push(x);
//				if (num_count.find(x) != num_count.end())
//					num_count[x]++;
//				else num_count[x] = 1;
//			}
//			else
//			{
//				if (cnt == 0) continue;
//				if (x == 1)	//가장 큰수 삭제
//				{
//					while (1)
//					{
//						if (!num_count[pq_d.top()])
//						{
//							pq_d.pop();
//						}
//						else
//						{
//							num_count[pq_d.top()]--;
//							cnt--;
//							break;
//						}
//					}
//				}
//				else
//					가장 작은 수 삭제
//				{
//					while (1)
//					{
//						if (!num_count[pq_a.top()])
//						{
//							pq_a.pop();
//						}
//						else
//						{
//							num_count[pq_a.top()]--;
//							cnt--;
//							break;
//						}
//					}
//				}
//			}
//		}
//		if (cnt==0)
//		{
//			cout << "EMPTY"<<"\n";
//		}
//		else
//		{
//			int max_num, min_num;
//			while (1)
//			{
//				if (num_count[pq_d.top()])
//				{
//					max_num = pq_d.top();
//					break;
//				}
//				else
//				{
//					pq_d.pop();
//				}
//			}
//			while (1)
//			{
//				if (num_count[pq_a.top()])
//				{
//					min_num = pq_a.top();
//					break;
//				}
//				else
//				{
//					pq_a.pop();
//				}
//			}
//			cout << max_num << " " << min_num << "\n";
//		}
//	}
//	return 0;
//}
//map으로만 다시 풀기
#include<iostream>
#include<map>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int test;
	cin >> test;
	while (test--)
	{
		int n;
		cin >> n;

		map<int, int> m;	//<들어온 정수, 들어온 개수>
		
		while (n--)
		{
			char ch;
			int x;
			cin >> ch >> x;

			if (ch == 'I')
			{
				m[x] += 1;
			}
			else
			{
				if (m.empty()) continue;

				if (x == 1)	//가장 큰수 삭제
				{
					if (m.rbegin()->second == 1)
						m.erase(--m.end());
					else
						m.rbegin()->second -= 1;
				}
				else
					//가장 작은 수 삭제
				{
					if (m.begin()->second == 1)
						m.erase(m.begin());
					else
						m.begin()->second -= 1;
				}
			}
		}
		if (m.empty())
		{
			cout << "EMPTY" << "\n";
		}
		else
		{
			cout << m.rbegin()->first << " " << m.begin()->first << "\n";
		}
	}
	return 0;
}

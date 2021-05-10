#include<iostream>
#include<deque>
#include<string>
#include<algorithm>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	char trash;
	int t,n,num,cnt;
	bool error,reverse;
	string p, trash2;

	cin >> t;

	while (t--)
	{
		deque<int> dq;
		error = false;
		reverse = false;
		cnt = 0;
		cin >> p >> n;
		if (n != 0)
		{
			cin >> trash;
			while (n--)
			{
				cin >> num >> trash;
				dq.push_back(num);
			}
			for (int i = 0; i < p.size(); i++)
			{
				if (p[i] == 'R')		//R일때 뒤집어짐을 표시 
				{
					if (reverse == false)
						reverse = true;
					else reverse = false;
				}
				else					//D일때 
				{
					if (!dq.empty())	//뒤집어져 있는지 여부에 따라 삭제 
					{
						if (reverse)
							dq.pop_back();
						else dq.pop_front();
					}
					else				//비어있으면 ERROR 
					{
						error = true;
						break;
					}
				}
			}
		}
		else	//배열이 비어있는 경우 
		{
			cin >> trash2;
			for (int i = 0; i < p.size(); i++)
				if (p[i] == 'D')	//D가 나오면 error 
				{
					error = true;
					break;
				}
		}
		if (error)
			cout << "error" << '\n';
		else	//error가 아닐때 결과 출력 
		{
			cout << "[";
			if (!reverse)
			{
				for (int i = 0; i < dq.size(); i++)
				{
					cout << dq[i];
					cnt++;
					if (cnt == dq.size()) break;
					cout << ",";
				}
			}
			else	//뒤집어진 상태면 반대로 
			{
				for (int i = dq.size() - 1; i >= 0; i--)
				{
					cout << dq[i];
					cnt++;
					if (cnt == dq.size()) break;
					cout << ",";
				}
			}
			cout << "]" << "\n";
		}
	}
	return 0;
}
//reverse를 할 때 deque 내장 함수의 reverse함수를 사용하면 시간초과(O(n))-> t : 최대 100 * p 최대 100000 * 배열 원소 개수 최대 100000개 
//r이 나왔을 때 뒤집어져 있다는 플래그 세우고 뒤집어져 있으면 pop_back 

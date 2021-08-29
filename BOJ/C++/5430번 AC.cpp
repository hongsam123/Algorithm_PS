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
				if (p[i] == 'R')		//R�϶� ���������� ǥ�� 
				{
					if (reverse == false)
						reverse = true;
					else reverse = false;
				}
				else					//D�϶� 
				{
					if (!dq.empty())	//�������� �ִ��� ���ο� ���� ���� 
					{
						if (reverse)
							dq.pop_back();
						else dq.pop_front();
					}
					else				//��������� ERROR 
					{
						error = true;
						break;
					}
				}
			}
		}
		else	//�迭�� ����ִ� ��� 
		{
			cin >> trash2;
			for (int i = 0; i < p.size(); i++)
				if (p[i] == 'D')	//D�� ������ error 
				{
					error = true;
					break;
				}
		}
		if (error)
			cout << "error" << '\n';
		else	//error�� �ƴҶ� ��� ��� 
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
			else	//�������� ���¸� �ݴ�� 
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
//reverse�� �� �� deque ���� �Լ��� reverse�Լ��� ����ϸ� �ð��ʰ�(O(n))-> t : �ִ� 100 * p �ִ� 100000 * �迭 ���� ���� �ִ� 100000�� 
//r�� ������ �� �������� �ִٴ� �÷��� ����� �������� ������ pop_back 

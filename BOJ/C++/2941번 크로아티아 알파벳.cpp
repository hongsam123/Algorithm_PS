#include<iostream>
using namespace std;

string dic[8] = { "c=","c-","dz=","d-","lj","nj","s=","z=" };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str;
	cin >> str;
	
	for (int i = 0; i < 8; i++)
	{
		while (1)
		{
			bool change = false;
			int idx = str.find(dic[i]);
			if (idx != string::npos)
			{
				str.replace(idx, dic[i].size(), "a");
				if (!change) change = true;
			}
			if (!change) break;
		}
	}

	cout <<str.size();

	return 0;
}

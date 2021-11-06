#include<iostream>
#include<deque>
#include<string>
using namespace std;

int n, k;
string str;
deque<char> dq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k >> str;

	int cnt = 0;
	for (int i = 0; i < str.size(); i++) {
		char ch = str[i];

		if (dq.empty())
			dq.push_back(ch);
		else {
			while (1)
			{
				int x = dq.back();
				if (x < ch) {
					dq.pop_back();
					cnt++;
					if (dq.empty() || cnt==k) {
						dq.push_back(ch);
						break;
					}
				}
				else {
					dq.push_back(ch);
					break;
				}
			}
		}

		if (cnt == k && i!=str.size()-1) {
			for (int j = i + 1; j < str.size(); j++) {
				dq.push_back(str[j]);
			}
			break;
		}
	}

	string answer = "";
	cnt = 0;
	for (char e : dq) {
		answer += e;
		cnt++;
		if (cnt == str.size() - k) break;
	}

	cout << answer;

	return 0;
}

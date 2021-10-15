#include<iostream>
#include<string>
using namespace std;

int t, n;
char op[3] = { ' ','+','-' };
string str;

bool check() {
	int sum = 0;
	char tmp_op = 0;
	string tmp = "";

	for (int i = 0; i < str.size(); i++) {
		char ch = str[i];
		if (ch >= '1' && ch <= '9') {
			//¼ýÀÚ
			tmp += ch;
		}
		else if (ch == '+') {
			if (tmp_op == 0 || tmp_op == '+')
				sum += stoi(tmp);
			else sum -= stoi(tmp);
			tmp = "";
			tmp_op = '+';
		}
		else if (ch == '-') {
			if (tmp_op == 0 || tmp_op == '+')
				sum += stoi(tmp);
			else sum -= stoi(tmp);
			tmp = "";
			tmp_op = '-';
		}
		else {
			continue;
		}
	}

	if (tmp_op == '+')
		sum += stoi(tmp);
	else sum -= stoi(tmp);

	if (sum == 0) return true;
	else return false;
}

void func(int num) {
	str += (num + 1) + '0';
	if (num == n-1) {
		if (check()) {
			cout << str << "\n";
		}
		return;
	}

	for (int i = 0; i <3; i++) {
		str += op[i];
		func(num + 1);
		str.pop_back();
		str.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	while (t--) {
		str = "";
		cin >> n;

		func(0);

		cout << "\n";
	}

	return 0;
}

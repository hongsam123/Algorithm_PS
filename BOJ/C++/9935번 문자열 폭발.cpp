#include<iostream>
using namespace std;

string str;
string str_bang;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> str >> str_bang;

	string tmp = "";

	for (int i = 0; i < str.size(); i++) {
		char ch = str[i];
		tmp += ch;
		if (ch == str_bang.back()) {
			//���� ���ڿ��� ������ ���ڰ� ���� ���� ���ڿ� ���ٸ�
			bool isSame = true;
			int tmp_k = tmp.size()-1;
			for (int j = str_bang.size() - 1; j >= 0; j--) {
				if (str_bang[j] != tmp[tmp_k--]) {
					isSame = false;
					break;
				}
			}
			//�������� ����� ���ڿ��� ���� ���ڿ� ������ŭ ���ڰ� ������ Ȯ��

			if (isSame) {
				//���ٸ� ���� ���ڿ� ���̸�ŭ pop_back
				for (int j = 0; j < str_bang.size(); j++) {
					tmp.pop_back();
				}
			}
		}
	}

	if (tmp == "")
		cout << "FRULA";
	else cout << tmp;

	return 0;
}

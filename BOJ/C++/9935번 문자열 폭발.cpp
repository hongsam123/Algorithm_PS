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
			//폭발 문자열의 마지막 글자가 현재 보는 글자와 같다면
			bool isSame = true;
			int tmp_k = tmp.size()-1;
			for (int j = str_bang.size() - 1; j >= 0; j--) {
				if (str_bang[j] != tmp[tmp_k--]) {
					isSame = false;
					break;
				}
			}
			//마지막에 저장된 문자열이 폭발 문자열 갯수만큼 글자가 같은지 확인

			if (isSame) {
				//같다면 폭발 문자열 길이만큼 pop_back
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

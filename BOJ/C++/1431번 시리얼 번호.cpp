#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n;

bool comp(const string& a, const string& b)
//함수의 인자로 stl이나 구조체 객체를 실어서 보내면 일어나는 값의 복사때문에
//그냥 string a, string b로 보내는 것은 바람직 하지 않다(불필요한 연산 발생)
//그러므로 위와 같이 reference를 보내는것이 바람직
{
	if (a.length() != b.length()) return a.length() < b.length();
	//길이가 다를때 처리

	int asum = 0;
	int bsum = 0;
	for (int i = 0; i < a.length(); i++)
		if (0 <= a[i] - '0' && a[i] - '0' <= 9)
			asum += a[i] - '0';
	for (int i = 0; i < b.length(); i++)
		if (0 <= b[i] - '0' && b[i] - '0' <= 9)
			bsum += b[i] - '0';
	if (asum != bsum) return asum < bsum;
	//같은 길이일때, 각 자리수 중 숫자인 것만 더해 그 크기순으로 처리

	int idx = 0;
	while (1)
	{
		if (idx == a.length()) break;
		if (a[idx] != b[idx]) break;
		idx++;
	}
	if (idx == a.length()) return false;
	else return a[idx] < b[idx];
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	vector<string> v;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		v.push_back(str);
	}

	sort(v.begin(), v.end(),comp);

	for (int i = 0; i < n; i++)
	{
		cout << v[i] << "\n";
	}

	return 0;
}


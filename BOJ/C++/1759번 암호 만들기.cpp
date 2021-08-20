#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int l, c;
vector<char> v;
string str;
bool isused[17];

int isOk()
{
	int vowel = 0;
	int consonant = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' ||
			str[i] == 'o' || str[i] == 'u')
			vowel++;
		else
			consonant++;
	}

	if (vowel >= 1 && consonant >= 2) return 1;
	else return 0;
}

void func(int n, int cur)
{
	if (n == l)
	{
		if (isOk())
		{
			cout << str << "\n";
		}
		return;
	}

	for (int i = cur; i < v.size(); i++)
	{
		if (isused[i]) continue;
		isused[i] = true;
		str += v[i];
		func(n + 1, i + 1);

		str.pop_back();
		isused[i] = false;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> l >> c;

	for (int i = 0; i < c; i++)
	{
		char x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	func(0, 0);

	return 0;
}

#include<iostream>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str;
	cin >> str;
	
	int half_length = str.length() / 2;

	int left = 0;
	int right = 0;

	for (int i = 0; i < half_length; i++)
	{
		left += str[i] - '0';
	}
	for (int i = half_length; i < str.length(); i++)
	{
		right += str[i] - '0';
	}

	if (left == right)
		cout << "lucky";
	else
		cout << "ready";

	return 0;
}

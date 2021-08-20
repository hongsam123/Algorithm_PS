#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct info {
	string name;
	int korean;
	int english;
	int math;
};
vector<info> student;

bool comp(info& a, info& b)
{
	if (a.korean != b.korean) return a.korean > b.korean;
	if (a.english != b.english) return a.english < b.english;
	if (a.math != b.math) return a.math > b.math;
	return a.name < b.name;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string str;
		int a, b, c;
		cin >> str >> a >> b >> c;
		student.push_back({ str,a,b,c });
	}

	sort(student.begin(), student.end(), comp);

	for (int i = 0; i < n; i++)
	{
		cout << student[i].name << "\n";
	}

	return 0;
}

//팩토리얼은 dp를 사용해야함
//long long 을 사용해도 범위를 벗어나는 문제
//굉장히 큰 수에 대한 문자배열을 이용한 덧셈
//파스칼 삼각형 + string 으로 문자 배열 a,b를 뒤에서부터 더해가며 새로운 문자배열 result에 결과를 저장해 나간다
//위를 진행해가며 올림수 sum을 저장해 나간다
#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
string comb[102][102];

string bigNumAdd(string n1, string n2)
{
	long long sum = 0;
	string result;

	//맨 뒤에서부터 더하기 시작한다

	while (!n1.empty() || !n2.empty() || sum)
	{
		if (!n1.empty())
		{
			sum += n1.back() - '0';
			n1.pop_back();
		}
		if (!n2.empty())
		{
			sum += n2.back() - '0';
			n2.pop_back();
		}
		result.push_back((sum % 10) + '0');
		sum = sum / 10;
	}

	//result를 뒤집어주기
	reverse(result.begin(), result.end());

	return result;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		comb[i][0] = comb[i][i] = "1";
		for (int j = 1; j < i; j++)
		{
			comb[i][j] = bigNumAdd(comb[i - 1][j] , comb[i - 1][j - 1]);
		}
	}

	cout << comb[n][m];


	return 0;
}

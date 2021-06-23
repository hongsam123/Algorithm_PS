#include <string>
#include <vector>
#include<iostream>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int cnt = 0;
    int deleteZero = 0;

    while (s != "1")
    {
        int num = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '1')
            {
                num++;
            }
            else
            {
                deleteZero++;
            }
        }

        s = "";
        while (num != 0)
        {
            s += (num%2 ==0? "0" : "1");
            num /= 2;
        }

        cnt++;
    }

    answer.push_back(cnt);
    answer.push_back(deleteZero);

    return answer;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> v = solution("110010101001");

    for (int e : v)
        cout << e << " ";

    return 0;
}

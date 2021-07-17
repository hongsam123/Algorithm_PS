#include<string>
#include<vector>
#include<set>
#include<map>
#include<iostream>
using namespace std;

vector<string> intersec, uni;
map<string, int> m1, m2;

int solution(string str1, string str2) {
    int answer = 0;

    for (int i = 0; i < str1.size() - 1; i++)
    {
        string str = "";
        int pnt = i;
        for (int j = 0; j < 2; j++)
        {
            if ((str1[pnt] >= 'a' && str1[pnt] <= 'z') || (str1[pnt] >= 'A' && str1[pnt] <= 'Z'))
            {
                if (str1[pnt] >= 'A' && str1[pnt] <= 'Z')
                    str += str1[pnt++] - 'A' + 'a';
                else str += str1[pnt++];
            }

            else break;
        }
        if (str.size() == 2)
        {
            if (m1[str] >= 1) m1[str]++;
            else m1[str] = 1;
        }
    }

    for (int i = 0; i < str2.size() - 1; i++)
    {
        string str = "";
        int pnt = i;
        for (int j = 0; j < 2; j++)
        {
            if ((str2[pnt] >= 'a' && str2[pnt] <= 'z') || (str2[pnt] >= 'A' && str2[pnt] <= 'Z'))
            {
                if (str2[pnt] >= 'A' && str2[pnt] <= 'Z')
                    str += str2[pnt++] - 'A' + 'a';
                else str += str2[pnt++];
            }
            else break;
        }
        if (str.size() == 2)
        {
            if (m2[str] >= 1) m2[str]++;
            else m2[str] = 1;
        }
    }

    //둘다 공집합일 경우 예외처리
    if (m1.empty() && m2.empty())
        return 65536;

    //교집합 구하기
    for (auto s1 : m1)
    {
        string str = s1.first;
        int num1 = s1.second;
        int num2 = m2[str];
        int n = min(num1, num2);
        while (n--)
            intersec.push_back(str);
    }

    //합집합 구하기
    for (auto s1 : m1)
    {
        string str = s1.first;
        int num1 = s1.second;
        if (m2[str] >= 1)  //m2에도 있으면
        {
            int num2 = m2[str];
            int num = max(num1, num2);
            while (num--) uni.push_back(str);
        }
        else
            while (num1--) uni.push_back(str);
    }
    for (auto s2 : m2)
    {
        string str = s2.first;
        int num2 = s2.second;
        if (m1[str] >= 1) continue;
        while (num2--) uni.push_back(str);
    }

    double d = (double)intersec.size() / uni.size();
    answer = d * 65536;

    return answer;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //cout << solution("FRANCE", "french") << "\n";
    //cout << solution("handshake", "shake hand") << "\n";
    cout << solution("aa1+aa2", "AAAA12") << "\n";
    //cout << solution("E=M*C^2", "e=m*c^2") << "\n";

    return 0;
}

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<char> operate;
vector<char> oper_list = { '*','+','-' }; //앞 인덱스에서 부터 높은 우선순위를 갖는 연산자 우선순위
vector<long long> number;

long long calc(long long a, long long b, char op)
{
    if (op == '+')
        return a + b;
    else if (op == '-')
        return a - b;
    else
        return a * b;
}

long long solution(string expression) {
    long long answer = 0;

    string str;
    for (int i = 0; i < expression.size(); i++)
    {
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*')
        {
            operate.push_back(expression[i]);
            number.push_back(stoi(str.c_str()));
            str = "";
        }
        else
            str += expression[i];
    }
    number.push_back(stoi(str.c_str()));

    do {
        vector<char> tmp_oper = operate;
        vector<long long> tmp_num = number;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < tmp_oper.size(); j++)
            {
                if (oper_list[i] == tmp_oper[j])
                {
                    tmp_num[j] = calc(tmp_num[j], tmp_num[j + 1], oper_list[i]);
                    tmp_num.erase(tmp_num.begin() + j + 1);
                    tmp_oper.erase(tmp_oper.begin() + j);
                    j--;
                }
            }
        }

        if (tmp_num[0] < 0)
            answer = max(answer, tmp_num[0] * -1);
        else
            answer = max(answer, tmp_num[0]);
    } while (next_permutation(oper_list.begin(), oper_list.end()));
    //주의 : next_permutation은 모든 조합을 만들어 주는 것이 아님
    //현재의 수열이(현재 벡터/배열의 순서가) 사전순이라고 생각했을 때
    //다음 수열(순서)로 만든다. 예를 들어 현재 수열이 사전순으로 가장 마지막 수열이라면 false를 바로 return
    //모든 조합을 만들기 위해서는 수열이 사전순의 제일 처음으로 초기화 되어있어야한다(기본 사전순 : * > + > -)


    return answer;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << solution("100-200*300-500+20");
    //cout << solution("50*6-3*2");

    return 0;
}

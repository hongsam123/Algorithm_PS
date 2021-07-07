#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<char> operate;
vector<char> oper_list = { '*','+','-' }; //�� �ε������� ���� ���� �켱������ ���� ������ �켱����
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
    //���� : next_permutation�� ��� ������ ����� �ִ� ���� �ƴ�
    //������ ������(���� ����/�迭�� ������) �������̶�� �������� ��
    //���� ����(����)�� �����. ���� ��� ���� ������ ���������� ���� ������ �����̶�� false�� �ٷ� return
    //��� ������ ����� ���ؼ��� ������ �������� ���� ó������ �ʱ�ȭ �Ǿ��־���Ѵ�(�⺻ ������ : * > + > -)


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

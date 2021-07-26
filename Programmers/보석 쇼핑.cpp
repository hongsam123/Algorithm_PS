#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

map<string, int> m;  //<��������, ����>
map<string, int> tmp;

vector<int> solution(vector<string> gems) {
    vector<int> answer;

    int st = 0;
    int en = gems.size() - 1;

    //���� ���� count;
    for (int i = 0; i < gems.size(); i++)
    {
        string str = gems[i];
        if (m[str]) m[str]++;
        else m[str] = 1;
    }

    //�տ��� ���� �����
    tmp = m;
;    while (st != en)
    {
        string str = gems[st];
        if (tmp[str] > 1)
        {
            st++;
            tmp[str]--;
        }
        else
            break;
    }
    while (st != en)
    {
        string str = gems[en];
        if (tmp[str] > 1)
        {
            en--;
            tmp[str]--;
        }
        else
            break;
    }
    cout << st << " " << en << "\n";

    //st,en ���� �� ����
    int tmp_st = st;
    int tmp_en = en;
    st = 0;
    en = gems.size() - 1;

    //�ڿ��� ���� �����
    while (st != en)
    {
        string str = gems[en];
        if (m[str] > 1)
        {
            en--;
            m[str]--;
        }
        else
            break;
    }
    while (st != en)
    {
        string str = gems[st];
        if (m[str] > 1)
        {
            st++;
            m[str]--;
        }
        else
            break;
    }
    cout << st << " " << en << "\n";

    //��
    if (en - st > tmp_en - tmp_st)
    {
        en = tmp_en;
        st = tmp_st;
    }

    answer.push_back(st + 1);
    answer.push_back(en + 1);

    return answer;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> v = solution({ "A","B","B","B","B","B","B","C","B","A" });
    for (int e : v)
        cout << e << " ";

    return 0;
}

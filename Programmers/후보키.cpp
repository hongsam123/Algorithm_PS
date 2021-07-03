#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;

vector<vector<string>> r;   //relation
int row, col;
bool isused[10];
vector<int> key;            //�˻��� �ĺ�Ű
vector<vector<int>> subKey;    //������ �ĺ�Ű

bool isOnly()   //���ϼ� �˻� : �ش� �ĺ�Ű�� �����̼��� ��� Ʃ���� �����ϰ� �ĺ��Ǵ°�
{
    vector<string> v;

    for (int i = 0; i < row; i++)
    {
        string val;
        for (int j : key)
        {
            val += r[i][j];
        }
        for (auto e : v)
        {
            if (e == val)
                return false;
        }
        v.push_back(val);
    }

    return true;
}

bool isMini()   //�ּҼ� �˻�
{
    if (!subKey.empty())
    {
        for (int i = 0; i < subKey.size(); i++)
        {
            vector<int> k = subKey[i];
            
            if (includes(key.begin(), key.end(), k.begin(), k.end()))   //k�� key�� �κ������� �� �� �ִ°�
                return false;                                           //(includes �Լ� : ������ true return ((�� ���� �� ���ĵǾ��־�� ��)))
        }
    }
    return true;
}

void func(int n, int index, int k)  //��Ʈ��ŷ���� ������ �ĺ�Ű ����(��������)
{
    if (n == k)
    {
        if (isOnly())
            if (isMini())
                subKey.push_back(key);

        return;
    }

    for (int i = index; i < col; i++)
    {
        if (isused[i]) continue;
        isused[i] = 1;
        key.push_back(i);
        func(n + 1,i+1, k);

        isused[i] = 0;
        key.pop_back();
    }
    return;
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    r = relation;
    col = relation[0].size();
    row = relation.size();

    for (int i = 1; i <= col; i++)
        func(0,0,i);

    answer = subKey.size();
    return answer;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    
    //vector<vector<string>> rela = { {"100", "ryan", "music", "2"}, {"200", "apeach", "math", "2"}, {"300", "tube", "computer", "3"}, {"400", "con", "computer", "4"}, {"500", "muzi", "music", "3"}, {"600", "apeach", "music", "2"} };
    //�ּҼ� �ݷ�
    vector<vector<string>> rela = { {"a", "1", "aaa", "c", "ng"},{"b",  "1", "bbb", "c", "g"},{"c",  "1", "aaa", "d", "ng"}, {"d",  "2", "bbb", "d", "ng"}};
    cout << solution(rela);

    return 0;
}

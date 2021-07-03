#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;

vector<vector<string>> r;   //relation
int row, col;
bool isused[10];
vector<int> key;            //검사할 후보키
vector<vector<int>> subKey;    //가능한 후보키

bool isOnly()   //유일성 검사 : 해당 후보키로 릴레이션의 모든 튜플이 유일하게 식별되는가
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

bool isMini()   //최소성 검사
{
    if (!subKey.empty())
    {
        for (int i = 0; i < subKey.size(); i++)
        {
            vector<int> k = subKey[i];
            
            if (includes(key.begin(), key.end(), k.begin(), k.end()))   //k가 key의 부분집합이 될 수 있는가
                return false;                                           //(includes 함수 : 있으면 true return ((두 집합 다 정렬되어있어야 함)))
        }
    }
    return true;
}

void func(int n, int index, int k)  //백트래킹으로 가능한 후보키 조합(개수별로)
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
    //최소성 반례
    vector<vector<string>> rela = { {"a", "1", "aaa", "c", "ng"},{"b",  "1", "bbb", "c", "g"},{"c",  "1", "aaa", "d", "ng"}, {"d",  "2", "bbb", "d", "ng"}};
    cout << solution(rela);

    return 0;
}

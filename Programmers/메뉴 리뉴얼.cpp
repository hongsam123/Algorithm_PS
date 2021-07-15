#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;

vector<string> order;
map<string, int> m;     //각 길이당 조합과 나온 횟수
string str;
int max_cnt;

int check(int n)    //str이 중복되는 메뉴인지 확인 : 이 후 메뉴의 부분집합이 몇 번 되는지
{
    int cnt = 0;
    for (int i = n + 1; i < order.size(); i++)
        if (includes(order[i].begin(), order[i].end(), str.begin(), str.end()))
            cnt++;

    return cnt;
}

void func(int x, int k, int n, int s)
{
    if (n == s)
    {
        int num = check(x);
        if (num == 0) return;   //중복이 안됨
        if (m[str] >= num) return; //이미 등록

        max_cnt = max(max_cnt, num);
        m[str] = num;
        return;
    }

    for (int j = k; j < order[x].size(); j++)
    {
        str += order[x][j];
        func(x, j + 1, n + 1, s);
        str.pop_back();
    }

}


vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for (int i = 0; i < orders.size(); i++)
        sort(orders[i].begin(), orders[i].end());

    order = orders;

    for (int i = 0; i < course.size(); i++)
    {
        int size = course[i];
        max_cnt = 0;
        for (int j = 0; j < orders.size(); j++)
            func(j, 0, 0, size);

        for (auto e : m)
            if (e.second == max_cnt)
                answer.push_back(e.first);

        m.clear();
    }

    sort(answer.begin(), answer.end());

    return answer;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<string> v = solution({ "ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH" }, { 2,3,4 });
    for (auto e : v)
        cout << e << " ";

    return 0;
}


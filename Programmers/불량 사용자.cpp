#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

vector<string> id_list[10];
map<string, int> m;
int n;
vector<vector<string>> ans;

void func(int x, int k)
{
    if (k == n)
    {
        vector<string> v;
        for (auto str : m)
        {
            if (str.second == 1)
                v.push_back(str.first);
        }

        sort(v.begin(), v.end());

        bool isin = false;
        for (auto a : ans)
            if (a == v) isin = true;
    
        if (!isin)
            ans.push_back(v);
      
        return;
    }

     for (auto id : id_list[x])
     {
        if (m[id]) continue;
        m[id] = 1;
        func(x + 1, k + 1);
        m[id] = 0;
     }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;

    n = banned_id.size();
    for (int i = 0; i < n; i++)
    {
        string ban_id = banned_id[i];

        //매칭되는 id list 저장
        for (int j = 0; j < user_id.size(); j++)
        {
            string uid = user_id[j];

            //길이가 안맞으면 continue;
            if (uid.size() != ban_id.size()) continue;

            bool posi = true;
            for (int k = 0; k < uid.size(); k++)
            {
                if (ban_id[k] == '*') continue;
                if (uid[k] != ban_id[k])
                {
                    posi = false;
                    break;
                }
            }
            if (posi)
            {
                id_list[i].push_back(uid);
            }
        }
    }

    //백트래킹으로 경우의 수
    func(0, 0);
    answer = ans.size();

    return answer;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << solution({ "frodo", "fradi", "crodo", "abc123", "frodoc" }, { "fr*d*", "abc1**" }) << "\n";
    //cout << solution({ "frodo", "fradi", "crodo", "abc123", "frodoc" }, { "*rodo", "*rodo", "******" });

    return 0;
}

#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include<iostream>

using namespace std;

bool comp(pair<double,int> x,pair<double,int> y)
{
    if(x.first!=y.first)
        return x.first>y.first;
    return x.second<y.second;
}

vector<int> solution(int n, vector<int> stages) {
    vector<int> answer;
    vector<pair<double,int>> stage_fail;   //<실패율, 스테이지 번호>
    
    for(int stage = 1 ; stage<=n ; stage++)
    {
        int total_user = 0;
        int fail_user = 0;
        for(int i=0;i<stages.size();i++)
        {
            if(stages[i]>=stage)
                total_user++;
            if(stages[i]==stage)
                fail_user++;
        }
        if(total_user==0)
        {
            stage_fail.push_back({0,stage});
            continue;
        }
        double fail = (double)fail_user/total_user;
        stage_fail.push_back({fail, stage});
    }
    
    sort(stage_fail.begin(),stage_fail.end(),comp);
    
    for(int i=0;i<n;i++)
        answer.push_back(stage_fail[i].second);
    
    return answer;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	vector<int> stage = {2, 1, 2, 6, 2, 4, 3, 3};
	vector<int> answer = solution(5,stage);
	for(int e : answer)
		cout<<e<<" ";
	
	return 0;
 } 

#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>
using namespace std;

int arr[100003];

vector<int> solution(string s) {
    vector<int> answer;
    
    string tmp = "";
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='{') continue;
        
        if(s[i]>='0' && s[i]<='9')
        {
            tmp += s[i];
            continue;
        }
        
        int x = 0;
        if(s[i] ==',' || s[i]=='}')
        {
            int num = 1;
            for(int j=tmp.size()-1;j>=0;j--)
            {
                x += (tmp[j]-'0') * num;
                num *= 10;
            }
            tmp = "";
        }
        arr[x]++;
    }
    
    vector<pair<int,int>> v;    //<num,count>
    for(int i=1;i<=100000;i++)
    {
        if(arr[i])
            v.push_back({arr[i],i});
    }
    sort(v.rbegin(),v.rend());
    
    for(pair<int,int> cur : v)
        answer.push_back(cur.second);
    
    return answer;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	vector<int> v1,v2,v3;
	v1 = solution("{{2},{2,1},{2,1,3},{2,1,3,4}}");
	for(int e : v1)
		cout<<e<<" ";
	cout<<"\n";
	
	fill(arr,arr+100002,0);
	v2 = solution("{{20,111},{111}}");
	for(int e : v2)
		cout<<e<<" ";
	cout<<"\n";
	
	fill(arr,arr+100002,0);
	v3 = solution("{{123}}");
	for(int e : v3)
		cout<<e<<" ";
	cout<<"\n";
	
	return 0;
}

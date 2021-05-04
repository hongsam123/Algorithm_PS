#include <string>
#include <vector>
#include <sstream>		//���ڿ� ��Ʈ�� 
#include <map>			//<key,value>������ ���� 
#include <iostream>
#include <utility>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string,string> nick;             //<id,nickname>
    vector<pair<string,string>> tmp;     //<id,���ڿ�>
    string str;
    
    for(int i=0;i<record.size();i++)
    {
        stringstream ss;
        ss.str(record[i]);
        ss>>str;
        
        if(str=="Enter")
        {
            string id;
            string nickname;
            ss >> id >> nickname;
            nick[id] = nickname;
            tmp.push_back({id,"���� ���Խ��ϴ�."});
        }
        else if(str=="Leave")
        {
            string id;
            ss>>id;
            tmp.push_back({id,"���� �������ϴ�."});
        }
        else
        {
            string id, nickname;
            ss>>id>>nickname;
            nick[id] = nickname;
        }
    }
    
    for(int i=0;i<tmp.size();i++)
        answer.push_back({nick[tmp[i].first]+tmp[i].second});
    
    return answer;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	vector<string> v = {"Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"};
	vector<string> s;
	s = solution(v);
	for(string e : s)
		cout<<e<<"\n";
	
	return 0;
}

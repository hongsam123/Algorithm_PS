#include <string>
#include <vector>
#include <sstream>
#include <stack>
#include <set>
#include <iostream>
using namespace std;

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    vector<int> erased;
    set<int> s;
    
    for(int i=0;i<n;i++)
        s.insert(i);
    
    auto it = s.find(k);
    
    for(int i=0;i<cmd.size();i++)
    {
        stringstream ss;
        ss.str(cmd[i]);
        
        char op;
        int num;
        ss>>op;
        
        if(op=='U')
        {
            ss >> num;
            for(int j=0;j<num;j++)
                it--;
        }
        else if(op=='D')
        {
            ss >> num;
            for(int j=0;j<num;j++)
                it++;
        }
        else if(op=='C')
        {
            erased.push_back(*it);
            it = s.erase(it);
            if(it==s.end()) it--;
        }
        else
        {
            s.insert(erased.back());
            erased.pop_back();
        }
    }
    
    string str(n,'X');
    for(auto e : s)
        str[e] = 'O';
    
    answer = str;
    
    return answer;
}

int main()
{
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cout<<solution(8,2,{"D 2","C","U 3","C","D 4","C","U 2","Z","Z"})<<"\n";
	cout<<solution(8,2,{"D 2","C","U 3","C","D 4","C","U 2","Z","Z","U 1","C"})<<"\n";
	
	return 0;
}

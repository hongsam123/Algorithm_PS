#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

map<string, vector<int>> m; // <������ ���� �� �ִ� ����� ��, ���� ����>
string infoArr[4][2] = {{"-"},{"-"},{"-"},{"-"}};

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    int num = info.size();
    
    //������ ���� �Է�
    for(int i=0;i<num;i++)
    {
        stringstream ss;
        ss.str(info[i]);
        int s = 0;
        
        ss>>infoArr[0][1]>>infoArr[1][1]>>infoArr[2][1]>>infoArr[3][1]>>s;
        
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                for(int k=0;k<2;k++)
                    for(int l=0;l<2;l++)
                    {
                        string str = infoArr[0][i] + infoArr[1][j] + infoArr[2][k] + infoArr[3][l];
                        m[str].push_back(s);
                    }
    }
    
    //map�� ���� ���� ����(���� ����)
    for(auto& cur : m)
        sort(cur.second.begin(),cur.second.end());
    
    //���� ó��
    for(int i=0;i<query.size();i++)
    {
        //����
        stringstream ss;
        ss.str(query[i]);
        string l,j,c,f,tmp = "";
        int s = 0;
        
        ss>>l>>tmp>>j>>tmp>>c>>tmp>>f>>s;
        string str = l+j+c+f;
        
        vector<int> scores = m[str];
        
        //����Ž������ �˻� 
        answer.push_back(scores.end() - lower_bound(scores.begin(),scores.end(),s));
    }
    
    return answer;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	vector<int> v = solution({"java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"},
	{"java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"});
	
	for(int e:v)
		cout<<e<<" "; 
	
	
	return 0;
 } 

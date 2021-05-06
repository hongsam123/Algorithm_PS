#include <string>
#include <iostream>
using namespace std;

bool isright(string s)
{
    int cnt = 0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='(')
            cnt++;
        else
            cnt--;
        
        if(cnt<0) return false;
    }
    return true;
}

string solution(string p) {
  
    if(p.empty()) return "";    //1
    
    string u = "";
    string v = "";
    int cnt = 0;
    for(int i=0;i<p.size();i++)     //2
    {
        if(p[i]=='(')
            cnt++;
        else
            cnt--;
        
        if(cnt==0)  //���� �� �� ���� ���ڿ��� �������� ��ȣ ���ڿ�
        {
            u = p.substr(0,i+1);    //p[0]~p[i]���� ���ڿ�
            //s.substr(i,n) s���ڿ��� i��° ���� n���� �κ� ���ڿ��� ����
            v = p.substr(i+1);      //p[i+1]~������ ���ڿ�
            break;
        }
    }
    if(isright(u))  //3
        return u+solution(v);
    
    string tmp = "(";   //4-1
    tmp += solution(v); //4-2
    tmp += ')';         //4-3
    
    for(int i=1;i<u.size()-1;i++)   //4-4
    {
        if(u[i]=='(')
            tmp += ')';
        else
            tmp += '(';
    }
    
    return tmp;         //4-5
}

int main()
{
	cout<<solution("(()())()")<<"\n";
	cout<<solution(")(")<<"\n";
	cout<<solution("()))((()"	)<<"\n";
	
	return 0;
}

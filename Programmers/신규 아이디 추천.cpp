#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string new_id) {
    string answer = "";
    
    if(new_id.size()>=1)    //아이디가 빈 문자열이 아니라면
    {
        for(int i=0;i<new_id.size();i++)    //1단계
        {
            if(new_id[i]>='A' && new_id[i]<='Z')    //문자가 대문자라면
                new_id[i] = new_id[i]-'A'+'a';      //소문자로 변경
        }
        
        string tmp = "";
        for(int i=0;i<new_id.size();i++)    //2단계
        {
            if((new_id[i]>='a' && new_id[i]<='z') || (new_id[i]>='0' && new_id[i]<='9') 
               || new_id[i]=='-' ||new_id[i]=='_' || new_id[i]=='.')
            {
                tmp += new_id[i];
            }
        }
        new_id = tmp;
        
        bool isuse = false;
        tmp = "";
        for(int i=0;i<new_id.size();i++)    //3단계
        {
            if(new_id[i]=='.' && isuse==false)
                isuse = true;
            if(new_id[i]!='.')
            {
                if(isuse)
                {
                    isuse = false;
                    tmp += '.';
                }
                tmp += new_id[i];
            }
        }
        new_id = tmp;
        
        tmp = "";
        for(int i=0;i<new_id.size();i++)    //4단계
        {
            if(i==0 && new_id[i]=='.')
                continue;
            if(i==new_id.size()-1 && new_id[i]=='.')
                continue;
            tmp += new_id[i];
        }
        new_id = tmp;
    }
    
    if(new_id.size()==0)   //5단계
        new_id += 'a';
    
    
    if(new_id.size()>=16)   //6단계
    {
        string tmp = "";
        for(int i=0;i<15;i++)
        {
            tmp += new_id[i];
        }
        
        if(tmp[14]=='.')
        {
            new_id = "";
            for(int i=0;i<14;i++)
                new_id += tmp[i];
        }
        else
            new_id = tmp;
    }
    
    while(new_id.size()<=2)     //7단계
    {
        new_id += new_id[new_id.size()-1];
    }
    
    answer = new_id;
    
    return answer;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cout<<solution("...!@BaT#*..y.abcdefghijklm")<<"\n";
	cout<<solution("z-+.^.")<<"\n";
	cout<<solution("=.=")<<"\n";
	cout<<solution("123_.def")<<"\n";
	cout<<solution("abcdefghijklmn.p")<<"\n";
	
	return 0;
}

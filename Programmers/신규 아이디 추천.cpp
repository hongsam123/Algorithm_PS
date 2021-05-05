#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string new_id) {
    string answer = "";
    
    if(new_id.size()>=1)    //���̵� �� ���ڿ��� �ƴ϶��
    {
        for(int i=0;i<new_id.size();i++)    //1�ܰ�
        {
            if(new_id[i]>='A' && new_id[i]<='Z')    //���ڰ� �빮�ڶ��
                new_id[i] = new_id[i]-'A'+'a';      //�ҹ��ڷ� ����
        }
        
        string tmp = "";
        for(int i=0;i<new_id.size();i++)    //2�ܰ�
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
        for(int i=0;i<new_id.size();i++)    //3�ܰ�
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
        for(int i=0;i<new_id.size();i++)    //4�ܰ�
        {
            if(i==0 && new_id[i]=='.')
                continue;
            if(i==new_id.size()-1 && new_id[i]=='.')
                continue;
            tmp += new_id[i];
        }
        new_id = tmp;
    }
    
    if(new_id.size()==0)   //5�ܰ�
        new_id += 'a';
    
    
    if(new_id.size()>=16)   //6�ܰ�
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
    
    while(new_id.size()<=2)     //7�ܰ�
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

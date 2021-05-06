#include<iostream>
//#include<string>
#include<algorithm>
using namespace std;
int main(void)
{
	string tmp1,tmp2;
	cin>>tmp1>>tmp2;
	
	string str1,str2;
	str1 = '0'+tmp1;
	str2 = '0'+tmp2;
	
	int len1,len2;
	len1 = str1.size();
	len2 = str2.size();
	
	int c[len1+1][len2+1]={0};
	
	for(int i=1;i<=len1;i++)
	{
		for(int j=1;j<=len2;j++)
		{
			if(str1[i]==str2[j])
			{
				c[i][j] = c[i-1][j-1]+1;
			}
			else
			{
				c[i][j] = max(c[i-1][j],c[i][j-1]);
			}
		}
	}
	
	cout<<c[len1][len2]-1;
	
	return 0;
		
}

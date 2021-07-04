#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n) {
    int answer = 0;
    
    long long x = 1;
    long long num = 0;
    while(n!=0)
    {
        num += (n%3) * x;
        n /= 3;
        x *= 10;
    }
    
    string str;
    while(num!=0)
    {
        str += (num%10) + '0';
        num /= 10;
    }
    
    long long y = 1;
    for(long long i=str.size()-1;i>=0;i--)
    {
        answer += y * (str[i]-'0');
        y*=3;
    }
    
    return answer;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cout<<solution(45)<<"\n";
	cout<<solution(125)<<"\n"; 
	
	return 0;
}

#include <string>
#include <vector>
#include<string>
#include<bitset>
#include <iostream>
using namespace std;


vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;

    for(long long i=0;i<numbers.size();i++)
    {
        long long num = numbers[i];
        bitset<52> bb = num;
        string str = bb.to_string();

        bool one_is = false;
        for(int j=str.size()-1;j>=0;j--)
        {
            if(one_is==false && str[j]=='0')
            {
                str[j] = '1';
                break;
            }
            if(one_is==true && str[j]=='0')
            {
                str[j] = '1';
                str[j+1] = '0';
                break;
            }
            if(str[j]=='1' && one_is==false)
                one_is = true;
        }
        long long x = 1;
        long long ans = 0;
        for(int j=str.size()-1;j>=0;j--)
        {
            if(str[j]=='1')
                ans += x;
            x *= 2;
        }
        answer.push_back(ans);
    }

    return answer;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	vector<long long> n = {2,7};
	n = solution(n);
	
	for(auto e : n)
		cout<<e<<" ";
	
	return 0;
 } 

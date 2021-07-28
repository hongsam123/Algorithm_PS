#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> stones, int k) {
    int start = 1;
    int end = *max_element(stones.begin(),stones.end());
    
    while(start<=end)
    {
        int mid = (start+end)/2;
        int cnt = 0;
        bool posi = false;
        for(int i=0;i<stones.size();i++)
        {
            if(stones[i]<=mid)
            {
                cnt++;
                if(cnt>=k)
                {
                    posi = true;
                    break;
                }
            }
            else
                cnt = 0;
        }
        
        if(posi)
            end = mid-1;
        else
            start = mid+1;
    }
    
    return start;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cout<<solution({2, 4, 5, 3, 2, 1, 4, 2, 5, 1},3);
	
	return 0;
}

#include <string>
#include <vector>
#include <iostream>
using namespace std;

int board[1026][1026];
int n;
int one,zero;

void func(int x,int y,int num)
{
    if(num==1)
    {
        if(board[x][y])
            one++;
        else
            zero++;
        return;
    }
    
    int pre = -1;
    bool posi = true;
    for(int i=x;i<x+num;i++)
    {
        for(int j=y;j<y+num;j++)
        {
            if(pre==-1)
                pre = board[i][j];
            else
            {
                if(pre != board[i][j])
                    posi = false;
            }
            pre = board[i][j];
        }
    }
    
    if(posi)
    {
        if(pre)
            one++;
        else
            zero++;
        return;
    }
    
    func(x,y,num/2);
    func(x+num/2,y,num/2);
    func(x,y+num/2,num/2);
    func(x+num/2,y+num/2,num/2);
    
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    
    n = arr[0].size();
    
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            board[i][j] = arr[i][j];
    
    func(0,0,n);
    
    answer.push_back(zero);
    answer.push_back(one);
    
    return answer;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	vector<int> vec = solution({{1,1,0,0},{1,0,0,0},{1,0,0,1},{1,1,1,1}});
	
	for(int e : vec) 
	cout<<e<<" ";
	
	return 0;
 } 

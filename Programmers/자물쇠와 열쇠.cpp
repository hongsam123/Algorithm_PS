#include <string>
#include <vector>
#include <iostream> 
using namespace std;

void rotate(vector<vector<int>> &key){	//key 90도 회전 함수 
    vector<vector<int>> tmp(key.size(),vector<int>(key.size()));
    
    for(int i=0;i<key.size();i++)
        for(int j=0;j<key.size();j++)
            tmp[j][key.size()-1-i] = key[i][j];
    
    key = tmp;
    return;
}

bool check(int x,int y,vector<vector<int>> key,vector<vector<int>> board){	//키와 자물쇠가 맞는지 확인 
    for(int i=0;i<key.size();i++)
    {
        for(int j=0;j<key.size();j++)
            board[x+i][y+j] += key[i][j];
    }
    
    for(int i=key.size()-1;i<=board.size()-key.size();i++)
    {
        for(int j=key.size()-1;j<=board.size()-key.size();j++)
            if(board[i][j]!=1) return false;
    }
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    
    int m = key[0].size();
    int n = lock[0].size();
    int backsize = 2*m + n - 2;
    
    vector<vector<int>> background(backsize,vector<int>(backsize,0));
    
    for(int i=0;i<n;i++)	//자물쇠를 맵 한가운데 배치 
    {
        for(int j=0;j<n;j++)
            background[i+m-1][j+m-1] = lock[i][j];
    }
    
    for(int round = 0;round<4;round++)	//키를 돌려가며 맞는지 확인 
    {
        for(int i=0;i<=backsize-m;i++)
            for(int j=0;j<=backsize-m;j++)
                if(check(i,j,key,background))
                {
                    answer = true;
                    return answer;
                }
        rotate(key);
    }
    
    return answer;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	vector<vector<int>> k = {{0,0,0},{1,0,0},{0,1,1}};
	vector<vector<int>> l = {{1,1,1},{1,1,0},{1,0,1}};
	cout<<solution(k,l);
	
	return 0;
 } 

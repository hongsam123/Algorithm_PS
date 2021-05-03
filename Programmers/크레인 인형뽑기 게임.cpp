#include <string>
#include <vector>
#include<iostream>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    vector<int> ans;
    int answer = 0;

    for(int i=0;i<moves.size();i++)
    {
        int x = 0;
        int y = moves[i] - 1;
        int doll=0;
        
        while(1)
        {
            if(x>=board.size()) 
			//해당 열에 인형이 없는 경우 doll은 0으로 유지된채 while문 탈출
                break;
            
            if(board[x][y])
            {
                doll = board[x][y];
                board[x][y] = 0;
                break;
            }
            x++;
        }
    
        if(doll)    //인형이 뽑힌 경우
        {
            if(!ans.empty())
            {
                if(doll==ans.back())
                {
                    ans.pop_back();
                    answer += 2;
                }
                else
                    ans.push_back(doll);
            }
            else
                ans.push_back(doll);
        }
	}
    return answer;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	vector<vector<int>> b = {{0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1}};
	vector<int> m = {1,5,3,5,1,2,1,4};
	cout<<solution(b,m);
	
	return 0;
}

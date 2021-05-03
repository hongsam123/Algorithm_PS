#include <string>
#include <vector>
#include<iostream>
using namespace std;

int button_position[13][3] = {{3,1},{0,0},{0,1},{0,2},{1,0},{1,1},{1,2},{2,0},{2,1},{2,2},{3,0},{3,2}};

int getDist(int x,int y)
{
    int a = abs(button_position[x][0] - button_position[y][0]);
    int b = abs(button_position[x][1] - button_position[y][1]);

    return a+b;
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int left = 10;
    int right = 11;
    
    for(int i=0;i<numbers.size();i++)
    {
        int n = numbers[i];
        
        if(n==1 || n==4 || n==7)
        {
            answer += 'L';
            left = n;
        }
        else if(n==3 || n==6 ||n==9)
        {
            answer += 'R';
            right = n;
        }
        else
        {
            int r_dist = getDist(n,right);
            int l_dist = getDist(n,left);
            if(r_dist==l_dist)
            {
                if(hand=="right")
                {
                    answer += 'R';
                    right = n;
                }
                else
                {
                    answer += 'L';
                    left = n;
                }
            }
            else if(r_dist<l_dist)
            {
                answer += 'R';
                right = n;
            }
            else
            {
                answer += 'L';
                left = n;
            }
        }
    }
    
    return answer;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	vector<int> v1 = {1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5};
	cout<<solution(v1,"right")<<"\n";
	vector<int> v2 = {7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2};
	cout<<solution(v2,"left")<<"\n";
	
	return 0;
}

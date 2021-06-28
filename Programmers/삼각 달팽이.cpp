#include <string>
#include <vector>
#include <iostream> 
using namespace std;

int num;
int number = 1;
int board[1002][1002];


bool canWrite(int x, int y)
//범위를 벗어나거나 수가 쓰여있다면(0이 아니라면) false
{
    if (x < 0 || x >= num || y < 0 || y > x) return false;
    if (board[x][y]) return false;

    return true;
}

vector<int> solution(int n) {
    vector<int> answer;

    num = n;
    int end = n * (n + 1) / 2;    //쓸수 있는 최대 숫자

    string order = "down";

    int x = 0;
    int y = 0;

    while (number <= end)
    {
        if (order == "down")
        {
            while (canWrite(x, y))
            {
                board[x][y] = number;
                number++;
                x++;
            }
            x--; y++;
            order = "right";
        }
        else if (order == "right")
        {
            while (canWrite(x, y))
            {
                board[x][y] = number;
                number++;
                y++;
            }
            y--;
            x--; y--;
            order = "up";
        }
        else
        {
            while (canWrite(x, y))
            {
                board[x][y] = number;
                number++;
                x--; y--;
            }
            x++; y++;
            x++;
            order = "down";
        }
    }


    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
            answer.push_back(board[i][j]);

    return answer;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> v = solution(6);

    for (int e : v)
        cout << e << " ";

    return 0;
}

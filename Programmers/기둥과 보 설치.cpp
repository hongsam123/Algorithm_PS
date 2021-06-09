#include <string>
#include <vector>
#include<iostream>
using namespace std;

bool board[102][102][2];//0은 기둥  1은 보
//처음에 2차원 배열로 0은 아무것도 없음, 1은 기둥, 2는 보, 3은 기둥&보로 풀었다가 너무 고려해야할 경우가 많아 헤맸다..
int boardsize;

bool checkCoverage(int x, int y)
{
    if (x<0 || y<0 || x>boardsize || y>boardsize)
        return false;
    return true;
}

bool isSetPossible(int x,int y,int type)
{
    if (type == 0) //기둥을 설치할 때
    {
        if (y == 0) return true;    //바닥 위에 있으면 가능

        //보의 한쪽 끝 부분 위에 있으면 가능
        if ((checkCoverage(x - 1, y) && board[x - 1][y][1]) || board[x][y][1]) return true;
        
        //다른 기둥 위에 있으면 가능
        if (checkCoverage(x, y - 1) && board[x][y - 1][0]) return true;
    }
    else
        //보를 설치할 때
    {
        //한쪽 끝부분이 기둥 위에 있거나
        if ((checkCoverage(x, y - 1) && board[x][y - 1][0]) || (checkCoverage(x + 1, y - 1) && board[x + 1][y - 1][0]))
            return true;

        //양쪽 끝 부분이 다른 보와 동시에 연결되어 있어야 한다
        if((checkCoverage(x-1,y)&&checkCoverage(x+1,y)) && board[x-1][y][1] &&board[x+1][y][1])
            return true;
    }
    return false;
}

bool isRemovePossible() //전수조사(크기가 작아 효율성 고민을 할 필요 없다
{
    for (int x = 0; x < boardsize; x++)
    {
        for (int y = 0; y < boardsize; y++)
        {
            for (int type = 0; type < 2; type++)
            {
                if (board[x][y][type])   //기둥 또는 보가 있을 때
                {
                    board[x][y][type] = 0;  //삭제했다가
                    if (!isSetPossible(x, y, type)) //다시 설치할 경우 문제가 없는지확인
                    {
                        board[x][y][type] = 1;
                        return false;
                    }
                    board[x][y][type] = 1;
                }
            }
        }
    }
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    boardsize = n;

    for (int i = 0; i < build_frame.size(); i++)
    {
        int x = build_frame[i][0];  //x좌표
        int y = build_frame[i][1];  //y좌표
        int a = build_frame[i][2];  //0이면 기둥, 1이면 보
        int b = build_frame[i][3];  //0이면 삭제, 1이면 설치

        if (b)   //설치
        {
            if (a == 0)    //기둥 설치
            {
                if (isSetPossible(x, y, 0))
                {
                    board[x][y][0] = 1;
                }
            }

            else    //보 설치
            {
                if (isSetPossible(x, y, 1))
                {
                    board[x][y][1] = 1;
                }
            }
        }
        else    //삭제
        {
            if (a == 0)    //기둥 삭제
            {
                board[x][y][0] = 0;
                if (!isRemovePossible()) board[x][y][0] = 1;
            }
            else        //보 삭제
            {
                board[x][y][1] = 0;
                if (!isRemovePossible()) board[x][y][1] = 1;
            }
        }
    }

    for (int x = 0; x <= n; x++)
    {
        for (int y = 0; y <= n; y++)
        {
            for (int type = 0; type < 2; type++)
            {
                if (board[x][y][type])
                {
                    vector<int> tmp;
                    tmp.push_back(x);
                    tmp.push_back(y);
                    tmp.push_back(type);

                    answer.push_back(tmp);
                }
            }
        }
    }

    return answer;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<vector<int>> bf = { {0, 0, 0, 1}, {2, 0, 0, 1}, { 4, 0, 0, 1}, { 0, 1, 1, 1}, { 1, 1, 1, 1}, { 2, 1, 1, 1}, { 3, 1, 1, 1}, {2, 0, 0, 0}, { 1, 1, 1, 0}, { 2, 2, 0, 1}};
    vector<vector<int>> v = solution(5, bf);

    for (auto e : v)
    {
        for (int n : e)
            cout << n << " ";
        cout << "\n";
    }


    return 0;
}

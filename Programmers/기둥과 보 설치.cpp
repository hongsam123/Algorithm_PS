#include <string>
#include <vector>
#include<iostream>
using namespace std;

bool board[102][102][2];//0�� ���  1�� ��
//ó���� 2���� �迭�� 0�� �ƹ��͵� ����, 1�� ���, 2�� ��, 3�� ���&���� Ǯ���ٰ� �ʹ� ����ؾ��� ��찡 ���� ��̴�..
int boardsize;

bool checkCoverage(int x, int y)
{
    if (x<0 || y<0 || x>boardsize || y>boardsize)
        return false;
    return true;
}

bool isSetPossible(int x,int y,int type)
{
    if (type == 0) //����� ��ġ�� ��
    {
        if (y == 0) return true;    //�ٴ� ���� ������ ����

        //���� ���� �� �κ� ���� ������ ����
        if ((checkCoverage(x - 1, y) && board[x - 1][y][1]) || board[x][y][1]) return true;
        
        //�ٸ� ��� ���� ������ ����
        if (checkCoverage(x, y - 1) && board[x][y - 1][0]) return true;
    }
    else
        //���� ��ġ�� ��
    {
        //���� ���κ��� ��� ���� �ְų�
        if ((checkCoverage(x, y - 1) && board[x][y - 1][0]) || (checkCoverage(x + 1, y - 1) && board[x + 1][y - 1][0]))
            return true;

        //���� �� �κ��� �ٸ� ���� ���ÿ� ����Ǿ� �־�� �Ѵ�
        if((checkCoverage(x-1,y)&&checkCoverage(x+1,y)) && board[x-1][y][1] &&board[x+1][y][1])
            return true;
    }
    return false;
}

bool isRemovePossible() //��������(ũ�Ⱑ �۾� ȿ���� ����� �� �ʿ� ����
{
    for (int x = 0; x < boardsize; x++)
    {
        for (int y = 0; y < boardsize; y++)
        {
            for (int type = 0; type < 2; type++)
            {
                if (board[x][y][type])   //��� �Ǵ� ���� ���� ��
                {
                    board[x][y][type] = 0;  //�����ߴٰ�
                    if (!isSetPossible(x, y, type)) //�ٽ� ��ġ�� ��� ������ ������Ȯ��
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
        int x = build_frame[i][0];  //x��ǥ
        int y = build_frame[i][1];  //y��ǥ
        int a = build_frame[i][2];  //0�̸� ���, 1�̸� ��
        int b = build_frame[i][3];  //0�̸� ����, 1�̸� ��ġ

        if (b)   //��ġ
        {
            if (a == 0)    //��� ��ġ
            {
                if (isSetPossible(x, y, 0))
                {
                    board[x][y][0] = 1;
                }
            }

            else    //�� ��ġ
            {
                if (isSetPossible(x, y, 1))
                {
                    board[x][y][1] = 1;
                }
            }
        }
        else    //����
        {
            if (a == 0)    //��� ����
            {
                board[x][y][0] = 0;
                if (!isRemovePossible()) board[x][y][0] = 1;
            }
            else        //�� ����
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

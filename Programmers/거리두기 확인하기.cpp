#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#include <iostream>
using namespace std;

char board[5][5];
bool visited[5][5];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    for (int t = 0; t < places.size(); t++)
    {
        //입력
        for (int i = 0; i < 5; i++)
        {
            string str = places[t][i];
            for (int j = 0; j < 5; j++)
            {
                board[i][j] = str[j];
            }
        }

        queue<tuple<int, int, int>> q;    //<x,y,dist>
        int ans = 1;

        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (board[i][j] == 'P')
                {
                    for (int k = 0; k < 5; k++)
                        fill(visited[k], visited[k] + 5, 0);

                    q.push(make_tuple( i,j,0 ));
                    visited[i][j] = 1;
                }

                while (!q.empty())
                {
                    auto cur = q.front(); q.pop();

                    int x = get<0>(cur);
                    int y = get<1>(cur);
                    int d = get<2>(cur);

                    //맨해튼 거리가 3이상이라면 통과
                    if (d > 2) continue;

                    //맨해튼 거리가 1이고 P인 경우 거리두기 지키지 않음
                    if (d == 1 && board[x][y] == 'P')
                    {
                        ans = 0;
                        break;
                    }

                    //맨해튼 거리가 2인 경우
                    if (d == 2 && board[x][y] == 'P')
                    {
                        if (x == i || y == j)    //일자로 앉은 경우 사이에 파티션이 있지 않으면 거리두기 지키지 않음
                        {
                            int nx = (x + i) / 2;
                            int ny = (y + j) / 2;
                            if (board[nx][ny] != 'X')
                            {
                                ans = 0;
                                break;
                            }
                        }
                        else                //대각선으로 앉은 경우 사이에 파티션이 있지 않으면 거리두기 지키지 않음
                        {
                            if (board[i][y] != 'X' || board[x][j] != 'X')
                            {
                                ans = 0;
                                break;
                            }
                        }
                    }
                    if (ans == 0) break;

                    for (int dir = 0; dir < 4; dir++)
                    {
                        int nx = get<0>(cur) + dx[dir];
                        int ny = get<1>(cur) + dy[dir];
                        if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
                        if (visited[nx][ny]) continue;
                        visited[nx][ny] = 1;
                        q.push(make_tuple( nx,ny,d + 1 ));
                    }
                }
                if (ans == 0) break;
            }
            if (ans == 0) break;
        }
        answer.push_back(ans);
    }

    return answer;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<vector<string>> v = { {"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"}, {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"}, {"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"}, {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"}, {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"} };
    vector<int> vec = solution(v);
    for (int e : vec)
        cout << e << " ";

    return 0;
}

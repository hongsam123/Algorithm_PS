#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
#define X first
#define Y second
using namespace std;

int n, ans;
int dist[27][27][4];                //[x][y][dir방향으로 도착했을때의 비용]
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
queue < tuple<int, int,int>> q;     //<x,y,dir>
const int INF = 1e9 + 10;

int solution(vector<vector<int>> board) {
    int answer = 0;
    n = board.size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 4; k++) {
                dist[i][j][k] = INF;
            }
        }
    }

    for (int i = 0; i < 4; i++)
        dist[0][0][i] = 0;
    q.push({ 0,0,-1 });

    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        int x = get<0>(cur);
        int y = get<1>(cur);
        int d = get<2>(cur);

        if (x == n - 1 && y == n - 1) {
           if (ans == 0) ans = dist[n - 1][n - 1][d];
            else ans = min(ans, dist[n - 1][n - 1][d]);
        }

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (board[nx][ny]) continue;
            int cost = 0;
            if (d!=-1 && dir != d) cost = 600;
            else cost = 100;
            if (dist[nx][ny][dir] < cost + dist[x][y][d]) continue;
            dist[nx][ny][dir] = cost + dist[x][y][d];
            q.push({ nx,ny,dir });
        }
    }

    answer = ans;

    return answer;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << solution({ {0, 0, 0, 0, 0},{0, 1, 1, 1, 0}, {0, 0, 1, 0, 0},{ 1, 0, 0, 0, 1}, { 0, 1, 1, 0, 0 }});

    return 0;
}

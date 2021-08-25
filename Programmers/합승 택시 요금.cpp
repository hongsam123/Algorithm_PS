#include <string>
#include <vector>
#include <algorithm>
#include<iostream>
using namespace std;

int dp[202][202];   //노드간 최단 거리
const int INF = 1e9+10;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    
    for(int i=1;i<=n;i++)
        fill(dp[i],dp[i]+n+1,INF);
    
    for(int i=0;i<fares.size();i++) {
        auto cur = fares[i];
        int u = cur[0];
        int v = cur[1];
        int dist = cur[2];
        dp[u][v] = dist;
        dp[v][u] = dist;
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(i==j) dp[i][j] = 0;
        }
    }
    
    for(int k=1;k<=n;k++) {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }
    
    if(dp[s][a]!=INF && dp[s][b]!=INF)
        answer = dp[s][a] + dp[s][b];
    
    for(int i=1;i<=n;i++) {
        if(i==s) continue;
        if(dp[s][i]!=INF && dp[i][a]!=INF && dp[i][b]!=INF)
        {
            int dist = dp[s][i] + dp[i][a] + dp[i][b];
            answer = min(answer,dist);
        }
    }
    
    return answer;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cout<<solution(6,4,6,2,	{{4, 1, 10}, {3, 5, 24}, {5, 6, 2}, {3, 1, 41}, {5, 1, 24},{4, 6, 50}, {2, 4, 66}, {2, 3, 22}, {1, 6, 25}});
	//cout<<solution(7,3,4,1,{{5, 7, 9}, {4, 6, 4}, {3, 6, 1}, {3, 2, 3}, {2, 1, 6}});
	
	
	return 0;
}

package algorithm.boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj1987 {
    static int r,c;
    static int sum;
    static boolean[] isused = new boolean[30];
    static int ans;
    static int[] dx= {1,0,-1,0};
    static int[] dy = {0,1,0,-1};
    static char[][] board = new char[22][22];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String line[] = br.readLine().split(" ");
        r= Integer.parseInt(line[0]);
        c = Integer.parseInt(line[1]);

        for(int i=0;i<r;i++) {
            String str = br.readLine();
            for(int j=0;j<c;j++) {
                board[i][j] = str.charAt(j);
            }
        }

        sum += 1;
        isused[board[0][0]-'A'] = true;
        dfs(0,0);

        System.out.println(ans);
    }

    static void dfs(int x,int y) {
        ans = Integer.max(ans,sum);

        for(int dir = 0;dir<4;dir++) {
            int nx = x + dx[dir];
            int ny = y+dy[dir];
            if(nx<0 || nx>=r||ny<0||ny>=c) continue;
            if(isused[board[nx][ny]-'A']) continue;
            isused[board[nx][ny]-'A'] =true;
            sum += 1;
            dfs(nx,ny);
            sum-=1;
            isused[board[nx][ny]-'A'] = false;
        }
    }
}

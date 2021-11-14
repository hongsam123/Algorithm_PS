package algorithm.boj;

import java.awt.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;

public class boj19238 {
    static int n,m;
    static int[][] board = new int[21][21];
    static int[] dx = {-1,0,0,1};
    static int[] dy = {0,-1,1,0};
    static int x,y,fuel;
    static ArrayList<Pair> dest = new ArrayList<>();
    static int[][]dist = new int[21][21];

    static class Pair {
        int x;
        int y;

        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
    static class Tuple implements Comparable<Tuple>{
        int d;
        int x;
        int y;

        public Tuple(int d, int x, int y) {
            this.d = d;
            this.x = x;
            this.y = y;
        }

        @Override
        public int compareTo(Tuple o) {
            if(this.d>o.d)
                return 1;
            else if(this.d==o.d) {
                if (this.x > o.x) {
                    return 1;
                }
                else if(this.x==o.x) {
                    if (this.y < o.y) {
                        return 1;
                    }
                }
            }
            return -1;
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");
        n = Integer.parseInt(line[0]);
        m = Integer.parseInt(line[1]);
        fuel = Integer.parseInt(line[2]);

        for(int i=1;i<=n;i++) {
            line = br.readLine().split(" ");
            for(int j=1;j<=n;j++ ){
                board[i][j] = Integer.parseInt(line[j-1]);
                if(board[i][j]==1) board[i][j] = -1;
            }
        }
        line = br.readLine().split(" ");
        x = Integer.parseInt(line[0]);
        y = Integer.parseInt(line[1]);

        dest.add(new Pair(0, 0));
        for(int i=1;i<=m;i++) {
            line = br.readLine().split(" ");
            board[Integer.parseInt(line[0])][Integer.parseInt(line[1])] = i;
            dest.add(new Pair(Integer.parseInt(line[2]), Integer.parseInt(line[3])));
        }

        for(int k=0;k<m;k++) {
            //태울 승객 고르기
            int guest = 0;
            PriorityQueue<Tuple> q = new PriorityQueue<>();

            for(int i=1;i<=n;i++) {
                for(int j=1;j<=n;j++) {
                    dist[i][j] = -1;
                }
            }

            dist[x][y] = 0;
            q.add(new Tuple(0, x, y));

            while (!q.isEmpty()) {
                Tuple cur = q.poll();
                int d = cur.d;
                int curX = cur.x;
                int curY = cur.y;

                if(board[curX][curY]>0) {
                    guest = board[curX][curY];
                    board[curX][curY] = 0;
                    fuel -= d;
                    x = curX;
                    y = curY;
                    break;
                }

                for(int dir =0;dir<4;dir++) {
                    int nx = curX + dx[dir];
                    int ny = curY + dy[dir];
                    if(nx<=0||nx>n||ny<=0||ny>n) continue;
                    if(board[nx][ny]==-1 || dist[nx][ny] != -1) continue;
                    dist[nx][ny] = d + 1;
                    q.add(new Tuple(dist[nx][ny], nx, ny));
                }
            }

            if (fuel <= 0 || guest == 0) {
                System.out.println(-1);
                System.exit(1);
            }

            int dest_x = dest.get(guest).x;
            int dest_y = dest.get(guest).y;

            Queue<Pair> que = new LinkedList<>();
            int tax = -1;

            for(int i=1;i<=n;i++) {
                for(int j=1;j<=n;j++) {
                    dist[i][j] = -1;
                }
            }
            dist[x][y] = 0;
            que.add(new Pair(x, y));
            while (!que.isEmpty()) {
                Pair cur = que.poll();
                if(cur.x==dest_x && cur.y==dest_y) {
                    tax = 2 * dist[cur.x][cur.y];
                    fuel -= dist[cur.x][cur.y];
                    x = cur.x;
                    y = cur.y;
                    break;
                }

                for(int dir = 0;dir<4;dir++) {
                    int nx = cur.x + dx[dir];
                    int ny = cur.y + dy[dir];
                    if(nx<=0||nx>n||ny<=0||ny>n) continue;
                    if(board[nx][ny]==-1 || dist[nx][ny] != -1) continue;
                    dist[nx][ny] = dist[cur.x][cur.y]+1;
                    que.add(new Pair(nx,ny));
                }
            }
            if (fuel < 0 || tax == -1) {
                System.out.println(-1);
                System.exit(1);
            }
            fuel += tax;
        }
        System.out.println(fuel);
    }
}

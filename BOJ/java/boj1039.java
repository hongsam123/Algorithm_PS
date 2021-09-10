package algorithm.boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;

public class boj1039 {
    static class Node {
        String s;
        int d;

        public Node(String s, int d) {
            this.s = s;
            this.d = d;
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");
        String str = line[0];
        int k = Integer.parseInt(line[1]);
        int ans = 0;

        int m = str.length();

        Queue<Node> q = new LinkedList<Node>();
        boolean[][] visited = new boolean[1000001][k+1];
        q.add(new Node(str,0));

        while(!q.isEmpty()) {
            Node cur = q.poll();
            //HashSet<String> set = new HashSet<>();
            //if(cur.s.charAt(0)=='0') continue;
            if(cur.d==k) {
                ans = Math.max(ans, Integer.parseInt(cur.s));
                continue;
            }
            //System.out.println(cur.s + " " +cur.d);

            for(int i=0;i<m-1;i++) {
                for(int j=i+1;j<m;j++) {
                    if(i==0 && cur.s.charAt(j)=='0') continue;
                    StringBuilder sb = new StringBuilder(cur.s);
                    sb.setCharAt(i, cur.s.charAt(j));
                    sb.setCharAt(j, cur.s.charAt(i));
                    if(visited[Integer.parseInt(sb.toString())][cur.d+1]) continue;
                    //if(set.contains(sb.toString())) continue;
                    q.add(new Node(sb.toString(), cur.d + 1));
                    visited[Integer.parseInt(sb.toString())][cur.d+1] = true;
                }
            }
        }


        if(ans==0) System.out.println(-1);
        else System.out.println(ans);
    }
}

package algorithm.boj.graph;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;

public class boj1167 {

    static ArrayList<ArrayList<Pair>> adj = new ArrayList<>();
    static int[] dist = new int[100002];
    static final int INF = 987654321;
    static PriorityQueue<Pair> pq = new PriorityQueue<>();

    static class Pair implements Comparable<Pair>{
        int cost;
        int idx;
        public Pair(int cost,int idx) {
            this.cost = cost;
            this.idx = idx;
        }

        @Override
        public int compareTo(Pair o) {
            if(this.cost<o.cost) return -1;
            else return 1;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        for(int i=0;i<=n;i++) {
            adj.add(new ArrayList<>());
        }

        for(int i=1;i<=n;i++) {
            String[] line = br.readLine().split(" ");
            int index = Integer.parseInt(line[0]);
            for(int j=1;j<line.length-1;j+=2) {
                adj.get(index).add(new Pair(Integer.parseInt(line[j+1]),Integer.parseInt(line[j])));
            }
        }
        //임의의 점에서 가장 거리가 먼 점 구하기
        Arrays.fill(dist,INF);

        pq.add(new Pair(0,1));
        dist[1] = 0;

        while(!pq.isEmpty()) {
            Pair cur = pq.poll();

            if(cur.cost!=dist[cur.idx]) continue;

            for(Pair nxt : adj.get(cur.idx)) {
                int ncost = nxt.cost;
                int nidx = nxt.idx;
                if(dist[nidx]>ncost+cur.cost) {
                    dist[nidx] = ncost+cur.cost;
                    pq.add(new Pair(ncost+cur.cost,nidx));
                }
            }
        }

        int x = 0;
        int max_cost = 0;
        for(int i=2;i<=n;i++) {
            if(max_cost<dist[i]) {
                x = i;
                max_cost = dist[i];
            }
        }
        //새로운 점에서 가장 먼 노드 구하기
        Arrays.fill(dist,INF);

        pq.add(new Pair(0,x));
        dist[x] = 0;

        while(!pq.isEmpty()) {
            Pair cur = pq.poll();

            if(cur.cost!=dist[cur.idx]) continue;

            for(Pair nxt : adj.get(cur.idx)) {
                int ncost = nxt.cost;
                int nidx = nxt.idx;
                if(dist[nidx]>ncost+cur.cost) {
                    dist[nidx] = ncost+cur.cost;
                    pq.add(new Pair(ncost+cur.cost,nidx));
                }
            }
        }

        int answer = 0;
        for(int i=1;i<=n;i++) {
            if(answer<dist[i]) answer = dist[i];
        }


        System.out.println(answer);


    }
}

import java.util.*;

class Solution {
    public int solution(int[][] jobs) {
        int answer = 0;
        
        //이차원 배열에서 각 원소의 첫번째 원소를 기준으로 정렬하기
        Arrays.sort(jobs, Comparator.comparingInt(o1->o1[0]));
        
        PriorityQueue<Pair> pq = new PriorityQueue<Pair>();
        
        int idx = 0;
        int time = 0;
        
        while(true){
            //현재 시간에 따라 대기 큐에 작업 채우기
            while(true) {
                int inTime = jobs[idx][0];
                int doTime = jobs[idx][1];
                if(inTime<=time){
                    pq.add(new Pair(doTime,inTime));
                    idx++;
                    if(idx==jobs.length) break;
                }else break;
            }
            if(idx==jobs.length) break;
            
            //현재 대기 큐에서 가장 작업 시간이 짧은 시간인 작업 수행하기
            if(!pq.isEmpty()){
                Pair cur = pq.poll();
                time += cur.x;
                answer += (time-cur.y);
            }
            else time++;
            
        }
        
        //대기 큐에 전부 찼다면 while문을 빠져나오고 대기 큐에 있는 작업을 짧은 수행시간 기준으로 처리
        while(!pq.isEmpty())
        {
            Pair cur = pq.poll();
            time += cur.x;
            answer += (time-cur.y);
        }
        answer /= jobs.length;
        return answer;
    }
}

class Pair implements Comparable<Pair>{
    int x;
    int y;
    Pair(int x,int y) {
        this.x = x;
        this.y = y;
    }
    
    @Override
    public int compareTo(Pair p) {
        if(this.x<p.x) return -1;
        else return 1;
    } 
}
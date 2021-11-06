import java.util.*;

class Solution {
    public int solution(int[] scoville, int K) {
        int answer = 0;
        
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        
        for(int i=0;i<scoville.length;i++) {
            int sco = scoville[i];
            pq.add(sco);
        }
        
        if(pq.peek()>=K) return answer;
        
        while(true) {
            answer++;
            
            if(pq.size()<2) break;
            
            int a = pq.poll();
            int b = pq.poll();
            
            int num = a + b*2;
            pq.add(num);
            
            if(pq.peek()>=K)
                return answer;
        }
        
        return -1;
    }
}
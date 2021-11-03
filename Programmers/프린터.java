import java.util.*;

class Solution {
    public int solution(int[] priorities, int location) {
        int answer = 0;
        int[] priority = new int[10];
        Queue<Integer> q = new LinkedList<>();
        
        int originalNum = 0;
        for(int i=0;i<priorities.length;i++) {
            int num = priorities[i];
            priority[num]++;
            if(i==location) 
            {
                q.offer(num*-1);
                originalNum = num;
            }
            else q.offer(num);
        }
        
        while(true) {
            int cur = q.poll();
            int maxPrior =0;
            for(int i=9;i>=originalNum;i--) {
                if(priority[i]>0)
                {
                    maxPrior = i;
                    break;
                }
            }
            
            if(cur==maxPrior){
                priority[cur]--;
                answer++;
                continue;
            }
            else if((cur*-1)==maxPrior){
                answer++;
                break;
            }else {
                q.offer(cur);
            }

        }
        
        return answer;
    }
}
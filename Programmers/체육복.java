import java.util.*;

class Solution {
    public int solution(int n, int[] lost, int[] reserve) {
        int answer = n-lost.length;
        
        boolean[] isReserve = new boolean[32];
        
        for(int i=0;i<reserve.length;i++) {
            isReserve[reserve[i]] = true;
        }
        
        
        Arrays.sort(lost);
        
        for(int i=0;i<lost.length;i++){
            if(isReserve[lost[i]]){
                isReserve[lost[i]] = false;
                lost[i] = 0;
                answer++;
            }
        }
        
        for(int i=0;i<lost.length;i++){
            int stu = lost[i];
            if(stu==0) continue;
            
            if(isReserve[stu-1]) {
                isReserve[stu-1] = false;
                answer++;
            }else if(isReserve[stu+1]){
                isReserve[stu+1] = false;
                answer++;
            } else continue;
        }        
        
        return answer;
    }
}
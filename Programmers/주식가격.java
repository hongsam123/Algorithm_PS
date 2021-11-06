import java.util.*;

class Solution {
    public int[] solution(int[] prices) {
        int[] answer = new int[prices.length];
        
        for(int i=0;i<prices.length;i++)
        {
            int p = prices[i];
            if(i==prices.length-1)
                answer[i] = 0;
            else {
                int cnt = 0;
                for(int j=i+1;j<prices.length;j++) {
                    if(prices[j]<p) {
                        cnt++;
                        break;
                    }else {
                        cnt++;
                    }
                }
                answer[i] = cnt;
            }
        }        
        return answer;
    }
}
import java.util.*;

class Solution {
    public int solution(int[] citations) {
        int answer = 0;
        
        Arrays.sort(citations);
        
        for(int i=1;i<=citations.length;i++) {
            int not = 0;
            for(int j=0;j<citations.length;j++) {
                if(citations[j]<i) not++;
                else {
                    if(not<=i && (citations.length-j)>=i) {
                        answer = i;
                        break;
                    }
                }
            }
        }
        
        
        return answer;
    }
}
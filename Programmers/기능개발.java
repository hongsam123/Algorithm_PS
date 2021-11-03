import java.util.*;

class Solution {
    public int[] solution(int[] progresses, int[] speeds) {        
        ArrayList<Integer> list = new ArrayList<>();
        ArrayList<Integer> result = new ArrayList<>();
        
        for(int i=0;i<progresses.length;i++) {
            int prog = progresses[i];
            int sp = speeds[i];
            
            int num = 100-prog;
            if(num%sp!=0){
                list.add(num/sp+1);
            }else{
                list.add(num/sp);
            }
        }
        
        int cnt = 1;
        int max = list.get(0);
        if(list.size()>=2){
            for(int i=1;i<list.size();i++) {
                int num = list.get(i);
                if(num>max) {
                    max = num;
                    result.add(cnt);
                    cnt = 1;
                } else {
                    cnt++;
                }
            }
            result.add(cnt);
        }
        else {
            result.add(1);
        }
        
        int[] answer = new int[result.size()];
        for(int i=0;i<result.size();i++) {
            answer[i] = result.get(i);
        }
        
        return answer;
    }
}
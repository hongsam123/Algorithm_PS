import java.util.*;

class Solution {
    public String solution(String[] participant, String[] completion) {
        String answer = "";
        
        HashMap<String,Integer> hm = new HashMap<>();
        for(int i=0;i<participant.length;i++) {
            String p = participant[i];
            if(hm.containsKey(p)) {
            //이미 있으면 1추가
                hm.put(p,hm.get(p)+1);
            }else {
            //없으면 hm에 넣기
                hm.put(p,1);
            }
        }
        
        for(int i=0;i<completion.length;i++) {
            String c = completion[i];
            hm.put(c,hm.get(c)-1);
        }
        
        for(String s : hm.keySet()) {
            if(hm.get(s)!=0) {
                answer = s;
            }
        }
        
        return answer;
    }
}
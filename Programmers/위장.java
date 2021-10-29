import java.util.*;

class Solution {
    public int solution(String[][] clothes) {
        int answer = 1;
        HashMap<String,Integer> hm = new HashMap<>();
        
        for(int i=0;i<clothes.length;i++) {
            //String name = clothes[i][0];
            //같은 이름을 가지는 의상은 존재하지 x
            String type = clothes[i][1];
            if(!hm.containsKey(type)){
                hm.put(type,1);
            }else {
                hm.put(type,hm.get(type)+1);
            }
        }
        
        for(String key : hm.keySet()) {
            answer *= (hm.get(key)+1);
        }
        
        return (answer-1);
    }
}
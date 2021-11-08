import java.util.*;

class Solution {
    public int[] solution(int[] array, int[][] commands) {
        int[] answer = new int[commands.length];
        
        ArrayList<Integer> list=  new ArrayList<>();
        
        for(int com = 0;com<commands.length;com++) {
            int a = commands[com][0];
            int b = commands[com][1];
            int k = commands[com][2];
            
            for(int j=a-1;j<=b-1;j++) {
                list.add(array[j]);
            }
            Collections.sort(list);
            
            answer[com] = list.get(k-1);
            
            list.clear();
        }
        
        return answer;
    }
}
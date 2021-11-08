import java.util.*;

class Solution {
    public String solution(int[] numbers) {
        StringBuilder sb = new StringBuilder();
        
        ArrayList<String> list = new ArrayList<>();
        
        for(int i=0;i<numbers.length;i++) {
            list.add(String.valueOf(numbers[i]));
        }
        
        //b+a가 값이 더 클 경우 자리를 바꿔준다
        Collections.sort(list,new Comparator<String>(){
            @Override
            public int compare(String a,String b) {
                return (b+a).compareTo(a+b);
            }
        });
        
        if(list.get(0).charAt(0)=='0') return "0";
        
        for(int i=0;i<list.size();i++) {
            sb.append(list.get(i));
        }
        
        String answer = sb.toString();
        
        return answer;
    }
}
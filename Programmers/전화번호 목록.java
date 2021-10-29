import java.util.*;

class Solution {
    public boolean solution(String[] phone_book) {
        boolean answer = true;
        
        Arrays.sort(phone_book);
        HashSet<String> hs = new HashSet<>();
        
        for(int i=phone_book.length-1;i>=0;i--) {
            String str = phone_book[i];
            if(hs.contains(str)){
                answer = false;
                break;
            } 
            else {
                for(int j=1;j<=str.length();j++) {
                    String new_str = str.substring(0,j);
                    hs.add(new_str);
                }
            }
        }
        
        return answer;
    }
}
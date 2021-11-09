import java.util.*;

class Solution {
    static String str;
    static String s="";
    static boolean[] isused = new boolean[10];
    static HashSet<Integer> hs = new HashSet<>();
    //소수찾기
    static boolean check() {
        int num = Integer.parseInt(s);
        if(num<=1) return false;
        for(int i=2;i*i<=num;i++){
            if(num%i==0) return false;
        }
        return true;
    }
    
    static void func(int k) {
        if(!s.equals("") && check()){
            hs.add(Integer.parseInt(s,10));
        }
        
        if(k == str.length()) return;
        
        for(int i=0;i<str.length();i++) {
            if(isused[i]) continue;
            s += str.charAt(i);
            isused[i] = true;
            
            func(k+1);
            
            isused[i] = false;
            s = s.substring(0,s.length()-1);
        }
    }
        
    public int solution(String numbers) {
        str = numbers;
        
        func(0);
        
        int answer = hs.size();
        
        return answer;
    }
}
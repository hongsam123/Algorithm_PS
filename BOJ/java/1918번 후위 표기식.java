package algorithm.boj.stack;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Stack;

public class boj1918 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();

        Stack<Character> s = new Stack<>();
        HashMap<Character,Integer> hm = new HashMap<>();
        hm.put('*',2);
        hm.put('/',2);
        hm.put('+',1);
        hm.put('-',1);

        String answer = "";
        for(int i=0;i<str.length();i++) {
            char ch = str.charAt(i);
            if(ch>='A' && ch<='Z') answer+=ch;
            else if(ch=='(') {
                s.add('(');
            }
            else if(ch==')') {
                while(s.peek()!='(') {
                    answer+=s.peek();
                    s.pop();
                }
                s.pop();
            }
            else {
                if(s.isEmpty()||s.peek()=='(') s.add(ch);
                else {
                    if(hm.get(ch)>hm.get(s.peek())) {
                        s.add(ch);
                    }else {
                        while(!s.isEmpty()) {
                            if(s.peek()=='(') break;
                            answer+=s.peek();
                            s.pop();
                            if((!s.isEmpty() && s.peek()!='(') && hm.get(ch)==2 && hm.get(s.peek())<hm.get(ch)) break;
                        }
                        s.add(ch);
                    }
                }
            }
        }

        while(!s.isEmpty()) {
            answer+= s.peek(); s.pop();
        }

        System.out.println(answer);
    }
}

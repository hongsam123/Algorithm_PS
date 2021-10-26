package algorithm.boj.hash;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Scanner;

public class boj11478 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.next();
        HashSet<String> hs = new HashSet<>();

        for(int i=0;i<str.length();i++) {
            for(int j=0;j<=str.length();j++) {
                if(i+j>str.length()) continue;
                String tmp = str.substring(i,i+j);
                hs.add(tmp);
            }
        }
        System.out.println(hs.size()-1);
    }
}

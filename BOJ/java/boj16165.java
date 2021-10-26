package algorithm.boj.hash;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.TreeMap;

public class boj16165 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        String[] line = br.readLine().split(" ");
        int n =Integer.parseInt(line[0]);
        int m = Integer.parseInt(line[1]);

        TreeMap<String, String> tm = new TreeMap<>();

        for(int i=0;i<n;i++) {
            String group = br.readLine();
            int k = Integer.parseInt(br.readLine());
            for(int j=0;j<k;j++) {
                String name = br.readLine();
                tm.put(name, group);
            }
        }

        for(int i=0;i<m;i++) {
            String name = br.readLine();
            int op = Integer.parseInt(br.readLine());
            if(op==1) {
                //멤버의 팀 이름 출력
                sb.append(tm.get(name)+"\n");
            }else {
                for (String keyVal : tm.keySet()) {
                    if (tm.get(keyVal).equals(name)) {
                        sb.append(keyVal+"\n");
                    }
                }
            }
        }
        System.out.println(sb.toString());
    }
}

package algorithm.boj.hash;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Iterator;

public class boj19583 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");
        String[] time = new String[100002];
        String[] name = new String[100002];

        String s = line[0];
        String e = line[1];
        String q = line[2];

        String input;
        int idx = 0;
        while((input=br.readLine()) != null) {
            line = input.split(" ");
            time[idx] = line[0];
            name[idx] = line[1];
            idx++;
        }

        HashSet<String> entrance = new HashSet<>();
        HashSet<String> exit = new HashSet<>();

        for(int i = 0;i<idx;i++) {
            //개강총회 시작 전 입장확인여부
            if(Integer.parseInt(s.substring(0,2))>Integer.parseInt(time[i].substring(0,2))
            || (Integer.parseInt(s.substring(0,2))==Integer.parseInt(time[i].substring(0,2))
                    && Integer.parseInt(s.substring(3,5))>=Integer.parseInt(time[i].substring(3,5)))) {
                entrance.add(name[i]);
            }
            //퇴장 확인여부
            if(Integer.parseInt(e.substring(0,2))<Integer.parseInt(time[i].substring(0,2))
            || (Integer.parseInt(e.substring(0,2)) == Integer.parseInt(time[i].substring(0,2))
                    && Integer.parseInt(e.substring(3,5))<=Integer.parseInt(time[i].substring(3,5)))) {
                if(Integer.parseInt(q.substring(0,2))>Integer.parseInt(time[i].substring(0,2))
                || (Integer.parseInt(q.substring(0,2)) == Integer.parseInt(time[i].substring(0,2))
                    && Integer.parseInt(q.substring(3,5))>= Integer.parseInt(time[i].substring(3,5)))) {
                    exit.add(name[i]);
                }
            }
        }

        int cnt = 0;
        for (String en : entrance) {
            if(exit.contains(en))
                cnt++;
        }

        System.out.println(cnt);

    }
}

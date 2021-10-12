package algorithm.boj.stage11.bruteforce;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj1107 {
    static int n,m;
    static boolean[] notWorking = new boolean[12];

    static boolean check(int x) {
        String str = Integer.toString(x);
        //System.out.println(str);
        for(int i=0;i<str.length();i++) {
            int num = str.charAt(i) - '0';
            if(notWorking[num]) return false;
        }
        return true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        m = Integer.parseInt(br.readLine());
        if(m>0) {
            String[] line = br.readLine().split(" ");
            for (int i = 0; i < line.length; i++) {
                notWorking[Integer.parseInt(line[i])] = true;
            }
        }

        if(m==10) {
            System.out.println(Math.abs(n-100));
            return;
        }

        int number = 0;
        //이동할 번호
        if(check(n)) {
            //n으로 바로 갈 수 있다면
            number = n;
        }else {
            int up_n = n+1;
            int down_n = n-1;
            while(true) {
                if (check(up_n)) {
                    number = up_n;
                    if (down_n>=0 && check(down_n)) {
                        if (Integer.toString(up_n).length() > Integer.toString(down_n).length()) {
                            number = down_n;
                        }
                    }
                    break;
                }else {
                    up_n++;
                    if(down_n<0) continue;
                    if (check(down_n)) {
                        number = down_n;
                        break;
                    }
                    else {
                        down_n--;
                    }
                }
            }
        }

        int a = Math.abs(100 - n);
        int b = Integer.toString(number).length() + Math.abs(n-number);

        System.out.println(Math.min(a,b));
    }
}

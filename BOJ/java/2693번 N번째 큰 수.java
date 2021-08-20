import java.util.ArrayList;
import java.util.Scanner;

import static java.util.Collections.sort;

public class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        ArrayList<Integer> list = new ArrayList<>();

        for(int test = 0;test<t;test++) {
            for(int i=0;i<10;i++)
                list.add(sc.nextInt());
            sort(list);
            System.out.println(list.get(7));
            list.clear();
        }
    }
}

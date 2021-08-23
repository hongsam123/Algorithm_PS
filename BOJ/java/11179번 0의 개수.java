import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());

        for(int test = 0;test<t;test++) {
            String[] line = br.readLine().split(" ");
            int n = Integer.parseInt(line[0]);
            int m = Integer.parseInt(line[1]);

            int ans = 0;
            for(int i=n;i<=m;i++) {
                if(i==0) {
                    ans++;
                    continue;
                }
                int tmp = i;
                while(tmp>=10) {
                    if(tmp%10==0) ans++;
                    tmp /= 10;
                }
            }
            System.out.println(ans);
        }
    }
}

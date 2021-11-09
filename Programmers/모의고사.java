import java.util.*;

class Solution {
    public int[] solution(int[] answers) {
        int[] cnt = new int[4];
        int[] ans1 = new int[answers.length];
        int[] ans2 = new int[answers.length];
        int[] ans3 = new int[answers.length];
        
        //1번 수포자 정답
        int x = 1;
        for(int i=0;i<answers.length;i++) {
            ans1[i] = x++;
            if(x==6) x = 1;
        }
        
        //2번 수포자 정답
        int[] x2 = {2,1,2,3,2,4,2,5};
        x = 0;
        for(int i=0;i<answers.length;i++) {
            ans2[i] = x2[x++];
            if(x>=8) x = 0;
        }
        
        //3번 수포자 정답
        int[] x3 = {3,3,1,1,2,2,4,4,5,5};
        x = 0;
        for(int i=0;i<answers.length;i++) {
            ans3[i] = x3[x++];
            if(x>=10) x = 0;     
        }        
        
        for(int i=0;i<answers.length;i++) {
            int ans = answers[i];
            if(ans1[i]==ans) cnt[1]++;
            if(ans2[i]==ans) cnt[2]++;
            if(ans3[i]==ans) cnt[3]++;
        }
        
        int max = 0;
        for(int i=1;i<=3;i++) {
            if(max<cnt[i]) max = cnt[i];
        }
        
        ArrayList<Integer> l = new ArrayList<Integer>();
        for(int i=1;i<=3;i++) {
            if(cnt[i]==max)
                l.add(i);
        }
        
        int[] answer = new int[l.size()];
        for(int i=0;i<l.size();i++)
            answer[i] = l.get(i);
        
        return answer;
    }
}
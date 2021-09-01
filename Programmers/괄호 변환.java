package stage11.bruteforce;

class Solution {
    static boolean isRight(String s) {
        int cnt = 0;
        for (int i = 0; i < s.length(); i++) {
            if(s.charAt(i)=='(') cnt++;
            else cnt--;

            if(cnt<0) return false;
        }
        return true;
    }

    static String solution(String p) {
        //1
        if(p=="") return p;

        //2
        String u = "";
        String v = "";
        int cnt = 0;
        for (int i = 0; i < p.length(); i++) {
            if(p.charAt(i)=='(') cnt++;
            else cnt--;

            if (cnt == 0) {
                //지금까지 본 문자열이 균형잡힌 문자열이라면
                u = p.substring(0,i+1);
                v = p.substring(i+1);
                break;
            }
        }

        //3
        if (isRight(u)) {
            return u + solution(v);
        }

        //4
        String tmp = "(";
        tmp += solution(v);
        tmp += ')';

        //4-4
        for (int i = 1; i < u.length() - 1; i++) {
            if(u.charAt(i)=='(') tmp += ')';
            else tmp += '(';
        }

        return tmp;
    }

    public static void main(String[] args) {
        System.out.println(solution("(()())()"));
    }
}
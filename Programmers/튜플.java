import java.util.*;

class Solution {
    static int[] solution(String s) {
        int[] answer;

        HashMap<Integer, Integer> map = new HashMap<>();
        HashMap<Integer, Integer> re_map = new HashMap<>();

        String str = "";
        for(int i=0;i<s.length();i++) {
            char ch = s.charAt(i);
            if(ch=='{') continue;

            if(ch>='0' && ch<='9') {
                str += s.charAt(i);
                continue;
            }

            if(ch=='}' ||ch==',') {
                if(str=="") continue;
                int n = Integer.parseInt(str);
                str = "";
                if(map.containsKey(n)) {
                    map.put(n,map.get(n)+1);
                } else {
                    map.put(n,1);
                }
            }
        }
        for (int e : map.keySet()) {
            re_map.put(map.get(e),e);
        }

        answer = new int[map.size()];

        int k = map.size()-1;
        for (int e : re_map.values()) {
            answer[k--] = e;
        }

        return answer;
    }

    public static void main(String[] args) {
        for(int e : solution("{{20,111},{111}}")) {
            System.out.println(e);
        }
    }
}
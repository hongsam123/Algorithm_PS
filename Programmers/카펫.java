class Solution {
    public int[] solution(int brown, int yellow) {
        int[] answer = new int[2];
        
        int r = 1;
        int ansC = 0;
        boolean posi = false;
        while(true) {
            for(int c = r;c>=1;c--) {
                //check
                if(2*r+2*c==4+brown && r*c==yellow+brown) {
                    ansC = c;
                    posi = true;
                }
            }
            if(posi) break;
            r++;
        }
        
        answer[0] = r;
        answer[1] = ansC;
        
        return answer;
    }
}
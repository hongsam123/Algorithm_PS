class Solution {
    static int getSecond(String time) {
        int h = Integer.parseInt(time.substring(0, 2));
        int m = Integer.parseInt(time.substring(3, 5));
        int s = Integer.parseInt(time.substring(6, 8));

        return h*3600 + m*60 + s;
    }

    static String getString(int sec) {
        int h = sec / 3600;
        sec = sec % 3600;
        int m = sec / 60;
        sec = sec % 60;
        StringBuilder sb = new StringBuilder("");
        if(h<10) sb.append("0");
        sb.append(h+":");
        if(m<10) sb.append("0");
        sb.append(m + ":");
        if(sec<10) sb.append("0");
        sb.append(sec);

        return sb.toString();
    }

    static String solution(String play_time, String adv_time, String[] logs) {
        String answer = "2";

        int play_time_second = getSecond(play_time);
        int adv_time_second = getSecond(adv_time);

        if (adv_time_second == play_time_second) {
            answer = "00:00:00";
            return answer;
        }

        long[] playCnt = new long[play_time_second+1];

        //모든 시청 시간의 시작시간에 +1, 종료시간에-1
        for(int i=0;i<logs.length;i++) {
            playCnt[getSecond(logs[i].substring(0, 8))]++;
            playCnt[getSecond(logs[i].substring(9))]--;
        }

        //배열을 순회하면서 이전 배열값을 누적
        //=> 현재 시간에 동영상을 보고있는 사람의 수
        for(int i=1;i<playCnt.length;i++)
            playCnt[i] += playCnt[i-1];

        //다시한번 배열을 순회하면서 이전 배열 값 누적
        //=> 현재 시간까지 동영상을 시청한 총 재생시간 누적
        for(int i=1;i<playCnt.length;i++)
            playCnt[i] += playCnt[i-1];

        //반복문을 통해 (종료시간 - (시작시간-1))을 계산하면 해당 시간동안 재생된 트래픽 수
        //최대값이 나올때 마다 갱신
        int max_st_time = 0;
        long max_time = playCnt[adv_time_second - 1];
        for (int i = 0; i + adv_time_second <= play_time_second; i++) {
            if (max_time < playCnt[i+adv_time_second] - playCnt[i]) {
                max_time =  playCnt[i+adv_time_second] - playCnt[i];
                max_st_time = i + 1;
            }
        }
        answer = getString(max_st_time);

        return answer;
    }
    public static void main(String[] args) {
        String[] arr = {"01:20:15-01:45:14", "00:40:31-01:00:00", "00:25:50-00:48:29", "01:30:59-01:53:29", "01:37:44-02:02:30"};
        System.out.println(solution("02:03:55","00:14:15",arr));
    }
}

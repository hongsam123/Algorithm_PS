import java.util.*;

class Solution {
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        int answer = 0;
        
        Queue<Integer> q = new LinkedList<>();
        Queue<Integer> waitTruck = new LinkedList<>();
        
        //초기 다리 상태와 대기 트럭 상태
        for(int i=0;i<bridge_length;i++) {
            q.offer(0);
        }
        for(int cur:truck_weights){
            waitTruck.offer(cur);
        }
        
        int total = 0;
        while(!q.isEmpty()){
            total -= q.peek();
            q.poll();
            
            if(waitTruck.isEmpty()) {
                answer+=bridge_length;
                break;
            }else {
                if((total+waitTruck.peek())<=weight){
                    //다리에 트럭이 올라갈 수 있다면
                    q.add(waitTruck.peek());
                    total+=waitTruck.peek();
                    waitTruck.remove();
                }
                else {
                    q.add(0);
                }
            }
            answer++;
        }
        
        return answer;
    }
}
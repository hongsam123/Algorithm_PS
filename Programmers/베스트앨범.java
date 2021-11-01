import java.util.*;
class Solution {
    public int[] solution(String[] genres, int[] plays) {
        ArrayList<Integer> result = new ArrayList<>();
        
        HashMap<String,Integer> genre_count = new HashMap<>();

        for(int i=0;i<genres.length;i++){
            String g = genres[i];
            int p = plays[i];
            
            //장르별로 재생된 시간 구하기
            if(genre_count.containsKey(g)) {
                genre_count.put(g,genre_count.get(g)+p);
            }else {
                genre_count.put(g,p);
            }
        }
        List<Map.Entry<String,Integer>> list = new LinkedList<>(genre_count.entrySet());
    
        Collections.sort(list, new Comparator<Map.Entry<String,Integer>>() {
            @Override
            public int compare(Map.Entry<String,Integer> o1, Map.Entry<String,Integer> o2){
                //value(재생된 시간을 기준으로 내림차순)
                return o2.getValue() - o1.getValue();
            }
        });
        
        for(int i=0;i<list.size();i++) {
            //재생 시간 기준 내림차순 정렬된 장르를 순회
            String g = list.get(i).getKey();
            HashMap<Integer,Integer> index_play = new HashMap<>();
            
            //해당 장르라면 맵에 넣기
            for(int j=0;j<plays.length;j++) {
                int p = plays[j];
                if(genres[j].equals(g)){
                    index_play.put(j,p);
                }
            }
            
            List<Map.Entry<Integer,Integer>> l = new LinkedList<>(index_play.entrySet());
            Collections.sort(l, new Comparator<Map.Entry<Integer,Integer>>(){
                @Override
                public int compare(Map.Entry<Integer,Integer> o1, Map.Entry<Integer,Integer> o2){
                //value(재생시간)를 기준으로 내림차순, 값이 같다면 인덱스를 기준으로 오름차순
                if(o1.getValue() == o2.getValue()){
                    return o1.getKey()-o2.getKey();
                }else {
                    return o2.getValue() - o1.getValue();
                }
                }
            });
            
            if(l.size()>=2){
                for(int j=0;j<2;j++) {
                    result.add(l.get(j).getKey());
                }
            }else{
                result.add(l.get(0).getKey());
            }
        }
        
        int[] answer = new int[result.size()];
        for(int i=0;i<result.size();i++) {
            answer[i] = result.get(i);
        }
        
        return answer;
    }
}
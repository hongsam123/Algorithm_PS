#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    //문제 크기가 작기 때문에 모든 경우의 수를 검사하는 완전 탐색으로도 해결할 수 있다.
    int answer = 1e9+10;
    
    //외벽은 원형이다. 0번 지점을 거쳐가는 경로가 존재할 수 있기 때문에 단순한 1차원 배열로 외벽을 표현하기는 부족하므로 weak배열의 길이를 2배 늘려 사용한다
    
    //모든 k개의 외벽을 검사하는 것은 변형된 weak배열에서 임의의 연속된 k개의 정점을 방문하는 것과 동일!
    
    //길이를 2배로 늘린 새로운 weak배열 만들기
    int m = weak.size();
    vector<int> new_weak;
    for(int e : weak) {
        new_weak.push_back(e);
    }
    for(int e : weak) {
        new_weak.push_back(e+n);
    }
    
    //순열 계산을 위한 정렬
    sort(dist.begin(),dist.end());
    
    //모든 순열에 대한 탐색
    do{
        for(int i=0;i<m;i++) {
            int st = new_weak[i];       //검사 시작 지점
            int en = new_weak[i+m-1];   //검사 종료 예상 지점
            
            for(int j=0;j<dist.size();j++) {
                st += dist[j];
                if(st>=en) {
                    //모든 지점을 방문했을 경우 탈출
                    answer = min(answer,j+1);
                    break;
                }
                //다음 검사 시작 지점 구하기
                //마지막 검사한 지점보다 큰 new_weak 가장 작은 지점
                int nxt = upper_bound(new_weak.begin(),new_weak.end(),st) - new_weak.begin();
                st = new_weak[nxt];
            }
        }
    }while(next_permutation(dist.begin(),dist.end()));
    
    if(answer == 1e9+10) return -1;
    
    return answer;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cout<<solution(12,{1,5,6,10},{1,2,3,4});
	//cout<<solution(12,{1,3,4,9,10},{3,5,7});
	
	return 0;
}

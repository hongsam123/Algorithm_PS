#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    //���� ũ�Ⱑ �۱� ������ ��� ����� ���� �˻��ϴ� ���� Ž�����ε� �ذ��� �� �ִ�.
    int answer = 1e9+10;
    
    //�ܺ��� �����̴�. 0�� ������ ���İ��� ��ΰ� ������ �� �ֱ� ������ �ܼ��� 1���� �迭�� �ܺ��� ǥ���ϱ�� �����ϹǷ� weak�迭�� ���̸� 2�� �÷� ����Ѵ�
    
    //��� k���� �ܺ��� �˻��ϴ� ���� ������ weak�迭���� ������ ���ӵ� k���� ������ �湮�ϴ� �Ͱ� ����!
    
    //���̸� 2��� �ø� ���ο� weak�迭 �����
    int m = weak.size();
    vector<int> new_weak;
    for(int e : weak) {
        new_weak.push_back(e);
    }
    for(int e : weak) {
        new_weak.push_back(e+n);
    }
    
    //���� ����� ���� ����
    sort(dist.begin(),dist.end());
    
    //��� ������ ���� Ž��
    do{
        for(int i=0;i<m;i++) {
            int st = new_weak[i];       //�˻� ���� ����
            int en = new_weak[i+m-1];   //�˻� ���� ���� ����
            
            for(int j=0;j<dist.size();j++) {
                st += dist[j];
                if(st>=en) {
                    //��� ������ �湮���� ��� Ż��
                    answer = min(answer,j+1);
                    break;
                }
                //���� �˻� ���� ���� ���ϱ�
                //������ �˻��� �������� ū new_weak ���� ���� ����
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

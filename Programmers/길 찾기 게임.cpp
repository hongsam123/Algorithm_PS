#include <string>
#include <vector>
#include <algorithm>
#include <iostream> 
using namespace std;

struct Node {
    int idx;
    int x;
    int y;
    Node *Left;
    Node *Right;
};

bool cmp(Node a, Node b) {
    //y��ǥ�� �� ũ��, ���ٸ� x��ǥ�� ��������� ���� ��尡 �켱������ ���´�
    if(a.y>=b.y) {
        if(a.y==b.y) {
            if(a.x < b.x) {
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}

void Make_Binary_Tree(Node *Root, Node *Child) {
    //������ �Ǵ� ��� Root�� ���� �ڸ��� ã�� ��� Child�� ���ڷ� ������ ����Լ��� ���� Ʈ�� ����
    //��带 ������ �� �ִ� ������尡 ���� ������ ��͸� ����� ������ ��������. 
    if(Root->x > Child->x) {
        if(Root->Left == NULL) {
            Root->Left = Child;
            return;
        }
        Make_Binary_Tree(Root->Left,Child);
    }
    else {
        if(Root->Right == NULL) {
            Root -> Right = Child;
            return;
        }
        Make_Binary_Tree(Root->Right,Child);
    }
}

void preOrder(Node *Root, vector<int> &answer) {
    if(Root==NULL) return;
    answer.push_back(Root->idx);
    preOrder(Root->Left,answer);
    preOrder(Root->Right,answer);
}

void postOrder(Node *Root, vector<int> &answer) {
    if(Root==NULL) return;
    postOrder(Root->Left,answer);
    postOrder(Root->Right,answer);
    answer.push_back(Root->idx);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    
    vector<Node> Tree;
    
    //Node�� �����ϴ� Tree vector�� �� ��带 ���� 
    for(int i=0;i<nodeinfo.size();i++) {
        int x = nodeinfo[i][0];
        int y = nodeinfo[i][1];
        int idx = i+1;
        Tree.push_back({idx,x,y,NULL,NULL});
    }
    //������ ���� ���� root������ ��������� ���̰� �� ���� node�� �켱����,
    //���� �����϶��� x��ǥ�� �� ���� node�� �켱���� ����
    sort(Tree.begin(),Tree.end(),cmp);
    
    //��Ʈ���(�� ������ ���� �� �տ� �� �ִ�)
    Node *Root = &Tree[0];
    
    //Ʈ�������
    for(int i=1;i<Tree.size();i++) Make_Binary_Tree(Root,&Tree[i]);
    
    //������ȸ
    vector<int> preOrder_v;
    preOrder(Root,preOrder_v);
    
    //������ȸ
    vector<int> postOrder_v;
    postOrder(Root, postOrder_v);
    
    answer.push_back(preOrder_v);
    answer.push_back(postOrder_v);
    
    return answer;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	vector<vector<int>> ans = solution({{5,3},{11,5},{13,3},{3,5},{6,1},{1,3},{8,6},{7,2},{2,2}});
	
	for(auto e : ans) {
		for(int x : e){
			cout<<x<<" ";
		}
		cout<<"\n";
	}
	
	return 0;
}

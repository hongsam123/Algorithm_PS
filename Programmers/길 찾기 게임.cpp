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
    //y좌표가 더 크고, 같다면 x좌표가 상대적으로 작은 노드가 우선순위를 갖는다
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
    //기준이 되는 노드 Root와 현재 자리를 찾는 노드 Child를 인자로 가지는 재귀함수로 이진 트리 구현
    //노드를 삽입할 수 있는 리프노드가 나올 때까지 재귀를 사용해 밑으로 내려간다. 
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
    
    //Node를 저장하는 Tree vector에 각 노드를 저장 
    for(int i=0;i<nodeinfo.size();i++) {
        int x = nodeinfo[i][0];
        int y = nodeinfo[i][1];
        int idx = i+1;
        Tree.push_back({idx,x,y,NULL,NULL});
    }
    //정렬을 시켜 가장 root노드부터 상대적으로 높이가 더 높은 node를 우선으로,
    //같은 높이일때는 x좌표가 더 작은 node를 우선으로 정렬
    sort(Tree.begin(),Tree.end(),cmp);
    
    //루트노드(위 정렬을 통해 맨 앞에 와 있다)
    Node *Root = &Tree[0];
    
    //트리만들기
    for(int i=1;i<Tree.size();i++) Make_Binary_Tree(Root,&Tree[i]);
    
    //전위순회
    vector<int> preOrder_v;
    preOrder(Root,preOrder_v);
    
    //후위순회
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

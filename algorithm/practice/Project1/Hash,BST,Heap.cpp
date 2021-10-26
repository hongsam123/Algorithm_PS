////Hash
//해시 함수 : 임의의 길이의 데이터를 고정된 길이의 데이터로 매핑하는 함수
//예) 카드번호 16자리를 앞 4자리만 떼내어 사용하는 경우
//해시 테이블 : 해시 함수를 이용해 만든 테이블
//
//충돌(Collision) : 해시 함수에서 일어나는 두 입력값에 대해 출력값이 동일한 문제점
//
// - 충돌을 막기 위한 방법
//
//1. Open Addressing(개방 주소법)
//	충돌이 발생할 시 원소를 저장하는 인덱스를 바꾸는 충돌 회피 방법
//	- 해당 칸이 이미 차있을 경우 1칸씩 뛰는 것 : Linear probing
//	- 어떤 방식으로 뛰냐에 따라 Quadratic probing,Double hashing의 방식이 있다
//
//2. Chaining(체이닝)
//	해시테이블에서 각 인덱스가 원소 1개만을 담는 것이 아니라 Linked List 구조로 여러 원소를 담고 있는 방식
//	Linked List에 새로운 원소를 집어넣을 때 맨 뒤에 넣으면 이미 존재하는 노드의 갯수만큼 이동한 후 새로운 노드를 붙어야 하므로 맨 앞에 두면 O(1)에 삽입 가능
//
//해쉬에서 삽입, 삭제, 검색은 모두 O(1)이지만 충돌이 빈번히 발생할수록 실제 시간 복잡도는 나빠진다.
//데이터의 성격에 따라 테이블  의 크기를 크게 한다거나 적절한 해시함수를 사용하여 충돌이 최대한 발생하지 않도록 한다
//해시테이블을 직접 구현할 일은 별로 없고 stl에 이미 구현되어있는 이진 검색 테이블, unordered_set, unordered_map이 존재(but map, set이 낫다)
//
//#include<unordered_set>
//#include<unordered_map>
//#include<iostream>
//using namespace std;
//
//void hash_example() {
//	//unordered_set(해시)
//	unordered_set<int> s;
//	s.insert(-10); s.insert(5); s.insert(10);
//	s.insert(-10);
//	cout << s.erase(100) << "\n";
//	cout << s.erase(5) << "\n";
//	if (s.find(10) != s.end()) cout << "10 is in s\n";
//	else cout << "10 is not in s\n";
//	cout << s.size() << "\n";
//	cout << s.count(-10) << "\n";
//	for (auto e : s)cout << e << "\n";
//
//
//	//unordered_multiset(원소의 중복이 허용되는 해시)
//	unordered_multiset<int> ms;
//	ms.insert(-10); ms.insert(100); ms.insert(15);
//	ms.insert(-10); ms.insert(15);
//
//	cout << ms.size() << "\n";
//	for (auto e : ms) cout << e << "\n";
//	cout << ms.erase(15) << "\n";		//모든 15가 지워진다
//	cout << ms.erase(ms.find(15)) << "\n";	//하나만 지울수 있다
//	ms.insert(100);
//	cout << ms.count(100) << "\n";	//2
//
//	//unordered_map
//	unordered_map<string, int> m;
//	m["hi"] = 123;
//	m["bfd"] = 1000;
//	m["gogo"] = 165;
//	cout << m.size() << "\n";	//3
//	m["hi"] = -3;
//	if (m.find("hi") != m.end()) cout << "hi is in m\n";
//	else cout << "hi is not in m\n";
//	m.erase("gogo");
//	for (auto e : m)
//		cout << e.first << " " << e.second << "\n";
//}



////Binary Search Tree
//이진 검색 트리 : 특별한 성질을 만족하는 트리. 왼쪽 자식은 부모보다 작고 오른쪽 자식은 부모보다 값이 큰 이진 트리
//
//특정 노드를 삽입할 때 필요한 시간 : 해당 노드가 자기 자리를 찾아가기 위해 비교를 몇 번 해야 하는지(해당 노드의 높이가 얼마인지)에 비례
//검색,삭제 또한 삽입과 마찬가지로 시간 복잡도는 높이에 비례
//(단, 트리가 균형 트리에 가까운 경우 빠르게 동작하지만(약 O(logN)), 편향된 트리에 가까울 경우 비효율적으로 Linked List나 배열을 쓰는것과 비슷한 시간(O(N)인데 공간은 더 차지할 수있음)
//(그렇기에 트리가 편향되어 있다면 트리를 쓰는 이유가 없다)
//
//이진 검색 트리가 편향되지 않게 삽입, 삭제를 개선한 트리가 AVL트리, Red Black트리 (불균형이 발생할 때 회전을 시키는 방식으로 구현)
//
////STL
// - STL set : 값들을 이진 검색 트리로 저장하는 자료구조. 단, 중복 원소는 허용하지 않음
// - STL map : (key, value)를 key에 대한 이진 검색 트리로 저장하는 자료구조. 단, 중복 key는 허용하지 않음
// - STL multiset : 값들을 이진 검색 트리로 저장하는 자료구조, 중복 원소가 허용됨
// - STL multimap : (key, value)를 key에 대한 이진 검색 트리로 저장하는 자료구조, 중복 key가 허용됨
//(이 때 이진 검색 트리의 구현은 자가 구현 트리로 되어있어 트리가 편향되지 않음을 보장)

////set, multiset 예제
//#include<iostream>
//#include<set>
//using namespace std;
//
//int main()
//{
//	set<int> s;
//	s.insert(3);	// s = {3}
//	s.insert({ 1,5,7 });	// s = {1,3,5,7}
//	if (s.find(6) == s.end())
//		cout << "6 not in s\n";
//	else
//		cout << "6 in s\n";
//	cout << s.size() << "\n";
//	s.erase(2);	// 아무일도 일어나지 않는다
//	s.erase(1);	// s = {3,5,7};
//	s.insert(3);	// set은 중복 원소가 허용되지 않는다.
//	for (auto e : s)
//		cout << e << " ";
//	cout << "\n";
//	s.clear();
//	cout << s.size() << "\n";
//
//	multiset<int> ms;
//	ms.insert(1);
//	ms.insert(2);
//	ms.insert(1);
//	for (auto e : ms)
//		cout << e << " ";
//	cout << "\n";
//	cout << ms.count(1);
//
//	return 0;
//}

////map, multimap 예제
//#include<iostream>
//#include<map>
//using namespace std;
//
//int main()
//{
//	map<string, int> m;	//key : string, value : int
//	m["kim"] = 2342;
//	m["apple"] = 323;
//	m["banana"] = 5252;
//	for (auto e : m)
//		cout << e.first << " " << e.second << "\n";
//	cout << m.size() << "\n";
//	if (m.find("apple") == m.end())
//		cout << "key apple not in m\n";
//	else
//		cout << "key apple int m\n";
//	m["apple"] = 1111;
//	cout << m.size() << " " << m["apple"] << "\n";
//	m.erase("kim");
//	m.clear();
//	
//	multimap<int, string> mm;
//	//multimap은 동일한 key가 여러 개일 수 있으니 []연산자로 원소에 접근할 수 없다.
//	mm.insert({ 1,"apple" });
//	mm.insert({ 1,"hi" });
//	mm.insert({ -10,"zcx" });
//	for (auto e : mm)
//		cout << e.first << " " << e.second << "\n";
//
//	return 0;
//}

////Heap
//최대값 혹은 최솟값을 빠르게 찾아내기 위한 이진트리
//최소 힙인 경우 부모가 자식보다 작고, 최대 힙인 경우 부모가 자식보다 크다.이때 루트가 최소값 혹은 최대값
//(왼쪽 오른쪽은 상관 없음)
//
//최소 힙에서는 원소의 삽입, 최솟값 확인, 최솟값 삭제의 기능 제공
//최대 힙에서는 원소의 삽입, 최대값 확인, 최대값 삭제의 기능 제공
//(최소 혹은 최대가 아닌 값의 존재 여부 확인 또는 원소 제거 불가능)
//
//- 삽입 : 원소를 트리 상의 다음 공간에 추가하고, 이후 힙의 성질을 만족하게끔 서로 자리를 바꾸는 식으로 구현
//(트리 상의 다음 공간은 높이가 작은 곳부터, 높이가 같다면 왼쪽부터 채워나가므로 균형트리가 보장된다.)
//삽입시 아무리 비교를 많이 해도 최대 높이만큼만 올라가면 삽입이 가능하고 힙이 균형 트리이기 때문에 시간복잡도 O(lon N) 보장
//- 최솟값 확인 : 루트에 적힌 원소
//- 최소값 삭제 : 루트를 바로 지우면 트리 구조가 깨진다.
//루트 값(최소값)을 트리 구조상 가장 마지막 위치의 값과 바꾸고 제거.
//힙의 조건을 만족하도록 위치를 바꿔가며 해결(자식이 두개인 경우에는 둘 자식 중 더 작은 자식과 교환)
//최대 높이 만큼만 내려가면 삭제가 가능, 균형트리이므로 O(logN)이 보장된다
//
//트리의 구현
//트리 구조는 node를 만들어 구현하는것이 정석적이지만 균형트리가 보장될 경우에는 각 원소를 배열에 대응할 수 있다.
//x의 왼쪽, 오른쪽 자식 인덱스 : 2x, 2x + 1
//x의 부모 : x / 2
//
//boj1927 최소 힙
//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//int heap[100005];
//int sz = 0;	//heap size
//
//void add(int x)
//{
//	sz++;
//	heap[sz] = x;
//	int idx = sz;
//	while (idx != 1)
//	{
//		int par = idx / 2;
//		if (heap[par] < heap[idx]) break;
//		swap(heap[par], heap[idx]);
//		idx = par;
//	}
//}
//
//int top()
//{
//	if (sz == 0) return 0;
//	return heap[1];
//}
//
//void pop()
//{
//	if (sz == 0) return;
//	swap(heap[1], heap[sz]);
//	sz--;
//	int idx = 1;
//	while (2 * idx <= sz)	//2*idx가 sz보다 크면 idx가 leaf노드
//	{
//		int min_child;
//		if (heap[idx * 2]<heap[idx * 2 + 1] or 2 * idx + 1>sz)	//왼쪽 자식값이 더 작거나 왼쪽 자식밖에 없는 경우
//			min_child = 2 * idx;	
//		else
//			min_child = 2 * idx + 1;
//		if (heap[min_child] > heap[idx]) break;
//		swap(heap[min_child], heap[idx]);
//		idx = min_child;
//	}
//}
//
////힙 STL
//==> priority_queue(기본적으로 최대힙)
//
//(힙에서 할 수 있는 것은 균형 이진 트리에서도 할 수 있고 시간복잡도도 O(log N)으로 동일
//	그러나 힙이 균형 이진트리보다 수행 속도가 빠르고, 구현도 쉽고, 공간도 적게 차지하므로 최소 혹은 최대값의 확인/삭제만 필요할 때는 힙을 사용한다)
//
//#include<queue>
//using namespace std;
//
//priority_queue<int> pq;	//최대 힙
//priority_queue<int, vector<int>, greater<int>> PQ;	//최소 힙




//boj7785 회사에 있는 사람
//boj17219 비밀번호 찾기
//boj9375 패션왕 신해빈
//boj11286 절댓값 힙
//프로그래머스 카카오 2021채용연계형 인턴십 표 편집
//boj13414 수강신청
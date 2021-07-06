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
//데이터의 성격에 따라 테이블의 크기를 크게 한다거나 적절한 해시함수를 사용하여 충돌이 최대한 발생하지 않도록 한다
//해시테이블을 직접 구현할 일은 별로 없고 stl에 이미 구현되어있는 이진 검색 테이블, unordered_set, unordered_map이 존재(but map, set이 낫다)


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

//boj7785 회사에 있는 사람
//boj17219 비밀번호 찾기
//boj9375 패션왕 신해빈
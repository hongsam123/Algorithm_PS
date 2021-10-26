////Hash
//�ؽ� �Լ� : ������ ������ �����͸� ������ ������ �����ͷ� �����ϴ� �Լ�
//��) ī���ȣ 16�ڸ��� �� 4�ڸ��� ������ ����ϴ� ���
//�ؽ� ���̺� : �ؽ� �Լ��� �̿��� ���� ���̺�
//
//�浹(Collision) : �ؽ� �Լ����� �Ͼ�� �� �Է°��� ���� ��°��� ������ ������
//
// - �浹�� ���� ���� ���
//
//1. Open Addressing(���� �ּҹ�)
//	�浹�� �߻��� �� ���Ҹ� �����ϴ� �ε����� �ٲٴ� �浹 ȸ�� ���
//	- �ش� ĭ�� �̹� ������ ��� 1ĭ�� �ٴ� �� : Linear probing
//	- � ������� �ٳĿ� ���� Quadratic probing,Double hashing�� ����� �ִ�
//
//2. Chaining(ü�̴�)
//	�ؽ����̺��� �� �ε����� ���� 1������ ��� ���� �ƴ϶� Linked List ������ ���� ���Ҹ� ��� �ִ� ���
//	Linked List�� ���ο� ���Ҹ� ������� �� �� �ڿ� ������ �̹� �����ϴ� ����� ������ŭ �̵��� �� ���ο� ��带 �پ�� �ϹǷ� �� �տ� �θ� O(1)�� ���� ����
//
//�ؽ����� ����, ����, �˻��� ��� O(1)������ �浹�� ����� �߻��Ҽ��� ���� �ð� ���⵵�� ��������.
//�������� ���ݿ� ���� ���̺�  �� ũ�⸦ ũ�� �Ѵٰų� ������ �ؽ��Լ��� ����Ͽ� �浹�� �ִ��� �߻����� �ʵ��� �Ѵ�
//�ؽ����̺��� ���� ������ ���� ���� ���� stl�� �̹� �����Ǿ��ִ� ���� �˻� ���̺�, unordered_set, unordered_map�� ����(but map, set�� ����)
//
//#include<unordered_set>
//#include<unordered_map>
//#include<iostream>
//using namespace std;
//
//void hash_example() {
//	//unordered_set(�ؽ�)
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
//	//unordered_multiset(������ �ߺ��� ���Ǵ� �ؽ�)
//	unordered_multiset<int> ms;
//	ms.insert(-10); ms.insert(100); ms.insert(15);
//	ms.insert(-10); ms.insert(15);
//
//	cout << ms.size() << "\n";
//	for (auto e : ms) cout << e << "\n";
//	cout << ms.erase(15) << "\n";		//��� 15�� ��������
//	cout << ms.erase(ms.find(15)) << "\n";	//�ϳ��� ����� �ִ�
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
//���� �˻� Ʈ�� : Ư���� ������ �����ϴ� Ʈ��. ���� �ڽ��� �θ𺸴� �۰� ������ �ڽ��� �θ𺸴� ���� ū ���� Ʈ��
//
//Ư�� ��带 ������ �� �ʿ��� �ð� : �ش� ��尡 �ڱ� �ڸ��� ã�ư��� ���� �񱳸� �� �� �ؾ� �ϴ���(�ش� ����� ���̰� ������)�� ���
//�˻�,���� ���� ���԰� ���������� �ð� ���⵵�� ���̿� ���
//(��, Ʈ���� ���� Ʈ���� ����� ��� ������ ����������(�� O(logN)), ����� Ʈ���� ����� ��� ��ȿ�������� Linked List�� �迭�� ���°Ͱ� ����� �ð�(O(N)�ε� ������ �� ������ ������)
//(�׷��⿡ Ʈ���� ����Ǿ� �ִٸ� Ʈ���� ���� ������ ����)
//
//���� �˻� Ʈ���� ������� �ʰ� ����, ������ ������ Ʈ���� AVLƮ��, Red BlackƮ�� (�ұ����� �߻��� �� ȸ���� ��Ű�� ������� ����)
//
////STL
// - STL set : ������ ���� �˻� Ʈ���� �����ϴ� �ڷᱸ��. ��, �ߺ� ���Ҵ� ������� ����
// - STL map : (key, value)�� key�� ���� ���� �˻� Ʈ���� �����ϴ� �ڷᱸ��. ��, �ߺ� key�� ������� ����
// - STL multiset : ������ ���� �˻� Ʈ���� �����ϴ� �ڷᱸ��, �ߺ� ���Ұ� ����
// - STL multimap : (key, value)�� key�� ���� ���� �˻� Ʈ���� �����ϴ� �ڷᱸ��, �ߺ� key�� ����
//(�� �� ���� �˻� Ʈ���� ������ �ڰ� ���� Ʈ���� �Ǿ��־� Ʈ���� ������� ������ ����)

////set, multiset ����
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
//	s.erase(2);	// �ƹ��ϵ� �Ͼ�� �ʴ´�
//	s.erase(1);	// s = {3,5,7};
//	s.insert(3);	// set�� �ߺ� ���Ұ� ������ �ʴ´�.
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

////map, multimap ����
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
//	//multimap�� ������ key�� ���� ���� �� ������ []�����ڷ� ���ҿ� ������ �� ����.
//	mm.insert({ 1,"apple" });
//	mm.insert({ 1,"hi" });
//	mm.insert({ -10,"zcx" });
//	for (auto e : mm)
//		cout << e.first << " " << e.second << "\n";
//
//	return 0;
//}

////Heap
//�ִ밪 Ȥ�� �ּڰ��� ������ ã�Ƴ��� ���� ����Ʈ��
//�ּ� ���� ��� �θ� �ڽĺ��� �۰�, �ִ� ���� ��� �θ� �ڽĺ��� ũ��.�̶� ��Ʈ�� �ּҰ� Ȥ�� �ִ밪
//(���� �������� ��� ����)
//
//�ּ� �������� ������ ����, �ּڰ� Ȯ��, �ּڰ� ������ ��� ����
//�ִ� �������� ������ ����, �ִ밪 Ȯ��, �ִ밪 ������ ��� ����
//(�ּ� Ȥ�� �ִ밡 �ƴ� ���� ���� ���� Ȯ�� �Ǵ� ���� ���� �Ұ���)
//
//- ���� : ���Ҹ� Ʈ�� ���� ���� ������ �߰��ϰ�, ���� ���� ������ �����ϰԲ� ���� �ڸ��� �ٲٴ� ������ ����
//(Ʈ�� ���� ���� ������ ���̰� ���� ������, ���̰� ���ٸ� ���ʺ��� ä�������Ƿ� ����Ʈ���� ����ȴ�.)
//���Խ� �ƹ��� �񱳸� ���� �ص� �ִ� ���̸�ŭ�� �ö󰡸� ������ �����ϰ� ���� ���� Ʈ���̱� ������ �ð����⵵ O(lon N) ����
//- �ּڰ� Ȯ�� : ��Ʈ�� ���� ����
//- �ּҰ� ���� : ��Ʈ�� �ٷ� ����� Ʈ�� ������ ������.
//��Ʈ ��(�ּҰ�)�� Ʈ�� ������ ���� ������ ��ġ�� ���� �ٲٰ� ����.
//���� ������ �����ϵ��� ��ġ�� �ٲ㰡�� �ذ�(�ڽ��� �ΰ��� ��쿡�� �� �ڽ� �� �� ���� �ڽİ� ��ȯ)
//�ִ� ���� ��ŭ�� �������� ������ ����, ����Ʈ���̹Ƿ� O(logN)�� ����ȴ�
//
//Ʈ���� ����
//Ʈ�� ������ node�� ����� �����ϴ°��� ������������ ����Ʈ���� ����� ��쿡�� �� ���Ҹ� �迭�� ������ �� �ִ�.
//x�� ����, ������ �ڽ� �ε��� : 2x, 2x + 1
//x�� �θ� : x / 2
//
//boj1927 �ּ� ��
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
//	while (2 * idx <= sz)	//2*idx�� sz���� ũ�� idx�� leaf���
//	{
//		int min_child;
//		if (heap[idx * 2]<heap[idx * 2 + 1] or 2 * idx + 1>sz)	//���� �ڽİ��� �� �۰ų� ���� �ڽĹۿ� ���� ���
//			min_child = 2 * idx;	
//		else
//			min_child = 2 * idx + 1;
//		if (heap[min_child] > heap[idx]) break;
//		swap(heap[min_child], heap[idx]);
//		idx = min_child;
//	}
//}
//
////�� STL
//==> priority_queue(�⺻������ �ִ���)
//
//(������ �� �� �ִ� ���� ���� ���� Ʈ�������� �� �� �ְ� �ð����⵵�� O(log N)���� ����
//	�׷��� ���� ���� ����Ʈ������ ���� �ӵ��� ������, ������ ����, ������ ���� �����ϹǷ� �ּ� Ȥ�� �ִ밪�� Ȯ��/������ �ʿ��� ���� ���� ����Ѵ�)
//
//#include<queue>
//using namespace std;
//
//priority_queue<int> pq;	//�ִ� ��
//priority_queue<int, vector<int>, greater<int>> PQ;	//�ּ� ��




//boj7785 ȸ�翡 �ִ� ���
//boj17219 ��й�ȣ ã��
//boj9375 �мǿ� ���غ�
//boj11286 ���� ��
//���α׷��ӽ� īī�� 2021ä�뿬���� ���Ͻ� ǥ ����
//boj13414 ������û
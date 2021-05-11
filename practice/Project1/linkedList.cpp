//#include<iostream>
//#include<algorithm>
//#include <list>
//#include<vector>
//using namespace std;
//
//const int MX = 5001;
//int dat[MX], pre[MX], nxt[MX];
//int unused = 1;
//
//void traverse()
//{
//	int cur = nxt[0];
//	while (cur != -1)
//	{
//		cout << dat[cur] << " ";
//		cur = nxt[cur];
//	}
//	cout << "\n\n";
//}
//
//void insert(int addr, int num) {
//	dat[unused] = num;
//	pre[unused] = addr;
//	nxt[unused] = nxt[addr];
//	
//	if (nxt[addr] != -1) pre[nxt[addr]] = unused;
//	nxt[addr] = unused;
//	unused++;
//}
//
//void erase(int addr) {
//	nxt[pre[addr]] = nxt[addr];
//	if(nxt[addr] != -1) pre[nxt[addr]] = pre[addr];
//}
//
//void insert_test() {
//	cout << "****** insert_test *****\n";
//	insert(0, 10); // 10(address=1)
//	traverse();
//	insert(0, 30); // 30(address=2) 10
//	traverse();
//	insert(2, 40); // 30 40(address=3) 10
//	traverse();
//	insert(1, 20); // 30 40 10 20(address=4)
//	traverse();
//	insert(4, 70); // 30 40 10 20 70(address=5)
//	traverse();
//}
//
//void erase_test() {
//	cout << "****** erase_test *****\n";
//	erase(1); // 30 40 20 70
//	traverse();
//	erase(2); // 40 20 70
//	traverse();
//	erase(4); // 40 70
//	traverse();
//	erase(5); // 40
//	traverse();
//}
//
//int main(void)
//{
//	fill(pre, pre + MX, -1);
//	fill(nxt, nxt + MX, -1);
//	insert_test();
//	erase_test();
//}

//int main(void)
//{
//	list<int> L = { 1,2 };
//	list<int>::iterator t = L.begin();	//t�� 1�� ����Ű�� ��
//	//auto t = L.begin(); �� ����
//	L.push_front(10);	//10,1,2
//	cout << *t << '\n';	//t�� ����Ű�� �� 1���
//	L.push_back(5);		//10,1,2,5
//	L.insert(t, 6);		//t�� ����Ű�� �� �տ� 6�� ���� 10,6,1,2,5
//	t++;				//t�� ��ĭ ������ ����, ���� ����Ű�� �� 2
//	t = L.erase(t);		//t�� ����Ű�� ���� ����, �� ���� ������ 5�� ��ġ ��ȯ
//						//10,6,1,5
//	cout << *t << '\n';
//	for (auto i : L) cout << i<<' ';
//	cout << '\n';
//
//	for (list<int>::iterator it = L.begin(); it != L.end(); it++)
//		cout << *it << ' ';
//
//	return 0;
//}

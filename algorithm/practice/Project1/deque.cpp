//#include<iostream>
//using namespace std;
//
//const int MX = 1000005;
//int dat[2 * MX + 1];
//int head = MX, tail = MX;
//
//void push_front(int x) {
//	dat[--head] = x;
//}
//
//void push_back(int x) {
//	dat[tail++] = x;
//}
//
//void pop_front() {
//	head++;
//}
//
//void pop_back() {
//	tail--;
//}
//
//int front() {
//	return dat[head];
//}
//
//int back() {
//	return dat[tail - 1];
//}
//
//void test() {
//	push_back(30); // 30
//	cout << front() << '\n'; // 30
//	cout << back() << '\n'; // 30
//	push_front(25); // 25 30
//	push_back(12); // 25 30 12
//	cout << back() << '\n'; // 12
//	push_back(62); // 25 30 12 62
//	pop_front(); // 30 12 62
//	cout << front() << '\n'; // 30
//	pop_front(); // 12 62
//	cout << back() << '\n'; // 62
//}
//
//int main(void) {
//	test();
//}

//#include<iostream>
//#include<deque>
//using namespace std;
//
//int main(void)
//{
//	deque<int> dq;
//	dq.push_front(10);
//	dq.push_back(50);
//	dq.push_front(24);
//	for (auto x : dq)
//		cout << x<<' ';
//	cout << '\n';
//
//	cout << dq.size() << '\n';
//	if (dq.empty()) cout << "deque is empty\n";
//	else cout << "deque is not empty\n";
//	dq.pop_front();
//	dq.pop_back();
//	cout << dq.back() << '\n';
//
//	dq.push_back(72);
//	cout << dq.front() << '\n';
//	dq.push_back(12);
//	dq[2] = 17;
//	dq.insert(dq.begin() + 1, 33);
//	dq.insert(dq.begin() + 4, 60);
//	
//	for (auto x : dq) cout << x << ' ';
//	cout << "\n";
//
//	dq.erase(dq.begin() + 3);
//	cout << dq[3] << '\n';
//	dq.clear();
//	
//}

//boj10866 덱
//boj1021 회전하는 큐
//boj5430 AC

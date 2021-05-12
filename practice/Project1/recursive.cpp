//재귀 문제==>> 절차지향적 사고를 버리고 귀납적으로만 생각! 
//1. 함수의 정의
//2. base condition
//3. 재귀 식

//#include<iostream>
//using namespace std;
////int sum;
//
//void func1(int num)
//{
//	/*if (num >= 1)
//	{
//		cout << num << " ";
//		func1(num - 1);
//	}	*/
//	if (num == 0) return;
//	//base condition을 잡고
//	cout << num << " ";
//	//k번째 연산을 토대로
//	func1(num-1);
//	//k+1번째 연산을 수행
//}
//
//int  func2(int num)
//{
//	/*sum += num;
//	if (num > 1)
//	{
//		func2(num - 1);
//	}
//	else
//		return 1;*/
//	if (num == 0) return 0;
//	//base condition을 잡고
//	return num + func2(num - 1);
//	//k번째까지 계산을 했다면 k+1번째 계산도 수행할 수 있음
//}
//
//int main(void)
//{
//	int n;
//	cin >> n;
//	func1(n);
//	cout << "\n";
//	//func2(n);
//	//cout << sum;
//	cout << func2(n);
//
//	return 0;
//}
//boj1629 곱셈
//boj11729 하노이 탑 이동 순서
//boj1074 Z
//boj17478 재귀함수가 뭔가요
//boj2447 별찍기10
//boj2448 별찍기11
//boj1992 쿼드트리
//boj1780 종이의 개수
//boj2630 색종이 만들기
//boj16505 별


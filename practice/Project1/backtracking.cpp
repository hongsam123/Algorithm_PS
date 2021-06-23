////next_permutation
//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//int main(void)
//{
//	int a[3] = { 1,1,3 };
//	//next_permutation을 이용한 순열
//	//
//	//nest_permutation은 현재의 수열을 사전순으로 생각했을 때 
//	//다음 수열로 만들고 true를 return한다
//	//만약 현재의 수열이 사전순으로 생각했을 때 제일
//	//마지막 수열이라면 false를 return
//	do {
//		for (int i = 0; i < 3; i++)
//		{
//			cout << a[i];
//		}
//		cout << "\n";
//	} while (next_permutation(a, a + 3));
//
//	cout << "\n";
//
//	//next_permutation을 이용한 조합
//	int b[4] = { 0,0,1,1 };
//	do {
//		for (int i = 0; i < 4; i++)
//		{
//			if (b[i] == 0)
//				cout << i + 1;
//		}
//		cout << "\n";
//	} while (next_permutation(b, b + 4));
//	//만약 5개중에 3개의 조합을 구한다면
//	//a[5] = {0,0,0,1,1}의 배열로 구할 수 있다
//
//	return 0;
//}

//boj15649 N과 M(1)
//boj15650 N과 M(2)
//boj15651 N과 M(3)
//boj15652 N과 M(4)
//boj15654 N과 M(5)
//boj15655 N과 M(6) (next_permutation)
//boj12101 1,2,3 더하기 2
//boj9663 N-Queen
//boj1182 부분수열의 합
// (다른풀이)
// 각 수를 더할지 말지를 고려하며 모든 부분수열의 합 상태공간 트리를 그린다고 생각
// 시간 복잡도는 O(n^2) 
//boj18428 감시 피하기
//boj15656 N과 M(7)
//boj6603 로또
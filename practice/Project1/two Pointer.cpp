////투 포인터 = 배열에서 원래 이중 for문으로 O(N^2)에 처리되는
//작업을 2개포인터의 움직임으로 O(N)에 해결하는 알고리즘
//
//(여기서 포인터는 커서)
//투포인터 문제가 이분탐색으로 풀리거나, 그 반대의 경우도 종종 있다


//boj2230 수 고르기 ( 이중 for문으로 시간초과 나는 문제)
//					 정렬을 하고 투 포인터를 사용하여
//					 두 포인터를 증가시키면서 차이가 m보다 큰지 확인하고 
//					 크다면 최소값을 갱신한다 
//					 st가 끝에 도달하거나 en이 범위를 넘어가면 종료
//					 시간 복잡도는 O(N)
//boj1806 부분합
//boj1644 소수의 연속합
//boj22862 가장 긴 짝수 연속한 부분 수열(large)
#include<iostream>
#include<algorithm>
using namespace std;

int n, k;
int arr[1000002];
int ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	
	int st = 0;
	int en = 0;
	int sum = 0;

	while (1) {
		while()
	}

	cout << ans;

	return 0;
}
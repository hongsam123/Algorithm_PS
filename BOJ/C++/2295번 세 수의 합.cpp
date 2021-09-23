#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n;
int arr[1002];
vector<int> two;
//arr에서 두 원소의 합을 다 묶어놓은 배열
//two[m] + arr[k] = a[l]을 만족하는 a[l] 중에서 최대값
//==> O(N^2lgN)풀이 : k,l 2중 for문, arr[l]-arr[k]가 배열 two에 있는지 이분탐색

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			two.push_back(arr[i] + arr[j]);
		}
	}

	sort(two.begin(), two.end());

	for (int i = n - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (binary_search(two.begin(), two.end(), arr[i] - arr[j])) {
				cout<<arr[i];
				return 0;
			}
		}
	}

	return 0;
}

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<int> arr;
vector<int> ans;
int min_ans = 2147483647;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr.push_back(x);
	}

	for (int i = 0; i < n; i++) {
		int num = arr[i];
		int target = num * -1;
		int x1 = num;
		int x2 = num;

		if (lower_bound(arr.begin(), arr.end(), target) == arr.end()) {
			x1 = arr[n-1];
		}
		else if(lower_bound(arr.begin(), arr.end(), target) == arr.begin()){
			x1 = arr[0];
		}
		else {
			x1 = *(lower_bound(arr.begin(), arr.end(), target) - 1);
			x2 = *lower_bound(arr.begin(), arr.end(), target);
		}
		
		if (x1!=num && min_ans > abs(num + x1)) {

			min_ans = abs(num + x1);
			ans.clear();
			ans.push_back(num);
			ans.push_back(x1);
		}
		
		if (x2 != num) {
			if (min_ans > abs(num + x2)) {
				min_ans = abs(num + x2);
				ans.clear();
				ans.push_back(num);
				ans.push_back(x2);
			}
		}
	}
	
	sort(ans.begin(), ans.end());

	for (int e : ans)
		cout << e << " ";

	return 0;
}

//���ĵ� �迭�� �̺�Ž������ �������� ������ �����Ǵ� ���� ����/������ �ε����� ���̰� �ش� �迭 ���� target�� ���� Ƚ��
#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
int arr[500002];

int lower_idx(int target)
{
	int st = 0;
	int en = n;
	while (st < en)
	{
		int mid = (st + en) / 2;
		if (arr[mid] >= target) en = mid;
		else st = mid+1;
	}
	return st;
}

int upper_idx(int target)
{
	int st = 0;
	int en = n;
	while (st < en)
	{
		int mid = (st + en) / 2;
		if (arr[mid] <= target) st = mid + 1;
		else en = mid;
	}
	return st;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);

	cin >> m;
	int target;
	while (m--)
	{
		cin >> target;
		cout << upper_idx(target) - lower_idx(target) << " ";
	}

	return 0;
}

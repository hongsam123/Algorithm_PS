#include<iostream>
#include<algorithm>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
    cin.tie(NULL);
	
	int n,target;
	cin>>n>>target;
	
	int arr[n]={0};
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	sort(arr,arr+n);
	
	cout<<arr[target-1];
	
	return 0;
}

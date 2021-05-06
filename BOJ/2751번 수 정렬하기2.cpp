#include<iostream>
#include<algorithm>
#define endl '\n'		//endl보다  \n이 시간을 적게 먹는다 
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//입력시 시간을 적게 먹는다.
	
	int n;
	cin>>n;
	
	int arr[n] = {0};
	
	for(int i=0;i<n;i++)
		cin>>arr[i];
	
	sort(arr,arr+n);
	
	for(int i=0;i<n;i++)
		cout<<arr[i]<<endl;
		
	return 0;
}

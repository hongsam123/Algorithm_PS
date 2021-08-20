#include<iostream>
#include<algorithm>
#define endl '\n'
using namespace std;

int main(void)
{
	int arr[4];
	
	for(int i=0;i<4;i++)
		cin>>arr[i];
	
	sort(arr,arr+4);
	
	int n1 = min(arr[0],arr[1]);
	int n2 = min(arr[2],arr[3]);
	
	cout<<n1*n2;
	
	return 0;
}

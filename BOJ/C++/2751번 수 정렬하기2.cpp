#include<iostream>
#include<algorithm>
#define endl '\n'		//endl����  \n�� �ð��� ���� �Դ´� 
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//�Է½� �ð��� ���� �Դ´�.
	
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

#include<iostream>
using namespace std;

int arr[41];

int fibonacci(int n)
{
	if(arr[n]>0){
		return arr[n];
	}else if(n==0){
		return 0;
	} else if(n==1){
		return 1;
	} else{
		return arr[n] =  fibonacci(n-1) + fibonacci(n-2);
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,num;
	
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		cin>>num;
		fibonacci(num);
		if(num==0){
			cout<<"1 0"<<"\n";
		}else if(num==1){
			cout<<"0 1"<<"\n";
		}else{
			cout<<fibonacci(num-1)<<" "<<fibonacci(num)<<"\n";
		}
	}
	
	return 0;
}

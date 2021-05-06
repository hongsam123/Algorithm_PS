#include<iostream>
#include<algorithm>
using namespace std;

int main(void)
{
	int n,a,b;
	cin>>n>>a>>b;
	
	int count=0;
	
	do{
		count++;
		if(min(a,b)%2 && (min(a,b)+1 == max(a,b))){
			cout<<count;
			return 0;
		}
		if(a%2)
			a = a/2+1;
		else
			a = a/2;
		
		if(b%2)
			b = b/2+1;
		else
			b = b/2;
		
		if(n%2)
			n = n/2+1;
		else 
			n = n/2;		
	}while(n>1);
	cout<<-1;
	return 0;
}

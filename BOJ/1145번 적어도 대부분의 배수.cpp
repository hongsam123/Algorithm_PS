#include<iostream>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int arr[5];
	
	for(int i=0;i<5;i++)
		cin>>arr[i];
	
	int n = 1;
	while(1)
	{
		int count=0;
		for(int i=0;i<5;i++)
			if(n%arr[i]==0 && n>=arr[i])
				count++;
		if(count>=3)
			break;
		n++;
	}
	cout<<n;
	
	return 0;
}

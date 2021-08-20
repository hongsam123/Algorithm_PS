#include<iostream>
#include<algorithm>
using namespace std;

int n,arr[12];
int maxtotal = -1000000000,mintotal = 1000000000;

void cal(int total,int index,int ad,int su,int mu,int di)
{
	if(index ==n)
	{
		maxtotal = max(maxtotal,total);
		mintotal = min(mintotal,total);
	}
	
	if(ad>0)
		cal(total+arr[index],index+1,ad-1,su,mu,di);
	if(su>0)
		cal(total-arr[index],index+1,ad,su-1,mu,di);
	if(mu>0)
		cal(total*arr[index],index+1,ad,su,mu-1,di);
	if(di>0)
		cal(total/arr[index],index+1,ad,su,mu,di-1);
		
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	int add,sub,mul,div;
	cin>>add>>sub>>mul>>div;
	
	cal(arr[0],1,add,sub,mul,div);
	
	cout<<maxtotal<<"\n"<<mintotal<<"\n";
	
	return 0;
}

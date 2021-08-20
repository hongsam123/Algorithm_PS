#include<iostream>
#include<utility>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	pair<int,int> p1;
	pair<int,int> p2;
	
	cin>>p1.first>>p1.second>>p2.first>>p2.second;
	pair<int,int> p3;
	
	p3.first = (p1.first*p2.second)+(p1.second*p2.first);
	p3.second = p1.second*p2.second;
	
	int n1 = max(p3.first,p3.second);
	int n2 = min(p3.first,p3.second);
	int c;
	
	while(1)
	{
		c = n1%n2;
		n1 = n2;
		n2 = c;
		if(n2==0) break;
	}
	
	cout<<p3.first/n1<<" "<<p3.second/n1;
	
	return 0;
}

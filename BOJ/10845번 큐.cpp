#include<iostream>
#include<string>
#include<queue>
using namespace std;

int main(void){
	int n,num;
	cin>>n;
	
	queue<int> que;
	string input;
	
	for(int i=0;i<n;i++)
	{
		cin>>input;
		if(input=="push")
		{
			cin>>num;
			que.push(num);
		}
		else if(input=="pop")
		{
			if(que.empty())
				cout<<-1<<endl;
			else 
			{
				cout<<que.front()<<endl;
				que.pop();
			}
		}
		else if(input=="size")
		{
			cout<<que.size()<<endl;
		}
		else if(input=="empty")
		{
			if(que.empty())
				cout<<1<<endl;
			else
				cout<<0<<endl;
		}
		else if(input=="front")
		{
			if(que.empty())
				cout<<-1<<endl;
			else 
			{
				cout<<que.front()<<endl;
			}
		}
		else
		{
			if(que.empty())
				cout<<-1<<endl;
			else 
			{
				cout<<que.back()<<endl;
			}
		}
	}
	
	return 0;
}

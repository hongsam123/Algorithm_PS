#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main(void)
{
	int n,num;
	cin>>n;
	
	stack<int> stack;
	string input;
	
	for(int i=0;i<n;i++)
	{
		cin>>input;
		if(input=="push")
		{
			cin>>num;
			stack.push(num);
		}
		else if(input=="top")
		{
			if(stack.empty())
				cout<<-1<<endl;
			else
				cout<<stack.top()<<endl;
		}
		else if(input=="size")
		{
			cout<<stack.size()<<endl;
		}
		else if(input=="empty")
		{
			if(stack.empty())
				cout<<1<<endl;
			else
				cout<<0<<endl;
		}
		else
		{
			if(stack.empty())
				cout<<-1<<endl;
			else 
			{
				cout<<stack.top()<<endl;
				stack.pop();
			}
		}
	}
	
	return 0;
	
}

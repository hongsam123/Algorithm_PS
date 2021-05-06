#include<iostream>
using namespace std;
pair<int, int> people[51];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n,rank[51]={0};
	cin>>n;

	for(int i=0;i<n;i++)
	{
		cin>>people[i].first>>people[i].second;
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(people[i].first>people[j].first && people[i].second>people[j].second)
				rank[j]++;
		}
	}
	
	for(int i=0;i<n;i++)
	{
		cout<<rank[i]+1<<" ";
	}
	
	return 0;
}

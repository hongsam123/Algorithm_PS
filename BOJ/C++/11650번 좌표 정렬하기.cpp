#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	vector<pair<int,int> > v;
	
	int n;
	cin>>n;
	
	v.resize(n);
	
	for(int i=0;i<n;i++)
	{
		cin>>v[i].first;
		cin>>v[i].second;
	}
	
	sort(v.begin(),v.end());
	
	for(int i=0;i<n;i++)
	{
		cout<<v[i].first<<" "<<v[i].second<<'\n';
	}
	
	return 0;
}

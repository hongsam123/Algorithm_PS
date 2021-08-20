#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

int arr[1001][1001];
bool visited[1001];
queue<int> q;

void dfs(int v,int s)
{
	cout<<s<<" ";
	for(int i=1;i<=v;i++)
	{
		if(arr[s][i] && !visited[i])
		{
			visited[i] = true;
			dfs(v,i);
			//인접한 노드에서 바로 dfs() 
		}
	}
}

void bfs(int v,int s)
{
	q.push(s);
	visited[s] = true;
	
	while (!q.empty())
	{
		s = q.front();
		q.pop();
		
		cout<<s<<" ";
		
		//bfs는 인접한 노드를 모두 push한 후 진행
		for(int i=1;i<=v;i++)
		{
			if(arr[s][i] && !visited[i])
			{
				visited[i] = true;
				q.push(i);
			}
		 } 
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int v,e,s;
	cin>>v>>e>>s;
	
	for(int i=0;i<e;i++)
	{
		int a,b;
		cin>>a>>b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}
	
	visited[s] = true;
	dfs(v,s);
	cout<<endl;
	
	memset(visited,false,sizeof(visited));
	bfs(v,s);
	cout<<endl;
	
	return 0;
}

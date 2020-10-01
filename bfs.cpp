#include<iostream>
#include<queue>
#include<vector>
using namespace std;
queue<int>q;
vector<vector<int>>g;
int visited[100000]={0};

void func(int u)
{
	for(int i=0;i<g[u].size();i++)
	{
		if(visited[g[u][i]]==0)
		{
			//visited[g[u][i]]=1;
			q.push(g[u][i]);
			cout<<"pushed "<<g[u][i]<<endl;
			//func(g[u][i]);
		}
	}
	q.pop();
	//if(q.front()==1)
	//	q.pop();
	cout<<"poped "<<u<<endl;
	return;
}

void bfs(int n,int m)
{
	q.push(1);
	cout<<"pushed 1"<<endl;
	visited[1]=0;
	for(int i=0;i<n;i++)
	{
		if(visited[q.front()] == 0)
		{
			visited[q.front()]=1;
			//cout<<"pushed "<<q.front()<<endl;
			func(q.front());
		}
	}

}

int main()
{
	int n,m;
	cin>>n>>m;
	g.resize(n+1);
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=0;i<n+1;i++)
    {
    	cout<<i<<" ";
    	for(auto it: g[i])
    		cout<<" "<<it;
    	cout<<endl;
    }
    bfs(n,m);
}
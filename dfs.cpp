#include<iostream>
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

void addEdge(vector<int>edge[],int u,int v)
{
	edge[u].push_back(v);
	edge[v].push_back(u);
}

void func(int u,vector<int>edge[],int visited[])
{
	visited[u]=1;
	for(int i=0;i<edge[u].size();i++)
		if(visited[edge[u][i]] == 0)
			func(edge[u][i],edge,visited);
}

void dfs(vector<int>edge[],int v)
{
	int visited[100005]={0};
	for(int i=0;i<v;i++)
	{
		if(visited[i] == 0)
			func(i,edge,visited);
	}
}

int main()
{
	int v=5;
	vector<int>edge[100];	
	int visited[100005]={0};
	addEdge(edge, 0, 1); 
    addEdge(edge, 0, 4); 
    addEdge(edge, 1, 2); 
    addEdge(edge, 1, 3); 
    addEdge(edge, 1, 4); 
    addEdge(edge, 2, 3); 
    addEdge(edge, 3, 4); 
    dfs(edge, v); 
    for(int i=0;i<v;i++)
    {
    	for(auto it: edge[i])
    		cout<<it<<" ";
    	cout<<endl;
    }
}
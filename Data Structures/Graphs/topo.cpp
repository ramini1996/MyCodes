#include<bits/stdc++.h>
using namespace std;
int arr[8];
int curr=7;
class Graph
{
	int v;
	list<int>* adj;
	void DFSUtil(int i,bool visited[]);
	public:
		Graph(int v);
		void addEdge(int src,int dest);
		void DFS(int s);		
};


Graph::Graph(int v)
{
	this->v=v;
	adj=new list<int>[v];
}

void Graph::addEdge(int src,int dest)
{
	adj[src].push_back(dest);
}
void Graph::DFSUtil(int i,bool visited[])
{
	visited[i]=true;
	list<int> :: iterator it;
	for(it=adj[i].begin();it!=adj[i].end();it++)
	{
		if(!visited[*it])
			DFSUtil(*it,visited);
	}
	arr[curr]=i;
	curr--;
}

void Graph::DFS(int s)
{
	bool visited[v];
	for(int i=0;i<v;i++)
		visited[i]=false;
	DFSUtil(s,visited);
	for(int i=0;i<v;i++){
		if(!visited[i])
			DFSUtil(i,visited);
	}
		
}

int main()
{
	Graph g(8);
	g.addEdge(0,2);
	g.addEdge(1,2);
	g.addEdge(1,3);
	g.addEdge(2,4);
	g.addEdge(4,5);
	g.addEdge(4,7);
	g.addEdge(3,5);
	g.addEdge(5,6);
	
	g.DFS(0);
	for(int i=0;i<8;i++)
		printf("%d ",arr[i]);
	return 0;
}

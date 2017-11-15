#include<bits/stdc++.h>
using namespace std;

class Graph
{
	int v;
	list<int>* adj;
	void DFSUtil(int s,bool visited[]);
	public:
	 	Graph(int v);	
	 	void addEdge(int u,int v);
	 	void printList();
	 	void DFS(int s);
	 	void BFS(int s);
};
Graph::Graph(int v)
{
	this->v=v;
	adj=new list<int>[v];	
}
void Graph::addEdge(int u,int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}
void Graph::printList()
{
	list<int> :: iterator it;
	for(int i=0;i<v;i++){
		for(it=adj[i].begin();it!=adj[i].end();it++)
			printf("%d ",*it);
		printf("\n");
	}
}
void Graph::DFSUtil(int s,bool visited[])
{
	visited[s]=true;
	printf("%d ",s);
	list<int> :: iterator it;
	for(it=adj[s].begin();it!=adj[s].end();it++){
		if(!visited[*it])
			DFSUtil(*it,visited);
	}
}
void Graph::DFS(int s)
{
	bool visited[v];
	for(int i=0;i<v;i++)
		visited[i]=false;
	DFSUtil(s,visited);
	/*for(int i=0;i<v;i++){
		if(visited[i]==false)
		DFSUtil(i,visited);
	}*/
}
void Graph::BFS(int s)
{
	bool visited[v];
	for(int i=0;i<v;i++)
		visited[i]=false;
	/*int dist[v];
	for(int i=0;i<v;i++)
		dist[i]=INT_MAX;*/
	dist[s]=0;
	queue<int> q;
	q.push(s);
	visited[s]=true;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		printf("%d ",u);
		list<int> :: iterator it;
		for(it=adj[u].begin();it!=adj[u].end();it++)
		{	
			if(!visited[*it]){
				q.push(*it);
				visited[*it]=true;
				//dist[*it]=dist[u]+1;
			}				
		}
	}
	/*cout<<endl;
	for(int i=0;i<v;i++)
		printf("%d ",dist[i]);*/
}
int main()
{
	Graph g(8);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(1,3);
	g.addEdge(2,3);
	g.addEdge(1,4);
	g.addEdge(2,5);
	g.addEdge(3,6);
	g.addEdge(4,7);
	//g.addEdge(5,6);for graph having different components(for DFS)
	//g.printList();
	//g.DFS(1);
	g.BFS(0);
	
	return 0;
}

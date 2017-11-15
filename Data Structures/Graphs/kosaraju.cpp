#include<bits/stdc++.h>
using namespace std;
int ft=0;
int arr[9],arr1[9];
class Graph{
	int v;
	list<int>* adj;
	void DFSUtil(int i,bool visited[]);
	void DFSUtil1(int i,bool visited[]);
	public:
		Graph(int v);
		void addEdge(int u,int v);
		Graph reverseGraph();
		Graph replaceOriginal();
		void DFS();
		void DFS1();
		void print();
};
Graph::Graph(int v)
{
	this->v=v;
	adj=new list<int>[v];
}
void Graph::addEdge(int u,int v)
{
	adj[u].push_back(v);
}
Graph Graph::reverseGraph()
{
	int v=this->v;
	Graph rg(v);
	list<int> :: iterator it;
	for(int i=0;i<v;i++)
	{
		for(it=adj[i].begin();it!=adj[i].end();it++)
		{
			rg.addEdge(*it,i);
		}
	}
	return rg;
}
void Graph::DFSUtil(int i,bool visited[])
{
	visited[i]=true;
	list<int> :: iterator it;
	for(it=adj[i].begin();it!=adj[i].end();it++){
		if(!visited[*it])
			DFSUtil(*it,visited);
	}
	arr[i]=ft;
	arr1[ft]=i;
	ft++;
}
void Graph::DFS()
{
	bool visited[v];
	for(int i=0;i<v;i++)
		visited[i]=false;
	for(int i=v-1;i>=0;i--){
		if(!visited[i]){
			DFSUtil(i,visited);
			
		}
	}
}


void Graph::DFSUtil1(int i,bool visited[])
{
	visited[i]=true;
	printf("%d ",arr1[i]);
	list<int> :: iterator it;
	for(it=adj[i].begin();it!=adj[i].end();it++){
		if(!visited[*it])
			DFSUtil1(*it,visited);
	}
}
void Graph::DFS1()
{
	bool visited[v];
	for(int i=0;i<v;i++)
		visited[i]=false;
	for(int i=v-1;i>=0;i--){
		if(!visited[i]){
			DFSUtil1(i,visited);
			cout<<endl;
		}
	}
}


Graph Graph::replaceOriginal()
{
	int v=this->v;
	Graph fg(v);

	list<int> :: iterator it;
	for(int i=0;i<v;i++){
		for(it=adj[i].begin();it!=adj[i].end();it++){
			fg.adj[arr[i]].push_back(arr[*it]);
		}
	}
	return fg;
}
void Graph::print()
{
	list<int> :: iterator it;
	for(int i=0;i<9;i++)
	{
		for(it=adj[i].begin();it!=adj[i].end();it++)
			printf("%d ",*it);
		cout<<endl;
	}
}
int main()
{
	Graph g(9);
	g.addEdge(0,3);
	g.addEdge(3,6);
	g.addEdge(6,0);
	g.addEdge(8,6);
	g.addEdge(5,8);
	g.addEdge(8,2);
	g.addEdge(2,5);
	g.addEdge(7,5);
	g.addEdge(7,4);
	g.addEdge(4,1);
	g.addEdge(1,7);
	
	Graph rg=g.reverseGraph();
	rg.DFS();//first pass
	Graph fg=g.replaceOriginal();
	fg.DFS1();
	//fg.print();
	return 0;
}

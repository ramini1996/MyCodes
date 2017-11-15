#include<bits/stdc++.h>
using namespace std;

class Graph
{
	int v;
	list<int>* adj;
	void topologicalSortUtil(int v,bool visited[],stack<int> &s);
	public:
		Graph(int v);
		void addEdge(int src,int dest);
		void topologicalSort();
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

void Graph::topologicalSortUtil(int v,bool visited[],stack<int> &s)
{
	visited[v]=true;
	list<int> :: iterator it;
	for(it=adj[v].begin();it!=adj[v].end();it++)
	{
		if(!visited[*it])
		topologicalSortUtil(*it,visited,s);
	}
	s.push(v);
}


void Graph::topologicalSort()
{
	bool visited[v];
	for(int i=0;i<v;i++)
	visited[i]=false;
	stack<int> s;
	for(int i=0;i<v;i++)
	{
		if(visited[i]==false)
		topologicalSortUtil(i,visited,s);
	}
	
	while(!s.empty())
	{
		cout<<s.top()<<" ";
		s.pop();
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
	
	g.topologicalSort();
	return 0;
}

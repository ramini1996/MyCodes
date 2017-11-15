#include<bits/stdc++.h>
using namespace std;

class Graph
{
	int v;
	list<int>* adj;
	void DFSUtil(int s,bool visited[]);
	public:
		Graph(int v);
		void addEdge(int src,int dest);
		void BFS(int s);
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

void Graph::DFSUtil(int s,bool visited[])
{
	visited[s]=true;
	cout<<s<<" ";
	list<int> :: iterator it;
	for(it=adj[s].begin();it!=adj[s].end();it++)
	{
		if(!visited[*it])
		{
			DFSUtil(*it,visited);
		}
	}	
}

void Graph::DFS(int s)
{
	bool visited[v];
	for(int i=0;i<v;i++)
	visited[i]=false;
	
	DFSUtil(s,visited);
}


/*void Graph::BFS(int s)
{
	bool visited[v];
	for(int i=0;i<v;i++)
	visited[i]=false;
	queue<int> q;
	q.push(s);
	visited[s]=true;
	while(!q.empty())
	{
		s=q.front();
		cout<<s<<" ";
		q.pop();
		list<int> :: iterator it;
		for(it=adj[s].begin();it!=adj[s].end();it++)
		{
			if(!visited[*it])
			{
				q.push(*it);
				visited[*it]=true;
			}
		}	
	}
}*/

int main()
{
	Graph g(4);
	g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.DFS(2);
    
    return 0;
}

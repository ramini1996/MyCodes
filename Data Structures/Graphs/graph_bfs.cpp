#include<bits/stdc++.h>
using namespace std;

class Graph
{
	int v;
	list<int> *adj;	
	public:
		Graph(int v);
		void addEdge(int v,int w);
		void BFS(int s);
};

Graph::Graph(int v)
{
	this->v=v;
	adj=new list<int>[v];
}

void Graph::addEdge(int v,int w)
{
	adj[v].push_back(w);
}

void Graph::BFS(int s)
{
	bool visited[v];
	for(int i=0;i<v;i++)
	visited[i]=false;
	
	queue<int> q;
	q.push(s);
	visited[s]=true;
	
	list<int> :: iterator it;
	while(!q.empty())
	{
		s=q.front();
		cout<<s<<" ";
		q.pop();
		for(it=adj[s].begin();it!=adj[s].end();it++)
		{
			if(!visited[*it])
			{
				q.push(*it);
				visited[*it]=true;
			}
		}		
	}
		
}


int main()
{
	Graph g(4);
	g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.BFS(2);
    return 0;
}

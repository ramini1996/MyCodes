#include<bits/stdc++.h>
using namespace std;


class Graph
{
	int v;
	list<pair<int,int> >* adj;
	public:
		Graph(int v);
		void addEdge(int src,int dest,int w);
		void shortestPath(int src);	
};

Graph::Graph(int v)
{
	this->v=v;
	adj=new list<pair<int,int> >[v];
}

void Graph::addEdge(int src,int dest,int w)
{
	adj[src].push_back(make_pair(dest,w));
	adj[dest].push_back(make_pair(src,w));
}

void Graph::shortestPath(int src)
{
	int dist[v];
	for(int i=0;i<v;i++)
	dist[i]=INT_MAX;
	set<pair<int,int> > s;
	s.insert(make_pair(0,src));
	dist[src]=0;
	while(!s.empty())
	{
		pair<int,int> temp=*(s.begin());
		s.erase(s.begin());
		int u=temp.second;
		list<pair<int,int> > :: iterator it;
		for(it=adj[u].begin();it!=adj[u].end();it++)
		{
			int v=(*it).first;
			int w=(*it).second;
			if(dist[v]>dist[u]+w)
			{
				if(dist[v]!=INT_MAX)
				s.erase(s.find(make_pair(dist[v],v)));
								
				dist[v]=dist[u]+w;
				s.insert(make_pair(dist[v],v));
				
			}
		}
	}
	for(int i=0;i<v;i++)
	cout<<dist[i]<<endl;
	
}

int main()
{
	Graph g(6);
	g.addEdge(0,1,5);
	g.addEdge(0,3,9);
	g.addEdge(0,4,2);
	g.addEdge(1,2,2);
	g.addEdge(2,3,3);
	g.addEdge(3,5,2);
	g.addEdge(4,5,3);
	g.shortestPath(0);
	return 0;	
}

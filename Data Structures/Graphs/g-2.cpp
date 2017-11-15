#include<bits/stdc++.h>
using namespace std;

class Graph
{
	int v;
	list<pair<int,int> >* adj;
	public:
	 	Graph(int v);	
	 	void addEdge(int u,int v,int w);
	 	void dijkstra(int s);
};
Graph::Graph(int v)
{
	this->v=v;
	adj=new list<pair<int,int> >[v];	
}
void Graph::addEdge(int u,int v,int w)
{
	adj[u].push_back(make_pair(v,w));
	adj[v].push_back(make_pair(u,w));
}
void Graph::dijkstra(int src)
{
	
	int dist[v];
	for(int i=0;i<v;i++)
		dist[i]=INT_MAX;
	dist[src]=0;
	set<pair<int,int> > s;
	s.insert(make_pair(0,src));
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
				{
					s.erase(s.find(make_pair(dist[v],v)));
				}
				dist[v]=dist[u]+w;
				s.insert(make_pair(dist[v],v));				
			}
		}
	}
	for(int i=0;i<v;i++)
		printf("vertex->%d distance->%d\n",i,dist[i]);
}
int main()
{
	Graph g(6);
	g.addEdge(0,1,5);
	g.addEdge(1,2,2);
	g.addEdge(0,4,2);
	g.addEdge(2,3,3);
	g.addEdge(3,5,2);
	g.addEdge(4,5,3);
	g.addEdge(0,3,9);
	//g.printList();
	g.dijkstra(0);
	
	
	return 0;
}

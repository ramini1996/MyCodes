#include<bits/stdc++.h>
using namespace std;

struct node
{
	int dest;
	struct node* next;
};

struct adjlist
{
	struct node* head;
};

struct graph
{
	int v;
	struct adjlist* array;	
};

struct graph* createGraph(int v)
{
	struct graph* g=(struct graph*)malloc(sizeof(struct graph));
	g->v=v;
	g->array=(struct adjlist*)malloc(v*sizeof(struct adjlist));
	for(int i=0;i<v;i++)
	{
		g->array[i].head=NULL;
	}
	return g;
}

struct node* newNode(int dest)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->dest=dest;
	temp->next=NULL;
	return temp;
}
void addEdge(struct graph* g,int src,int dest)
{
	struct node* temp=newNode(dest);
	temp->next=g->array[src].head;
	g->array[src].head=temp;
	
	temp=newNode(src);
	temp->next=g->array[dest].head;
	g->array[dest].head=temp;	
}


void print(struct graph* g,int s)
{
	for(int i=0;i<g->v;i++)
	{
		struct node* temp=g->array[i].head;
		while(temp!=NULL)
		{
			printf("%d ",temp->dest);
			temp=temp->next;
		}
		cout<<"\n";
	}
}

void bfs(struct graph* g,int s)
{
	int v=g->v;
	bool visited[v];
	for(int i=0;i<v;i++)
	visited[i]=false;
	cout<<s<<" ";
	visited[s]=true;
	queue<node*> q;
	q.push(g->array[s].head);
	while(!q.empty())
	{
		struct node* temp=q.front();
		q.pop();
		cout<<temp->dest<<" ";
		visited[temp->dest]=true;
		while(temp!=NULL)
		{
			if(visited[temp->dest]==false)
			q.push(temp);
			
			temp=temp->next;
		}
	}	
}

int main()
{
		int v=5;
		struct graph* g=createGraph(v);
		addEdge(g,0,1);
		addEdge(g,0,4);
		addEdge(g,4,1);
		addEdge(g,4,3);
		addEdge(g,3,2);
		addEdge(g,3,1);
		addEdge(g,2,1);
		bfs(g,0);
		return 0;
}



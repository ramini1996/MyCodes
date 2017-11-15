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


void print(struct graph* g)
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
		print(g);
		return 0;
}

/*
void addEdge(int a[][5],int src,int dest)
{
	a[src][dest]=1;
	a[dest][src]=1;
}
void print(int a[][5],int v)
{
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			if(a[i][j]==1)
			cout<<j<<" ";
		}	
		cout<<"\n";
	}
}
int main()
{
	int v=5;
	int a[5][5]={0};
	addEdge(a,0,1);
	addEdge(a,0,4);
	addEdge(a,4,1);
	addEdge(a,4,3);
	addEdge(a,3,2);
	addEdge(a,3,1);
	addEdge(a,2,1);
	print(a,v);
	return 0;
}*/

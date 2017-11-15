#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node* next;
};
struct graph
{
	int v;
	struct node* array;
};

struct graph* createGraph(int v)
{
	struct graph* g=(struct graph*)malloc(sizeof(struct graph));
	g->v=v;
	g->array=(struct node*)malloc(v*sizeof(struct node));
	for(int i=0;i<v;i++)
	{
		g->array[i].data=i;
		g->array[i].next=NULL;
	}
	return g;
}

void addEdge(struct graph* g,int src,int dest)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=dest;
	temp->next=g->array[src].next;
	g->array[src].next=temp;
}
void print(struct graph* g)
{
	for(int i=0;i<g->v;i++)
	{
		struct node* temp=&(g->array[i]);
		while(temp!=NULL)
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
}

int main()
{
	int v=6;
	struct graph* g=createGraph(v);
	addEdge(g,0,1);
	addEdge(g,0,4);
	addEdge(g,0,5);
	addEdge(g,1,3);
	addEdge(g,1,4);
	addEdge(g,2,1);
	addEdge(g,3,2);
	addEdge(g,3,4);
	print(g);
	return 0;		
}

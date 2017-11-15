#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	struct node* next;	
};

void insertatStart(struct node** head,int data)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->next=*head;
	*head=temp;
}
void insertatEnd(struct node** head,int data)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->next=NULL;
	if(*head==NULL)
	*head=temp;
	else
	{
		struct node* current=*head;
		while(current->next!=NULL)
		current=current->next;
		current->next=temp;
	}
}

struct node* add(struct node* h1,struct node* h2)
{
	int temp=0,s;
	struct node* p=h1;
	struct node* q=h2;
	struct node* h3=NULL;
	while(p!=NULL && q!=NULL)
	{
		s=p->data+q->data+temp;
		insertatEnd(&h3,s%10);
		temp=s/10;
		p=p->next;
		q=q->next;
	}
	while(p!=NULL)
	{
		s=p->data+temp;
		insertatEnd(&h3,s%10);
		temp=s/10;
		p=p->next;
	}
	while(q!=NULL)
	{
		s=q->data+temp;
		insertatEnd(&h3,s%10);
		temp=s/10;
		q=q->next;
	}
	if(temp!=0)
	insertatEnd(&h3,temp);
	return h3;
}
int main()
{
		struct node* h1=NULL;
		struct node* h2=NULL;
		insertatEnd(&h1,3);
		insertatEnd(&h1,8);
		insertatEnd(&h1,5);
		
		insertatEnd(&h1,4);
		insertatEnd(&h2,6);
		insertatEnd(&h2,2);
		
		struct node* h3=add(h1,h2);

		while(h3!=NULL)
		{
			cout<<h3->data<<" ";
			h3=h3->next;		
		}		
		return 0;	
}


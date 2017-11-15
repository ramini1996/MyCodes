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

struct node* add(struct node* l1,struct node* l2,int carry)
{
	if(l1==NULL && l2==NULL && carry==0)
	return NULL;
	
	struct node* result=(struct node*)malloc(sizeof(struct node));
	int value=carry;
	if(l1!=NULL)
	value+=l1->data;
	if(l2!=NULL)
	value+=l2->data;
	result->data=value%10;
	struct node* more=add(l1!=NULL?l1->next:NULL,l2!=NULL?l2->next:NULL,value>=10?1:0);
	result->next=more;
	return result;
}


int main()
{
	struct node* l1=NULL;
	struct node* l2=NULL;
	struct node* l3;
	insertatEnd(&l1,9);
	insertatEnd(&l1,9);
	insertatEnd(&l1,9);
	
	insertatEnd(&l2,9);
	insertatEnd(&l2,8);
	
	l3=add(l1,l2,0);
	while(l3!=NULL)
	{
		cout<<l3->data<<" ";
		l3=l3->next;
	}
	return 0;	
}

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

struct node* padList(struct node** p,int n)
{
	while(n--)
	insertatStart(p,0);
}

struct node* add(struct node* l1,struct node* l2,int* carry)
{
	if(l1==NULL && l2==NULL)
	return NULL;
	
	struct node* result=(struct node*)malloc(sizeof(struct node));
	result->next=add(l1->next,l2->next,carry);
	int value= *carry + l1->data + l2->data;
	result->data=value%10;
	*carry=value/10;
	return result;
}

struct node* addLists(struct node** l1,struct node** l2)
{
	int count1=0,count2=0;
	struct node* p=*l1;
	while(p!=NULL)
	{
		count1++;
		p=p->next;
	}
	p=*l2;
	while(p!=NULL)
	{
		count2++;
		p=p->next;
	}
	if(count1<count2)
	padList(l1,count2-count1);		
	else if(count2<count1)
	padList(l2,count1-count2);

	int carry=0;
	struct node* l3=add(*l1,*l2,&carry);
	
	if(carry!=0)
	insertatStart(&l3,carry);
	
	return l3;
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
	insertatEnd(&l2,9);
	insertatEnd(&l2,9);
	
	l3=addLists(&l1,&l2);
	while(l3!=NULL)
	{
		cout<<l3->data<<" ";
		l3=l3->next;
	}
	return 0;	
}

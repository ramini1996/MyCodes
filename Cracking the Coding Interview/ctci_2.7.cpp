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


struct node* nodeIntersect(struct node* h1,struct node* h2)
{
	struct node* p=h1;
	struct node* q=h2;
	int c1=1,c2=1,x;
	while(p->next!=NULL)
	{
		c1++;
		p=p->next;
	}
	while(q->next!=NULL)
	{
		c2++;
		q=q->next;
	}
	if(p!=q)
	return NULL;
	
	if(c1>c2)
	{
		x=c1-c2;
		while(x--)
		h1=h1->next;
	}
	else if(c2>c1)
	{
		x=c2-c1;
		while(x--)
		h2=h2->next;
	}
	while(h1!=h2)
	{
		h1=h1->next;
		h2=h2->next;
	}
	return h1;
}


int main()
{
	struct node* head1=NULL;
	insertatEnd(&head1,2);
	insertatEnd(&head1,3);
	insertatEnd(&head1,4);
	insertatEnd(&head1,5);
	insertatEnd(&head1,6);
	insertatEnd(&head1,7);
	insertatEnd(&head1,8);
	insertatEnd(&head1,9);
	
	struct node* ptr=head1;
	while(ptr->data!=6)
	ptr=ptr->next;
	
	struct node* head2=NULL;
	insertatEnd(&head2,12);
	insertatEnd(&head2,14);
	
	struct node* ptr1=head2;
	while(ptr1->next!=NULL)
	ptr1=ptr1->next;
	
	ptr1->next=ptr;
	
	struct node* ans=nodeIntersect(head1,head2);
	if(ans==NULL)
	cout<<"No Intersection";
	else
	cout<<ans->data;
	return 0;	
}

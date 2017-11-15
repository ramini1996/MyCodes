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

int main()
{
		struct node* head=NULL;
		insertatEnd(&head,3);
		insertatEnd(&head,5);
		insertatEnd(&head,8);
		insertatEnd(&head,5);
		insertatEnd(&head,10);
		insertatEnd(&head,2);
		insertatEnd(&head,1);
		
		struct node* p=head;
		struct node* q=head;
		int partition;
		scanf("%d",&partition);
		while(q!=NULL)
		{
			if(q->data<partition)
			{
				int t=q->data;
				q->data=p->data;
				p->data=t;
				p=p->next;		
			}		
			q=q->next;
		}		
		struct node* ptr=head;
		while(ptr!=NULL)
		{
			cout<<ptr->data<<" ";
			ptr=ptr->next;
		}
				
		return 0;	
}


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
		insertatEnd(&head,2);
		insertatEnd(&head,9);
		insertatEnd(&head,9);
		insertatEnd(&head,5);
		insertatEnd(&head,3);
		insertatEnd(&head,8);
	
		insertatEnd(&head,7);
		insertatEnd(&head,7);
		insertatEnd(&head,2);
		insertatEnd(&head,4);
		insertatEnd(&head,0);
		insertatEnd(&head,1);
		insertatEnd(&head,0);
		insertatEnd(&head,6);
		
		
		struct node* ptr=head;
	
		
		while(ptr!=NULL)
		{
			printf("%d ",ptr->data);
			ptr=ptr->next;
		}
	
		cout<<endl;
	
		struct node* p=head;
		struct node* q=NULL;
		set<int> s;
		while(p!=NULL)
		{
			if(s.find(p->data)==s.end())
			{
				s.insert(p->data);
				q=p;
			}
			else
			{
				q->next=p->next;
			}
			p=p->next;
		}
	
	
	
		ptr=head;
	
		
		while(ptr!=NULL)
		{
			printf("%d ",ptr->data);
			ptr=ptr->next;
		}
		return 0;	
}


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

/*struct node* detectLoop(struct node* head)
{
	set<node*> s;
	while(1)
	{
		if(head==NULL)return NULL;
		if(s.find(head)!=s.end())
		return head;
		s.insert(head);
		head=head->next;
	}	
}*/


struct node* findBeginning(struct node* head)
{
	struct node* slow=head;
	struct node* fast=head;
	while(fast!=NULL && fast->next!=NULL)
	{
		slow=slow->next;
		fast=fast->next->next;
		if(slow==fast)
		break;
	}
	
	if(fast==NULL || fast->next==NULL)
	return NULL;
	
	slow=head;
	while(slow!=fast)
	{
		slow=slow->next;
		fast=fast->next;
	}
	return fast;
	
}


int main()
{
	struct node* head=NULL;
	insertatEnd(&head,1);
	insertatEnd(&head,2);
	insertatEnd(&head,3);
	insertatEnd(&head,4);
	insertatEnd(&head,5);
	insertatEnd(&head,6);
	insertatEnd(&head,9);
	insertatEnd(&head,12);
	
	struct node* ptr=head;
	while(ptr->next!=NULL)
	ptr=ptr->next;
	
	struct node* prev=head;
	while(prev->data!=4)
	prev=prev->next;
	
	ptr->next=prev;
	 
	
	struct node* ans=findBeginning(head);
	if(ans==NULL)
	cout<<"No Loop";
	else
	cout<<ans->data;
	return 0;	
}

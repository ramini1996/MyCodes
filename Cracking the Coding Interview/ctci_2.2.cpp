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

int print(struct node* head,int k)
{
	if(head==NULL)
	return 0;
	int index=print(head->next,k)+1;
	if(index==k)
	cout<<head->data;
	return index;
}
/*void printList(struct node* head)
{
	if(head==NULL)
	return;
	print(head->next);
	printf("%d ",head->data);
}*/

int main()
{
		struct node* head=NULL;
		insertatEnd(&head,10);
		insertatEnd(&head,20);
		insertatEnd(&head,30);
		insertatEnd(&head,40);
		insertatEnd(&head,50);
		insertatEnd(&head,60);
	
		insertatEnd(&head,70);
		insertatEnd(&head,80);
		insertatEnd(&head,90);
		insertatEnd(&head,100);
		insertatEnd(&head,110);
		insertatEnd(&head,500);
		insertatEnd(&head,600);
		insertatEnd(&head,143);
		
		
		/*int k;
		scanf("%d",&k); 
		struct node* p=head;
		struct node* q=head;
		while(k--)
		q=q->next;
		while(q!=NULL)
		{
			p=p->next;
			q=q->next;
		}
		cout<<p->data<<endl;*/
		
		int k;
		scanf("%d",&k);
		print(head,k);
		//printList(head);		
		return 0;	
}


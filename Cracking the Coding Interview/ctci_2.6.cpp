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

/*bool isPalindrome(struct node* h1)
{
	struct node* p=h1;
	struct node* h2=NULL;
	while(p!=NULL)
	{
		insertatStart(&h2,p->data);
		p=p->next;
	}
	while(h1!=NULL)
	{
		if(h1->data!=h2->data)
		break;
		h1=h1->next;
		h2=h2->next;
	}
	return (h1==NULL);
}*/


/*bool isPalindrome(struct node* h1)
{
	stack<int> s;
	struct node* p=h1;
	while(p!=NULL)
	{
		s.push(p->data);
		p=p->next;
	}
	
	p=h1;
	while(p!=NULL)
	{
		if(p->data!=s.top())
		break;
		s.pop();
		p=p->next;
	}
	return (p==NULL);
}*/

/*bool isPalindrome(struct node* head)//superb
{
	struct node* slow=head;
	struct node* fast=head;
	
	stack<int> s;
	
	while(fast!=NULL && fast->next!=NULL)
	{
		s.push(slow->data);
		slow=slow->next;
		fast=fast->next->next;	
	}
	
	if(fast!=NULL)
	slow=slow->next;
	
	while(slow!=NULL)
	{
		if(slow->data!=s.top())
		return false;
		s.pop();
		slow=slow->next;
	}	
	return true;
}*/

class Result
{
	public:
		struct node* ptr;
		bool result;
		Result(struct node* ptr,bool result)
		{
			this->ptr=ptr;
			this->result=result;
		}
};

Result isPalindromeRecursive(struct node* head,int length)
{
	if(head==NULL || length<=0)
	{
		 Result r(head,true);
		 return r;
	}
	else if(length==1)
	{
		Result r(head->next,true);
		return r;
	}
	
	Result res=isPalindromeRecursive(head->next,length-2);
	if(!res.result || ((res.ptr)==NULL) )
	return res;
	
	res.result=((res.ptr->data)==(head->data));
	res.ptr=res.ptr->next;
	
	return res;
	
}


bool isPalindrome(struct node* head,int length)
{
	Result res=isPalindromeRecursive(head,length);
	return res.result;
}



int main()
{
	struct node* h1=NULL;
	insertatEnd(&h1,7);
	insertatEnd(&h1,8);
	insertatEnd(&h1,6);
	insertatEnd(&h1,5);
	insertatEnd(&h1,6);
	insertatEnd(&h1,8);
	insertatEnd(&h1,7);
	 
	cout<<isPalindrome(h1,7);
	return 0;
}

#include<iostream>
#include<conio.h>
using namespace std;

class node
{
	public:
		int element;
		node *next;
};

class sll
{
	public:
		node *head;
		sll()
		{
			head = NULL;
		}
		void create();				//create list
		void display();				//display created list
		int getsize();				//length of list
		void rearrange();			//Question 3rd
		void fun(node *temp) ;		//Question 4th
		int getmiddle();			//Question 1 getting middle of list
};

//creating linked list
void sll::create()
{
	cout<<"Linked list Creation :\n";
	int ch=1;
	while(ch!=0)
	{
		node *temp;
		node *p;
		temp=new node;
		cout<<"Enter the element:";
		cin>>temp->element;
		
		if(head==NULL)
		{
			head=temp;
			temp->next=NULL;
			p=head;
		}
		else
		{
			p->next=temp;
			temp->next=NULL;
			p=temp;
		}
		cout<<"If you want to continue press 1,else 0.\n";
		cin>>ch;
	}
}

//displaying list
void sll::display()
{
	node *p;
	p=head;
	while(p!=NULL)
	{
		cout<<p->element<<"->";
		p=p->next;
	}
	cout<<" NULL\n";
}

//function for length of list
int sll::getsize()
{
	node *p=NULL;
	p=head;
	int flag=1;
	while(p->next!=NULL)
	{
		p=p->next;
		flag++;
	}
	return flag;
}

//3rd question
void sll::rearrange()
{
	node *p, *q;
	int temp;
	if (!head )
	return;
	p = head; q = head->next;
	while(q)
	{
		temp = p->element;
		p->element = q->element;
		q->element = temp;
		p = q->next;
		q = p ? p->next : 0;
	}
}

//4th question
void sll::fun (node *temp)
{
	if (temp == NULL)
	return;
	fun(temp->next);
	cout<< temp->element<<" ";
}

//function for getting middle element
int sll::getmiddle()
{
	node *p=NULL;
	p=head;
	int len=getsize();
	int mid=len/2;

	for(int i=1;i<mid;i++)
	{
		p=p->next;
	}
	if(len%2==0)							//if list contain even no of elements
	{
		cout<<"Middle elements are "<<p->element<<" and "<<p->next->element<<".\n";
	}
	else									//if list contain odd no of elements
	{
		cout<<"Middle element is "<<p->next->element<<".\n";
	}
}

//main function for menu
int main()
{
	int choice;
	sll list;
	cout<<"\t\tDS THEORY ASSIGNMENT 2\n";
	char c='y';
	while(c=='y')
	{
		cout<<"Give your question no.:\n";
		cout<<"1.Create and dislay and get middle element\n3.Rearrange list display\n4.Passing head in fun(node *temp)\n";
		cin>>choice;
		switch(choice)
		{
			case 1:
				list.create();
				list.display();
				list.getmiddle();
				break;	
				
			case 3:
				list.create();
				cout<<"Original list:";
				list.display();
				list.rearrange();
				cout<<"Rearranged list:";
				list.display();
				break;
				
			case 4:
				list.create();
				cout<<"Original list:";
				list.display();
				cout<<"After passing head in function:\n";
				list.fun(list.head);
				break;				
			
		}
		cout<<"\nDo you want another choice..press y\n";
		c=getch();
	}
	
	return 0;
}

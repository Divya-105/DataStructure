
#include<iostream>
#include<conio.h>

using namespace std;

//student class with different fields
class Student
{
	public:
	int roll_no;
	string name;
	float cgpa;
	int prn;
	float HSCmarks;
	Student *next;
	
};

//students register class for different functions and manipulating list
class StudentsRegister
{
	private:
		Student *head=NULL;
			
	public:
		int ch,choice;
		
		StudentsRegister()
		{
			head=NULL;
		}
		void CreateList();
		void DisplayList();
		void InsertStudent();
		void DeleteStudent();
		void ReverseList();
		void SortingRollNos();
		void UpdateRollNo();
		void SearchRollNo();
};

//function for creating students' list
void StudentsRegister::CreateList()
{
	int n;
	Student *temp=NULL;
	Student *p=NULL;	
	cout<<"Enter the total no of students:";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		if(head==NULL)
		{
			head=new(Student);
			cout<<"Enter the Students's first name:"<<endl;
			cin>>head->name;
			cout<<"Enter the roll no.:";
			cin>>head->roll_no;
			cout<<"Enter the prn no:"<<endl;
			cin>>head->prn;
			cout<<"Enter the Students's FY cgpa:"<<endl;
			cin>>head->cgpa;
			cout<<"Enter HSC percentage aggregate:"<<endl;
			cin>>head->HSCmarks;
			head->next=NULL;
			p=head;	
		}
		else
		{
			temp=new(Student);
			cout<<"Enter the Students's name:"<<endl;
			cin>>temp->name;
			cout<<"Enter the roll no.:";
			cin>>temp->roll_no;
			cout<<"Enter the prn no:"<<endl;
			cin>>temp->prn;
			cout<<"Enter the Students's FY cgpa:"<<endl;
			cin>>temp->cgpa;
			cout<<"Enter HSC percentage aggregate:"<<endl;
			cin>>temp->HSCmarks;
			temp->next=NULL;
			p->next=temp;
			p=temp;
			
		}
		cout<<endl;
	}
	
}

//inserting student node 
void StudentsRegister::InsertStudent()
{
	int opt;
	Student *temp=NULL;
	Student *p=NULL;
	cout<<"Give your choice:";
	
	//choose one option
	cout<<"1.Insert Student at beginning\n2.Insert Student at end\n3.Insert Student in between\n";
	cin>>choice;
	switch(choice)
	{
		case 1:
			//Insert Student at beginning
			cout<<"Enter Student's info to be Inserted:";
			temp=new(Student);
			cout<<"Enter the Students's first name:"<<endl;
			cin>>temp->name;
			cout<<"Enter the roll no.:";
			cin>>temp->roll_no;
			cout<<"Enter the prn no:"<<endl;
			cin>>temp->prn;
			cout<<"Enter the Students's FY cgpa:"<<endl;
			cin>>temp->cgpa;
			cout<<"Enter HSC percentage aggregate:"<<endl;
			cin>>temp->HSCmarks;
			temp->next=NULL;
			temp->next=head;
			head=temp;
			break;
			
		case 2:
			//Insert Student at end
			p=head;
			while(p->next!=NULL)
			{
				p=p->next;
			}
			
			temp=new(Student);
			cout<<"Enter Student's info to be Inserted:";
			cout<<"Enter the Students's first name:"<<endl;
			cin>>temp->name;
			cout<<"Enter the roll no.:";
			cin>>temp->roll_no;
			cout<<"Enter the prn no:"<<endl;
			cin>>temp->prn;
			cout<<"Enter the Students's FY cgpa:"<<endl;
			cin>>temp->cgpa;
			cout<<"Enter HSC percentage aggregate:"<<endl;
			cin>>temp->HSCmarks;
			temp->next=NULL;
			p->next=temp;
			break;
		
		case 3:
			//Insert Student in between
			int pos,no;
			cout<<"1.Insert Student by position\n2.Insert Student after any roll no\n";
			cin>>opt;
			switch(opt)
			{
				//insert by position
				case 1:
			
					cout<<"Enter the position\n";
					cin>>pos;
					p=head;
					for(int i=1;i<pos-1;i++)
					{
						p=p->next;
					}
					temp=new(Student);
					temp->next=NULL;
					cout<<"Enter Student's info to be Inserted:";
					cout<<"Enter the Students's first name:"<<endl;
					cin>>temp->name;
					cout<<"Enter the roll no.:";
					cin>>temp->roll_no;
					cout<<"Enter the prn no:"<<endl;
					cin>>temp->prn;
					cout<<"Enter the Students's FY cgpa:"<<endl;
					cin>>temp->cgpa;
					cout<<"Enter HSC percentage aggregate:"<<endl;
					cin>>temp->HSCmarks;
					temp->next=p->next;
					p->next=temp;
					
					break;
					
					//insert after roll no
				case 2:
					int roll;
					cout<<"Enter Student's roll no after whom you want to insert:";
					cin>>roll;
					temp=head;
					int flag=0;
					while(temp!=NULL)
					{
						if(temp->roll_no==roll)
						{
							flag=1;
							break;
						}
						temp=temp->next;
					}
					if(flag==0)
					{
						cout<<"Student is not present in the list.\n";
					}
					p=new(Student);
					cout<<"Enter the student's info to be inserted:";
					cout<<"Enter the Students's name:"<<endl;
					cin>>p->name;
					cout<<"Enter the roll no.:";
					cin>>p->roll_no;
					cout<<"Enter the prn no:"<<endl;
					cin>>p->prn;
					cout<<"Enter the Students's FY cgpa:"<<endl;
					cin>>p->cgpa;
					cout<<"Enter HSC percentage aggregate:"<<endl;
					cin>>p->HSCmarks;
					p->next=NULL;
					p->next=temp->next;
					temp->next=p;
					break;
					
        }

}
}

void StudentsRegister::DeleteStudent()
{
	int opt;
	Student *temp=NULL;
	Student *p=NULL;
	cout<<"1.Delete 1st student\n2.Delete last student\n3.Delete student somewhere in betwwen\n";
	cin>>ch;
	switch(ch)
	{
		case 1:
			//delete 1st student
			temp=head;
			head=head->next;
			delete(temp);
			break;
			
		case 2:
			//delete at end
			p=head;
			while(p->next->next!=NULL)
			{
				p=p->next;
			}
 			delete(p->next);
			p->next=NULL;
			break;

		case 3:
			//delete in between
			cout<<"1.Delete student by position\n2.Delete student by roll no\n";
			cin>>opt;
			switch(opt)
			{
				//delete by position
				case 1:
					p=head;
					int pos;
					cout<<"Position at which student to be deleted:";
					cin>>pos;
					for(int i=1;i<pos-1;i++)
					{
						p=p->next;
					}
					temp=p->next;
					p->next=temp->next;
					delete(temp);
					break;
							
				//delete by roll no.	
				case 2:
					int no;
					cout<<"Give the roll no of the student to be deleted:";
					cin>>no;
					temp=head;
					int flag;
					while(temp!=NULL)
					{
						if(temp->roll_no==no)
						{
							flag=1;
							break;
						}
						temp=temp->next;
					}
					if(flag==0)
					{
						cout<<"Roll No is not present in the list\n";
					}
					temp=head;
					while(temp->next->roll_no!=no)
					{
						temp=temp->next;
					}
					p=temp->next;
					temp->next=temp->next->next;
					delete(p);
						
					break;
								
					default:
					cout<<"Wrong choice...\n";	
								
					}
							
				}
			}
			
//reversing students' list
void StudentsRegister::ReverseList()
{
	Student *p=NULL;
	Student *q=NULL;
	Student *r=NULL;
	q=head;
	r=q->next;
	while(r!=NULL)
	{
		q->next=p;
		p=q;
		q=r;
		r=q->next;
	}
	q->next=p;
	head=q;
	
}

//alotting sorted roll no.s to students
void StudentsRegister::SortingRollNos()
{
	int data;
	Student *p=NULL;
	Student *q=NULL;
	p=head;
	
	if(head==NULL || head->next==NULL) 
	{
		cout<<"Sorting not required..\n";	
	}
	else
	{
		while(p->next!=NULL)
		{
			q=p->next;
			while(q!=NULL)
			{
				if(p->roll_no > q->roll_no)
				{
					data=p->roll_no;
					p->roll_no=q->roll_no;
					q->roll_no=data;
				}
				q=q->next;
			}
			p=p->next;
		}
	}
	cout<<"Students with sorted roll no.s are:\n";
}	

void StudentsRegister::UpdateRollNo()
{
	Student *temp=NULL;
	int no,val;
	cout<<"Give the roll no of the student to be updated:";
	cin>>no;
	cout<<"Give the new roll no:";
	cin>>val;
	temp=head;
	int flag;
	while(temp!=NULL)
	{
		if(temp->roll_no==no)
		{
			flag=1;
			temp->roll_no=val;
			break;
		}
		temp=temp->next;
	}
	if(flag==0)
	{
		cout<<"Roll No is not present in the list\n";
	}
	
	
}

void StudentsRegister::SearchRollNo()
{
	Student *temp=NULL;
	int no;
	cout<<"Give the roll no of the student to be searched:";
	cin>>no;
	temp=head;
	int flag;
	while(temp!=NULL)
	{
		if(temp->roll_no==no)
		{
			flag=1;
			cout<<"Name:"<<temp->name<<"\nRoll no. :"<<temp->roll_no<<"\nCGPA :"<<temp->cgpa<<"\nPRN no. :"<<temp->prn<<"\nHSC Percentage :"<<temp->HSCmarks<<endl;
			break;
		}
		temp=temp->next;
	}
	if(flag==0)
	{
		cout<<"Roll No is not present in the list\n";
	}
	
}
//display students' list
void StudentsRegister::DisplayList()
{
	Student *p=NULL;
	p=head;
	cout<<"Students' Register:\n";
	while(p!=NULL)
	{
		cout<<"Name:"<<p->name<<"\nRoll no. :"<<p->roll_no<<"\nCGPA :"<<p->cgpa<<"\nPRN no. :"<<p->prn<<"\nHSC Percentage :"<<p->HSCmarks;
		p=p->next;
		cout<<endl;
		cout<<"\t||\n\t"<<"\\/\n";
	}
	cout<<"END OF LIST.."<<endl;
	
}

//main function
int main()
{
	StudentsRegister obj;
	
	int choice;
	cout<<"\tMIT Academy of Engineering, Alandi, PUNE...!\t\n";
	cout<<"\t\t.....Placement Information System.....\n";
	cout<<"First create your register..so choose 1.\n";

	char c='y';
	while (c=='y')
	{
	cout<<"1.Create Students' register\n2.Display the students' register\n3.Insert student to the list\n4.Deleting student from the list\n";
	cout<<"5.Reversing the list\n6.Sorting the roll numbers:\n7.Updating the roll no\n8.Searching for a roll no\n";
	cout<<"Enter your choice:\n";
	cin>>choice;
	
	switch(choice)	
	{
		case 1:
			obj.CreateList();				//calling function to create a list 
			break;
		
		case 2:
			obj.DisplayList();				//calling function to display the list
			break;
			
		case 3:
			obj.InsertStudent();			//calling function to insert a student
			obj.DisplayList();
			break;
			
		case 4:
			obj.DeleteStudent();			//calling function to delete a student
			obj.DisplayList();
			break;
		
		case 5:
			obj.ReverseList();				//calling function to reverse the singly linked list and print it
			obj.DisplayList();
			break;
		
		case 6:
			obj.SortingRollNos();		//calling function to allot sorted roll no.s to students
			obj.DisplayList();
			break;
			
		case 7:
			obj.UpdateRollNo();
			obj.DisplayList();
			break;
		
		case 8:
			obj.SearchRollNo();
			break;
			
		default:
			cout<<"Oops.! Wrong choice.Make another choice. Press enter."<<endl;
	}
	cout<<"Do you want to make another choice? Then press y.."<<endl;
	c=getch();
	}
	
return 0;
}





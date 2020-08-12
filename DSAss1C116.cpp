/* GHARSANSAAR market sales have received an order from a grocery shop for different brands of sugar of different amount in Kgs from some no of customers.
 This is the program for the same..*/
#include<iostream>
#include<conio.h>
using namespace std;

class grocery
{
	public:
		int sugar_amt[50],amount,pos,temp,j,len;
		int damt,p;
		int read_amt();
		void display_amt();
		void insert_amt();
		void update_amt();
		void delete_amt();
};

int grocery::read_amt()
{
	cout<<"Enter the no. of brands:"<<endl;
	cin>>len;
	cout<<"Enter the sugar amount for each brand one by one:\n";
		for(int i=0;i<len;i++)
		{
			cin>>sugar_amt[i];
		}
		return 0;
}

void grocery::display_amt()
{
	cout<<"Amounts of different brands of sugar to be ordered are:"<<endl;
	for(int i=0;i<len;i++)
		{
			cout<<sugar_amt[i]<<" Kgs"<<endl;
		}
}

void grocery::insert_amt()
{
	cout<<"Enter an amount of sugar to be inserted\n";
	cin>>temp;
	cout<<"Enter the brand No. at which it is to be inserted\n";
	cin>>j;
	for(int k=len;k>j;k--)
	{
		sugar_amt[k]=sugar_amt[k-1];
	}
	sugar_amt[j]=temp;
	cout<<"Quantity inserted successfully...!!\nNew shopping list is...."<<endl;
	for(int m=0;m<=len;m++)
	{
		cout<<sugar_amt[m]<<" ";
	}
}


void grocery::update_amt()
{
	cout<<"Enter the brand No. to be updated:";
	cin>>pos;
	cout<<"Enter amount of that Brand to be updated:";
	cin>>amount;
	cout<<"Present amount is:"<<sugar_amt[pos]<<endl;
	sugar_amt[pos]=amount;
	cout<<"Congratulations..!! Required changes are done.!! Updated amounts are...\n"; 
}


void grocery::delete_amt()
{
	int count=0;
	cout<<"Enter the brand amount to be vanished:";
	cin>>damt;

	for(int p=0;p<len;p++)
	{	
		int abc=sugar_amt[p];
		if(abc==damt)
		{
			for(int x=p;x<(len-1);x++)
			{
				sugar_amt[x]= sugar_amt[x+1];			
			}
			cout<<"Element deleted successfully..."<<endl;
	    	for(int ele=0;ele<(len-1);ele++)
	    	{
				cout<<sugar_amt[ele]<<" ";
	    	}
	    	count++;
	    	break;
		}	
		else
		{	  
			continue;
		}
			
	}	
	if(count==0)
	{
		cout<<"Sorry..! Amount not found in the list..";
	}	
}



int main()
{
	int choice,x,n,len;
	cout<<"Give the no of customers :";
	cin>>n;
	grocery customer[n];
	cout<<"Let's read your shopping list first. So in choice press 1.\n";
	for(int x=0;x<n;x++)
	{
	char c='y';
	while (c=='y')
	{
	cout<<"1.Read the shopping list\n2.Display the shopping list\n3.Insert an amount to the list\n4.Updating the list\n5.Deleting an amount from the list\n";
	cout<<"Enter your choice:\n";
	cin>>choice;
	
	switch(choice)	
	{
		case 1:
			customer[x].read_amt();
			break;
		
		case 2:
			customer[x].display_amt();
			break;
			
		case 3:
			customer[x].insert_amt();
			break;
		
		case 4:
			customer[x].update_amt();
			customer[x].display_amt();
			break;
			
		case 5:
			customer[x].delete_amt();
			break;
			
		default:
			cout<<"Oops.! Wrong choice.Make another choice. Press enter."<<endl;
	}
	cout<<"Do you want to make another choice? Then press y.."<<endl;
	c=getch();
	}
	}
	return 0;
	
}






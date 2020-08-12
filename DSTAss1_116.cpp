//Program ro manipulate sales of ever fresh cake shop

#include<iostream>
#include<conio.h>

using namespace std;

class Cake_shop
{
	int cake[4][4];
	public:
		void read_sales();
		void display_sales();
		void monthly_total_sales();
		void flavor_wise_sales();
};

//Read the sales
void Cake_shop::read_sales()
{
	cout<<"Enter the sales:\n\n";
	
	for(int i=0;i<4;i++)
	{
		if(i==0)
		{
			cout<<"For Pineapple cake:\n"; 
		}
		else if(i==1)
		{
			cout<<"For Black Forest cake:\n";
		}
		else if(i==2)
		{
			cout<<"For Red Velvet cake:\n";
		}
		else
		{
			cout<<"For Caramel Apple Cake:\n";
		}
		for(int j=0;j<4;j++)
		{ 
			if(j==0)
			{
				cout<<"For March 2020:\n"; 
			}
			else if(j==1)
			{
				cout<<"For April 2020:\n";
			}
			else if(j==2)
			{
				cout<<"For May 2020:\n";
			}
			else
			{
				cout<<"For June 2020:\n";
			}
			cin>>cake[i][j];
		}
		cout<<endl;
	}
	
	cout<<"Sales have been entered successfully..!!\n\n";
}

//Display the sales
void Cake_shop::display_sales() 
{
	cout<<"CAKE FLAVOR\t\tMAR2020  \tAPRIL2020  \tMAY2020  \tJUN2020\n\n";
	for(int i=0;i<4;i++)
	{
		if(i==0)
		{
			cout<<"****Pineapple cake:\t"; 
		}
		else if(i==1)
		{
			cout<<"Black Forest cake:\t";
		}
		else if(i==2)
		{
			cout<<"Red Velvet cake:\t";
		}
		else
		{
			cout<<"Caramel Apple Cake:\t";
		}
		for(int j=0;j<4;j++)           //printing 2D array of cake shop
		{
			cout<<cake[i][j]<<"\t\t";
		}
		cout<<"\n";
	}
}

//Counting total sales of each month
void Cake_shop::monthly_total_sales()
{
	int mon,sum=0;
	char m='y';
	cout<<"1.March 2020\n2.April 2020\n3.May 2020\n4.June 2020\n";
	while(m=='y')
	{
	cout<<"Enter the month no.:\n";
	cin>>mon;
	switch(mon)
	{
		case 1:
			for(int i=0;i<4;i++)
			{
				sum=sum+cake[i][0];
			}
			break;
		case 2:
			for(int i=0;i<4;i++)
			{
				sum=sum+cake[i][1];
			}
			break;
		case 3:
			for(int i=0;i<4;i++)
			{
				sum=sum+cake[i][2];
			}
			break;
		case 4:
			for(int i=0;i<4;i++)
			{
				sum=sum+cake[i][3];
			}
			break;
		default:
			cout<<"wrong month choice.\n";
	}
	cout<<"Monthly total sale for this month is: "<<sum<<endl;
	cout<<"Press y for next month.\n";
	m=getch();
}
}

//Counting total sales based on flavour
void Cake_shop::flavor_wise_sales()
{
	int flav,sum=0;
	cout<<"Enter your favourite flavor:\n";
	cout<<"1.Pineapple \n2.Black Forest\n3.Red Velvet \n4.Caramel apple\n";
	cin>>flav;
	switch(flav)
	{
		case 1:
			for(int i=0;i<4;i++)
			{
				sum=sum+cake[0][i];
			}
			break;
		case 2:
			for(int i=0;i<4;i++)
			{
				sum=sum+cake[1][i];
			}
			break;
		case 3:
			for(int i=0;i<4;i++)
			{
				sum=sum+cake[2][i];
			}
			break;
		case 4:
			for(int i=0;i<4;i++)
			{
				sum=sum+cake[3][i];
			}
			break;
		default:
			cout<<"wrong flavor choice.\n";
	}
	cout<<"Total sale for this flavor is: "<<sum<<endl;
}

//main body
int main()
{
	Cake_shop cake;
	cout<<"Welcome to \n \t\t.......EVER FRESH CAKE SHOP.........\n";
	cout<<"Read the sales first so chose 1.\n";
	int choice;
	char c='y';
	//choosing any choice desired number of times
	while(c=='y')
	{
		cout<<"Enter your choice:\n";
		cout<<"1. Read the sales value of cake for each month\n";
		cout<<"2. Display table of sales of cakes made\n";	
		cout<<"3. Find total sales of cake for each month\n";
		cout<<"4. To find total sales of cakes as per the flavor of cake\n";
		cin>>choice;
		
		//choice for options
		switch(choice)
		{
			case 1:
				cake.read_sales();
				break;
			case 2:
				cake.display_sales();
				break;
			case 3:
				cake.monthly_total_sales();
				break;
			case 4:
				cake.flavor_wise_sales();
				break;
			default:
				cout<<"You have entered a wrong choice..\n";
		}
		cout<<"Do you want another choice then press y..or else any other key.\n";
		c=getch();		
	}
	return 0;
}

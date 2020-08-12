
#include<iostream>
#include<conio.h>

using namespace std;
//class definition and body

class Sparse_Operations
{
	 const static int MAX=10;
	 int s_mat[MAX][3],temp;
	 public:
		 Sparse_Operations(int r,int c,int l)
		 {
		 s_mat[0][0]=r;
		 s_mat[0][1]=c;
		 s_mat[0][2]=l;
		 temp=0;
		 }
		 //necessary operations on matrix declaration
		 void insert(int r,int c,int val);
		 void print();
		 void transpose(Sparse_Operations a);
		 void transpose();
		 void add(Sparse_Operations b);
		 void multiply(Sparse_Operations t);
};
 
  //method to insert 
 void Sparse_Operations:: insert(int r,int c,int val)
 {
	 if(r > s_mat[0][0] || c > s_mat[0][1])
	 {
	 cout<<" s_mat enetered is not acceptable.";  // row and column values out of limit
	 }
	 else
	 s_mat[temp+1][0]=r;
	 s_mat[temp+1][1]=c;
	 s_mat[temp+1][2]=val;
	 temp++;
 }
 
 //method to print matrix
 void Sparse_Operations::print()
 {
	 int i;
	 cout<<"\nDimension:"<<s_mat[0][0]<<"x"<<s_mat[0][1];
	 cout<<"\nSparse Matrix :\nRow\tColumn\tValue\n";
	 for(i=0;i<=temp;i++)
	 {
	 	cout<<s_mat[i][0]<<"\t"<<s_mat[i][1]<<"\t"<<s_mat[i][2]<<endl;
	 }
 }
 
 //function body to transpose matrix for multiplication
 void Sparse_Operations::transpose(Sparse_Operations a)
 {
	 Sparse_Operations t(s_mat[0][1],s_mat[0][0],s_mat[0][2]);
	 if(temp>0)
	 {
		 for(int i=0;i<s_mat[0][1];i++) //upto total columns
		 {
			 for(int j=1;j<=temp;j++) //upto total rows
			 {
				 if(s_mat[j][1]==i)
				 {
					 t.temp++;
					 t.s_mat[t.temp][0]=s_mat[j][1];
					 t.s_mat[t.temp][1]=s_mat[j][0];
					 t.s_mat[t.temp][2]=s_mat[j][2];
				 }
			 }
		 }
	 }
	 a.multiply(t);
 }
 
 //to print transpose of a matrix
 void Sparse_Operations:: transpose()
 {
 Sparse_Operations t(s_mat[0][1],s_mat[0][0],s_mat[0][2]);
	 if(temp>0)
	 {
		 for(int i=0;i<s_mat[0][1];i++) //run upto columns
		 {
			 for(int j=1;j<=temp;j++) //run upto row values
			 {
				 if(s_mat[j][1]==i)
				 {
					 t.temp++;
					 t.s_mat[t.temp][0]=s_mat[j][1];
					 t.s_mat[t.temp][1]=s_mat[j][0];
					 t.s_mat[t.temp][2]=s_mat[j][2];
				 }
			 }
		 }
	 }
 t.print();
 }
 
 //for addition of matrices
 void Sparse_Operations::add(Sparse_Operations b)
 {
	 int k1=1;
	 int k2=1;
	 Sparse_Operations result(s_mat[0][0],s_mat[0][1],0);
	 if(s_mat[0][0]!=b.s_mat[0][0] || s_mat[0][1]!=b.s_mat[0][1])
	 {
	 	cout<<"Matrices Can't be added";
	 }
	 else
	 {
	 	while(k1<=temp && k2<=b.temp)
		{
		 if(s_mat[k1][0]>b.s_mat[k2][0] ||(s_mat[k1][0]==b.s_mat[k2][0] && s_mat[k1][1]>b.s_mat[k2][1]))
		 {
			 result.insert(b.s_mat[k2][0],b.s_mat[k2][1],b.s_mat[k2][2]);
			 k2++;
		 }
		 else if(s_mat[k1][0]<b.s_mat[k2][0] || (s_mat[k1][0]==b.s_mat[k2][0] && s_mat[k1][1]<b.s_mat[k2][1]))
		 {
			 result.insert(s_mat[k1][0],s_mat[k1][1],s_mat[k1][2]);
			 k1++;
		 }
		 else
		 {
			 int addedval=s_mat[k1][2]+b.s_mat[k2][2];
			 if(addedval!=0)
			 result.insert(s_mat[k1][0],s_mat[k1][1],addedval);
			 k1++;
			 k2++;
		 }
		 }
	 }
 result.s_mat[0][2]=result.temp;
 result.print();
 }
 
 //to obtain multiplication of two matrices
 void Sparse_Operations:: multiply(Sparse_Operations t)
 {
	 int sum,t1,t2, t3=1;
	 Sparse_Operations mresult(s_mat[0][0],t.s_mat[0][1],0);
	 for(int i=0;i<s_mat[0][0];i++)
		 {
		 for(int j=0;j<t.s_mat[0][1];j++)
		 {
			 sum = 0;
			 t1 = 1;
			 t2 = 1;
			 int flag1 = 0;
			 int flag2 = 0;
			 while(t1<=s_mat[0][2])
			 {
			 if(s_mat[t1][0] == i)
			 {
			 	flag1 = 1;
			 	break;
			 }
			 t1++;
			 }
			 while(t2<=t.s_mat[0][2])
			 {
			 	if(t.s_mat[t2][0] == j)
				 {
				 flag2 = 1;
				 break;
				 }
				 t2++;
				 }
				 if(flag1 == 1 && flag2 == 1)
				 {
				 while(s_mat[t1][0]==i && t.s_mat[t2][0]==j)
				 {
					 if(s_mat[t1][1] == t.s_mat[t2][1])
					 {
					 	sum = sum + s_mat[t1][2] * t.s_mat[t2][2];
					 	t1++;
					 	t2++;
					 }
					 else if(s_mat[t1][1]< t.s_mat[t2][1])
					 {
					 	t1++;
					 }
					 else
					 {
					 	t2++;
					 }
					 }
					 if(sum>0)
					 {
					 	mresult.insert(s_mat[t3][0],t.s_mat[t3][1],sum);
					 	t3++;
					 }
				 }
		 	}
	 	 }
 mresult.s_mat[0][2] = t3-1;
 mresult.print();
 }

//main body
int main()
{
 int r,c,l,val,i,choice;
 cout<<"Enter No of Rows of FIRST MATRIX :";
 cin>>r;
 cout<<"Enter No of Column of FIRST MATRIX :";
 cin>>c;
 cout<<"Enter No of Non-Zero elements in FIRST MATRIX :";
 cin>>l;
 cout<<endl;
 Sparse_Operations a(r,c,l);
 for(i=0;i<l;i++)
 {
 cout<<"Enter Row no :";
 cin>>r;
 cout<<"Enter column no :";
 cin>>c;
 cout<<"Enter the value :";
 cin>>val;
 a.insert(r,c,val);
 }
 cout<<endl;
 cout<<"FIRST MATRIX : :";
 a.print();
 cout<<"Enter No of Rows of SECOND MATRIX :";
 cin>>r;
 cout<<"Enter No of Column of SECOND MATRIX :";
 cin>>c;
 cout<<"Enter No of Non-Zero elements in SECOND MATRIX :";
 cin>>l;
 cout<<endl;
 Sparse_Operations b(r,c,l);
 for(i=0;i<l;i++)
 {
 cout<<"Enter Row no :";
 cin>>r;
 cout<<"Enter column no :";
 cin>>c;
 cout<<"Enter the value :";
 cin>>val;
 b.insert(r,c,val);
 }
 cout<<"SECOND MATRIX :\n";
 b.print();
 
 char m='y';
 while(m=='y')
 {
 cout<<"Enter your Choice :\n ";
 cout<<"1:Transpose of Sparse Matrix\n ";
 cout<<"2:Addition of Sparse Matrix \n";
 cout<<"3:Multiplication of Sparse Matrix \n";
 cin>>choice;
 switch(choice)
 {
 case 1:
 cout<<"Transpose of FIRST MATRIX : :"<<endl;
 a.transpose();
 cout<<endl;
 cout<<"Transpose of SECOND MATRIX : :"<<endl;
 b.transpose();
 break;
 case 2:
 cout<<"Addition of matrices :"<<endl;
 a.add(b);
 break;
 case 3:
 cout<<"Multiplication of matrices :"<<endl;
 b.transpose(a);
 break;
 default:
 cout<<"Output cannot be obtained. Try again..";
 }
 
 cout<<"If you want to try again then press y..otherwise any other key\n";
 m=getch();
}
 
 return 0;
}


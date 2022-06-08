#include<iostream>
#include<cmath> 
using namespace std;
#define MAX 10 
class nqueen
{
	public: void placequeen(int);
			int place(int[MAX],int);
		
};
int nqueen :: place(int x[MAX],int k)
{
	int i;
	for(i=1;i<k;i++)
		   if(x[i]==x[k] || abs(x[i]-x[k])==abs(i-k)) return 0;
	return 1;
}
void nqueen :: placequeen(int n)
{
	int k,count,x[MAX],i;
	k=1; count=0;x[k]=0;
	cout<< "\n The different solutions are as follows";
	cout<< "\n\nEach solution indicates the column in which the Queen";
	cout<< "\n Is to be placed in different rows";
	while(k!=0)
	{
		x[k]=x[k]+1;
		while((x[k]<=n) && (!place(x,k)))
		x[k]=x[k]+1;
		if(x[k]<=n)
		{
			if(k==n)
			{
				count=count+1;
				cout<<endl<<endl;
				for(i=1;i<=n;i++)
				cout<<x[i]<<"\t";//getch
	
			}
			else
			{
				k++;
				x[k]=0;
			}
		}
		else
		k--;
	}
}
int main()
{
	int n;
	nqueen nq;
	cout<<"\nEnter the number of Queen :"; cin>>n;
	nq.placequeen(n);return 0;
}

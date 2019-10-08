#include<iostream>
#include <string.h>
using namespace std;
int size,Rsiz,tem;

class FD
{
	private:
		char R[100];
		char Ch[100][100];
		char Lfd[100][100];
		char Rfd[100][100];
		int Loss[100][100];
	public:
		void read();
		void Find();


};

void FD::read()
{
	
	 cout<<"Enter the number of Child Relations\n";
	 cin>>size;

	cout<<"Enter the Attributes of the Parent Relation\n";
	cin>>R;

	
	 cout<<"Enter the Child Relation\n";
	 for(int i=0;i<size;i++)
	 	cin>>Ch[i];

	Rsiz=strlen(R);

	for(int i=0;i<size;i++)
		for(int j=0;j<Rsiz;j++)
			Loss[i][j]=0;

	cout<<"Enter the number of FDs\n";
	cin>>tem;
	cout<<"Enter the functional dependencies(To differentiate the RHS put a '-'\n";
	for(int i=0;i<tem;i++)
	{	cin>>Lfd[i];
		cin>>Rfd[i];
	}

	//cout<<size<<Rsiz<<endl;
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<strlen(Ch[i]);j++)
		{
			for(int k=0;k<Rsiz;k++)
			{
				//if(Ch[i][j]!='\0'
				if(Ch[i][j]==R[k])
				{
					Loss[i][k]=1;
					break;
					
				}
			}
			
		}
	}

	for(int i=0;i<size;i++)
	{
		cout<<"R"<<i+1<<":";
		for(int j=0;j<Rsiz;j++)
			cout<<Loss[i][j]<<" ";
		cout<<endl;
	}
}

int lindex[10];
int rigindex[10];

void FD::Find()
{
	
	
	for(int i=0;i<tem;i++)
	{	for(int j=0;j<strlen(Lfd[i]);j++)
		{
			for(int k=0;k<Rsiz;k++)
			{
				if(R[k]==Lfd[i][j])
				{	lindex[j]=k;
					break;
				}
			
			}
			
		}
		
		for(int j=0;j<strlen(Rfd[i]);j++)
		{
			for(int k=0;k<Rsiz;k++)
			{
				if(R[k]==Rfd[i][j])
				{	rigindex[j]=k;
					break;
				}
			}
		}
		
	
		int flag=1;
		for(int z=0;z<size;z++)
		{
			for(int j=0;j<strlen(Lfd[i]);j++)
			{
				if(Loss[z][lindex[j]]==0)
				{
					flag=0;
					break;
				}
			}	
			if(flag==0)
				break;
		}
		if(flag==1)
		{
			for(int z=0;z<size;z++)
			{
				for(int j=0;j<strlen(Rfd[i]);j++)
				{
					Loss[z][rigindex[j]]=1;
				}
			}
		}
	}
	cout<<endl;
	for(int i=0;i<size;i++)
	{
		cout<<"R"<<i+1<<":";
		for(int j=0;j<Rsiz;j++)
			cout<<Loss[i][j]<<" ";
		cout<<endl;
	}

	int lossless=0;
	int sum=0;

	for(int i=0;i<size;i++)
	{
		sum=0;
		for(int j=0;j<Rsiz;j++)
			sum+=Loss[i][j];
		if(sum==Rsiz)
		{
			lossless=1;
			break;
		}
	}

	if(lossless==1)
		cout<<"Reln is Lossless\n";
	else
		cout<<"Reln is lossy\n";

}

int main()
{
	FD f;
	f.read();
	f.Find();
	return 0;
}

#include<iostream>

using namespace std;

class problem
{
	private:
		int a[10][10];
		int b[10];
	
	
	public:
		
		void celebrity();
		void dosa();
};

void problem::celebrity()
{
	int n,lab,flag=0;
	cout<<"Enter the number of celebrity in the room\n";
	cin>>n;
	int s[n];
	cout<<"Enter their relationship with each other(1 when i=i)\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>a[i][j];
		}
	}
	
	for(int i=0;i<n;i++)
		s[i]=1;
	
	int i=0,j=1;
	while(j<n)
	{
		if(a[i][j]==1)
		{
			s[i]=0;
			i++;
			if(i==j)
				j++;
		}
		else if(a[i][j]==0)
		{
			s[j]=0;
			j++;
		}
	}
	
	for(int i=0;i<n;i++)
	{
		if(s[i]==1)
			lab=i;
	} 
	for(int i=0;i<n;i++)
	{
		
			if(a[i][lab]==0 && i!=lab)
			{	flag=1;
				break;
			}
			else if(a[lab][i]==1 && i!=lab)
			{	flag=1;
				break;
			}
	}
	if(flag==1)
	cout<<"NO CELEBRITY\n";
	else
	cout<<"celebrity is in "<<lab+1<<" position\n";
		
}

void problem::dosa()
{
	int n,temp, count=0;
	cout<<"Enter the number of dosas\n";
	cin>>n;
	cout<<"Enter the radius of each dosa\n";
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
	}
	int max,ax=n-1;
	while(ax>=0)
	{	
		max=0;
		for(int i=0;i<=ax;i++)
		{
			if(b[max]<=b[i])
				max=i;
		}
		
		if(max==ax);
		
		else if(max==0)
		{	count++;
			for(int i=0;i<=ax/2;i++)
			{	
				temp=b[i];
				b[i]=b[ax-i];
				b[ax-i]=temp;
			}
			
		}
		else
		{	count=count+2;
		
		for(int i=0;i<=max/2;i++)
		{	
			temp=b[i];
			b[i]=b[max-i];
			b[max-i]=temp;
		}
		
		for(int i=0;i<=ax/2;i++)
		{	
			temp=b[i];
			b[i]=b[ax-i];
			b[ax-i]=temp;
		}
		}
		ax--;
		
	}
	cout<<"DOSA : ";
	for(int i=0;i<n;i++)
	{
		cout<<b[i]<<" ";
	}
	cout<<endl;
	cout<<"NO. COUNT is "<<count<<endl;
}

int main()
{
	problem p;
	int cho;
	cout<<"Enter choice\n1.celebrity problen\n2.Dosa\n";
	cin>>cho;
	if(cho==1)
	p.celebrity();
	else if(cho==2)
	p.dosa();
	else
	cout<<"Wrong\n";

	return 0;
}
		
		

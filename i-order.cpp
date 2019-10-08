#include<iostream>
#include<math.h>
using namespace std;

int size;
class Web
{
	public:
		int a[100];
		int ca[100];
		void read();
		int select(int a[], int beg, int end, int i,int n);
		int partition(int a[],int beg,int end,int x);
		void print();

};	
	
void Web::read()
{
	cout<<"Enter number of Website\n";
	cin>>size;
	cout<<"Enter number of Hits for Each Website\n";
	
	for(int i=0;i<size;i++)
	{	
		cin>>a[i];
		ca[i]=a[i];
	}
}

int Web::select(int a[], int beg, int end, int I, int n)
{
	int b[n],k=0;
	int val=ceil((float)n/5);
	int m[val];
		
	if(n<=5)
	{
		for(int i=beg;i<=end;i++)
		{	b[k]=a[i];
			k++;
		}
		for(int i=1;i<n;i++)
		{
			for(int j=i;j>0;j--)
			{
				if(b[j]<b[j-1])
				{
					int temp=b[j];
					b[j]=b[j-1];
					b[j-1]=temp;
				}
			
				else break;
			}
		}
	return(b[I-1]);
	}
	
	else
	{
		int ce=floor(n/5),i=0;
		int u=beg;
		while(ce>0)
		{
			m[i]=select(a,u,u+4,3,5);
			i++;
			u+=5;
			ce--;
		}
		
		int z=n%5;
		if(z!=0)
		{	
			m[i]=select(a,u,u+z-1,ceil((float)z/2),z);
			i++;
			
		}
		//cout<<m[0]<<" "<<m[1]<<endl;
		int x=select(m,0,i-1,ceil((float)i/2),i); //T([n/5])  val=ceil(n/5)
		//cout<<x<<endl;
		//int arr[n];
		// for(int arrr=beg;arrr<=end;arrr++)
		// {	arr[arrr]=a[arrr];
		// 	cout<<arr[arrr]<<" ";
		// }
		// cout<<endl;

		int j=partition(a,beg,end,x);
		// cout<<j<<" "<<I<<endl;
		// cout<<"Array"<<endl;
		// for(int vas=0;vas<size;vas++)
		// 	cout<<a[vas]<<" ";
		// cout<<endl;

		if(j==I)
			return (a[j-1]);
		else if(I<j)
			return(select(a,beg,j-2,I,j-beg-1));
		else if(I>j)
			return(select(a,j,end,I-j,end-j+1));
			
	}
	
	//cout<<"\nval - "<<val<<" ce "<<ce<<endl;
}

int Web::partition(int a[], int beg, int end, int x)
{
	int pivot,pi=0;
	for(int da=beg;da<=end;da++)
	{
		if(a[da]==x)
		{
			pi=da;
			break;
		}
	}
	int temp=a[beg];
	a[beg]=a[pi];
	a[pi]=temp;
	pivot=a[beg];
	
	int i=beg+1;
	int j=end;
	while(i<j)
	{	
		
		while(a[i]<=pivot && i<end)
		{	i++;
			
		}
		while(a[j]>pivot && j>beg)
		{	j--;
			
		}
				
		if(i<j)
		{
			int temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	
		temp=a[beg];
		a[beg]=a[j];
		a[j]=temp;
	
return(j+1);

}

void Web::print()
{
	cout<<"WEBSITE   HITS\n";
	for(int i=0;i<size;i++)
	{
		cout<<i+1<<"	"<<a[i]<<endl;
	}
}

int main()
{
	Web w;
	int i;
	w.read();
	cout<<"Enter the value of i\n";
	cin>>i;
	//w.print();
	for(int z=1;z<=i;z++)
	{
		int v=w.select(w.a,0,size-1,z,size);
		cout<<"The "<<z<<"th smallest hits is "<<v<<endl;
		for(int m=0;m<size;m++)
			w.a[m]=w.ca[m];

	}
		 for(int m=0;m<size;m++)
		 	w.a[m]=w.ca[m];
		 cout<<"MEDIAN ___\n";
		 int v=w.select(w.a,0,size-1,ceil((float)size/2),size);
		 cout<<"The median is "<<v<<endl;
	
	
		
	return 0;
}

	

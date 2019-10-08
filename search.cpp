#include<iostream>
#include<cstdlib>

using namespace std;
int rand();

class search
{
	private:
		int a[100];
	
	public:
		void input();
		int LinearSearch(int x);
		int BinarySearch(int x);
};

void search::input()
{
	for(int i=0;i<100;i++)
		a[i]=rand()%200;
	int temp;
	for(int i=1;i<100;i++)
	{
		for(int j=i;j>0;j--)
		{
			if(a[j]<a[j-1])
			{
				temp=a[j];
				a[j]=a[j-1];
				a[j-1]=temp;
			}
			
			else break;
		}
	}
}
		
	


int search::LinearSearch(int x)
{
	int countl=0;
	for(int i=0;i<100;i++)
	{	
		countl++;
		if(x==a[i])
			break;
	}
	
return(countl);
}
		
int search::BinarySearch(int x)
{
	int countb=0;
	int beg=0;
	int end=99;
	int mid;
	while(beg<=end)
	{
		countb++;
		mid=(beg+end)/2;
		if(a[mid]==x)
			{break;}
		
		else if(x<a[mid])
		{
			end=mid-1;
		}
		
		else
		{
			beg=mid+1;
		}
	}
return(countb);
}

int main()
{
	search s;
	float l=0.0,b=0.0;
	int x;
	cout<<"ENTER THE VALUE OF X\n";
	cin>>x;
	for(int i=0;i<1000;i++)
	{
		s.input();
		l+=s.LinearSearch(x);
		
		b+=s.BinarySearch(x);
	}
	cout<<"THE AVERAGE T.C for Linear Search is "<<l/1000<<"	and Binary Search is "<<b/1000<<endl;
	
	
	
	return 0;
}

			
			
		
		
		


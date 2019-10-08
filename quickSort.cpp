#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;

int rand();
int noc=0;
int size=100;
int tcase=1000;
class Sort
{
	private:
		int a[100];
		
	public:
	
		void read();
		void quickSort(int beg,int end);
		int partition(int beg,int end);
		void print();
};

void Sort::read()
{
	srand(time(NULL));
	//cout<<"\nElements are enter\n";
	for(int i=0;i<size;i++)
		a[i]=rand()%100;
}

void Sort::quickSort(int beg,int end)
{
	if(beg<end)
	{	
		int j;
		j=partition(beg,end);
		quickSort(beg,j-1);
		quickSort(j+1,end);
	}
}

int Sort::partition(int beg,int end)
{
	int pivot=a[beg];
	int i=beg;
	int j=end;
	while(i<j)
	{	
		
		while(a[i]<=pivot && i<end && ++noc)
		{	i++;
			
		}
		while(a[j]>pivot && j>beg && ++noc)
		{	j--;
			
		}

		if(i<j)
		{
			int temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	
	{int temp=a[beg];
		a[beg]=a[j];
		a[j]=temp;
	}

return(j);
}

void Sort::print()
{
	for(int i=0;i<size;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}
int main()
{
	Sort s;
	int cases[tcase];
	for(int i=0;i<tcase;i++)
	{s.read();
	//s.print();
	s.quickSort(0,size-1);
	//s.print();
	//cout<<"\nNumber of Comparisons "<<noc<<endl;
	cases[i]=noc;
	noc=0;
	}
	float sum=0;
	for(int i=0;i<tcase;i++)
		sum+=cases[i];
	cout<<"NORMAL : Average Comparisons is "<<sum/tcase<<endl;

	return(0);
}
		
			
	

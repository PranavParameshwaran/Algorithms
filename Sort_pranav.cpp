#include<iostream>
#include<cstdlib>
using namespace std;
int rand();

class Sort
{
	private: 
			int val_is[10];
			int val_ss[10];
			int val_bs[10];
	
	public :
			void insert();
			int Inssort();
			int Selsort();
			int Bubsort();
			
};

void Sort::insert()
{
	
	for(int i=0;i<10;i++)
	{
		val_is[i]=rand()%100;
		val_ss[i]=val_is[i];
		val_bs[i]=val_is[i];
	}
}

int Sort::Inssort()
{

	int temp;
	int count=0;
	cout<<"old :";
	for(int i=0;i<10;i++)
		cout<<val_is[i]<<" ";
	cout<<"\n";
		
	for(int i=1;i<10;i++)
	{
		for(int j=i;j>0;j--)
		{
			count++;
			if(val_is[j]<val_is[j-1])
			{
				temp=val_is[j];
				val_is[j]=val_is[j-1];
				val_is[j-1]=temp;
			}
			
			else break;
		}
	}
	cout<<"new :";
	for(int i=0;i<10;i++)
		cout<<val_is[i]<<" ";
	cout<<"\n";
	return(count);
		
}

int Sort::Selsort()
{
	
	int temp;
	int imax=0;
	int count=0;
	int max=val_ss[0];
	
	cout<<"old :";
	for(int i=0;i<10;i++)
		cout<<val_ss[i]<<" ";
	cout<<"\n";
	for(int i=0;i<10;i++)
	{
		 imax=0;
		 max=val_ss[0];
		
		for(int j=1;j<10-i;j++)
		{
			count++;
			if(val_ss[j]>max)
			{
				max=val_ss[j];
				imax=j;
			}
		}
		
		temp=val_ss[10-i];
		val_ss[10-i]=val_ss[imax];
		val_ss[imax]=temp;
	}
	cout<<"new :";
	for(int i=0;i<10;i++)
		cout<<val_ss[i]<<" ";
	cout<<"\n";
	return(count);			
}

int Sort::Bubsort()
{
	
	int temp;
	int count=0;
	cout<<"old :";
	for(int i=0;i<10;i++)
		cout<<val_bs[i]<<" ";
	cout<<"\n";
	
	for(int i=1;i<10+1;i++)
	{
		int chek=0;
		for(int j=0;j<10-i;j++)
		{
			count++;
			if(val_bs[j]>val_bs[j+1])
			{
				temp=val_bs[j];
				val_bs[j]=val_bs[j+1];
				val_bs[j+1]=temp;
				chek=1;
			}
		}
		if(chek==0)
		break;
	}
	cout<<"new :";
	for(int i=0;i<10;i++)
		cout<<val_bs[i]<<" ";
	cout<<"\n\n";
	
return(count);
}


int main()
{
	Sort s;
	int counti[10];
	int countb[10];
	int counts[10];
	
	for(int i=0;i<10;i++)
	{
		s.insert();
		counti[i]=s.Inssort();
		counts[i]=s.Selsort();
		countb[i]=s.Bubsort();
	}
	cout<<"INSERT  SEL  BUBBLE\n";
	for(int i=0;i<10;i++)
	{
	cout<<counti[i]<<"\t";
	cout<<counts[i]<<"\t";
	cout<<countb[i]<<"\t";
	cout<<"\n";
	}

	


float av=0.0;
for(int i=0;i<10;i++)
{
	av+=(counti[i]/10);
}	
cout<<"\n Insert :"<<av/10;
av=0.0;
	
for(int i=0;i<10;i++)
{
	av+=(float)(counts[i]);
}
av/=100;	

cout<<"\n Select :"<<(float)av;
av=0.0;

for(int i=0;i<10;i++)
{
	av+=(countb[i]/10);
}	
	cout<<"\n bubble :"<<av/10;
	cout<<"\n";


return 0;
}

	









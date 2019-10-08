#include<iostream>
#include<cstdlib>
#include<string.h>

int tcase=1;
int n;
using namespace std;

class data
{
	private:
		char a[10][100];  // a[][] is the word in the dictionary
		char m[10][100];  // m[][] is the meaning in the dictionary
	
	public:
		void read();
		void Msort(int beg,int end);
		void Merge(int beg,int end);
		void insert();
		void print();
		
};

void data::read()
{
	cout<<"enter the number of words\n";
	cin>>n;
	cout<<"Enter the words and its meaning\n";
	for(int i=0;i<n;i++)
	{	cout<<"Word :";
		cin>>a[i];
		cout<<"Meaning :";
		cin>>m[i];
		cout<<"##############\n";
	}
}

void data::Msort(int beg, int end)
{
	if(beg<end)
	{
		int mid=(beg+end)/2;
		Msort(beg, mid);
		Msort(mid+1,end);
		Merge(beg,end);
	}
}

void data::Merge(int beg,int end)
{	
	int i=beg,k;  
	int mid=(beg+end)/2;
	int j=mid+1;  
	char b[end-beg+1][100];
	char m1[end-beg+1][100];
	for(k=0;k<(end-beg+1);k++)
	{
		if(i<=mid && j<=end)
		{
			if(strcmp(a[i],a[j])<0) // strcmpi(a[i],a[j]<0)
			{
				strcpy(b[k],a[i]);//strcpy(b[k],a[i]);
				strcpy(m1[k],m[i]);
				i++;
			}
			else
			{
				strcpy(b[k],a[j]);//strcpy(b[k],a[j]);
				strcpy(m1[k],m[j]);
				j++;
			}
		}
		
		else break;
				
	}


	if(i>mid || j>end)
	{
		if(i>mid)
			{
				for(int ma=j;ma<=end;ma++)
				{	strcpy(b[k],a[ma]);  //strcpy(b[k],a[m]);
					strcpy(m1[k],m[ma]);
					k++;
				}
			}
		else if(j>end)
			{
				for(int ma=i;ma<=mid;ma++)
				{	strcpy(b[k],a[ma]); //strcpy(b[k],a[m]);
					strcpy(m1[k],m[ma]);
					k++;
				}
			}
	}
	
	int z=0;
	for(int ma=beg;ma<=end;ma++)
	{
		strcpy(a[ma],b[z]); //strcpy(a[m],b[z]);
		strcpy(m[ma],m1[z]);
		z++;
	}
	

}

void data::print()
{
	for(int i=0;i<n;i++)
	{	cout<<a[i]<<" - "<<m[i];
		cout<<endl;
	}
}

void data::insert()
{
	char nw[100];
	char nm[100];
	int index;
	//char temp[100];
	cout<<"Enter the word to enter\n";
	cin>>nw;
	cout<<"Enter the meaning of the word\n";
	cin>>nm;
	cout<<"***********\n";
		
	if(strcmp(nw,a[0])<0)
	{	index=0;
		for(int i=n;i>index;i--)
		{
		
			strcpy(a[i],a[i-1]);
			strcpy(m[i],m[i-1]);
		}
		strcpy(a[index],nw);
		strcpy(m[index],nm);
		n++;
	}	
		
			
	else if(strcmp(nw,a[n-1])>0)
	{	
		strcpy(a[n],nw);
		strcpy(m[n],nm);
		n++;
	}
	else
	{
		for(int i=0;i<n-1;i++)
		{
			if(strcmp(nw,a[i])>0 && strcmp(nw,a[i+1])<=0)
			index=i+1;
		}

		for(int i=n;i>index;i--)
		{
		
			strcpy(a[i],a[i-1]);
			strcpy(m[i],m[i-1]);
		}
		strcpy(a[index],nw);
		strcpy(m[index],nm);
		n++;
	}
			
}
int main()
{
	while(tcase)
	{
		cout<<"CASE :"<<tcase<<endl;
		data d;
		d.read();
		cout<<"QUESTION 1\n";
		d.Msort(0,n-1);
		d.print();
		cout<<"QUESTION 2\n";
		d.insert();
		d.print();
		tcase--;
	}
}
	
		

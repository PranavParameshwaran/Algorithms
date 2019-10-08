#include<iostream>
#include<cstdlib>
#include<string.h>

using namespace std;

int size;
int S1=-1,E1=-1,S2=-1,E2=-1;
class DNA
{
	private:
		char S[100];
		char F[100];
	
	public:
		int Stemp[100];
		int Ftemp[100];
		void read();
		void BruteForce();
		void IncDesign();
		int divideNConquerS(int beg,int end);
		int divideNConquerF(int beg,int end);
		void pruning();
		void print();
	
};

void DNA::read()
{
	cout<<"Enter the DNA code for Father\n";
	cin>>F;
	size=strlen(F);
	cout<<"Enter the DNA code for Son (Make sure the number of char are same)\n";
	cin>>S;
	for(int i=0;i<size;i++)
	{
		if(F[i]=='A')
			Ftemp[i]=2;
		else if(F[i]=='C')
			Ftemp[i]=1;
		else if(F[i]=='G')
			Ftemp[i]=-1;
		else if(F[i]=='T')
			Ftemp[i]=-2;
			
		if(S[i]=='A')
			Stemp[i]=2;
		else if(S[i]=='C')
			Stemp[i]=1;
		else if(S[i]=='G')
			Stemp[i]=-1;
		else if(S[i]=='T')
			Stemp[i]=-2;
	}
			
}

void DNA::BruteForce()
{
	cout<<"\nBRUTE FORCE \n";
	int msum1=0,sum1=0,s1=-1,e1=-1; //FATHER
	int sum2=0,msum2=0,s2=-1,e2=-1;	//SON
	for(int i=0;i<size;i++)
	{
		
		for(int j=i;j<size;j++)
		{	
			sum1=0,sum2=0;
			for(int k=i;k<=j;k++)
			{
				sum1+=Ftemp[k];
				sum2+=Stemp[k];
			}
			
			if(msum1<sum1)
			{ 
				msum1=sum1;
				s1=i;
				e1=j;
			}
			if(msum2<sum2)
			{
				msum2=sum2;
				s2=i;
				e2=j;
			}
		}
	}

	for(int i=s1;i<=e1;i++)
	{
		if(s1==-1)
		{	cout<<"null\n";
			break;	
		}
				
			cout<<F[i];
	}
		cout<<"\nMCSSS of father is "<<msum1<<endl;
	
	
	for(int i=s2;i<=e2;i++)
	{
		if(s2==-1)
		{	cout<<"null\n";
			break;
		}
			cout<<S[i];
	}
		cout<<"\nMCSSS of son is "<<msum2<<endl;
	
	
	if((msum1-msum2)>=-10 && (msum1-msum2)<=10)
		cout<<"FATHER - SON TRUE!!!\n";
	else
		cout<<"DNA Mis-Matched\n";
	
}

void DNA::IncDesign()
{
	cout<<"\nINCREMENTAL DESIGN \n";
	int msum1=0,sum1=0,s1=-1,e1=-1; //FATHER
	int sum2=0,msum2=0,s2=-1,e2=-1;	//SON
	
	for(int i=0;i<size;i++)
	{
		sum1=0;
		for(int j=i;j<size;j++)
		{	
			sum1+=Ftemp[j];
			if(msum1<sum1)
			{ 	msum1=sum1;
				s1=i;
				e1=j;
			}
		}
	}
	
	for(int i=0;i<size;i++)
	{
		sum2=0;
		for(int j=i;j<size;j++)
		{	
			sum2+=Stemp[j];
			if(msum2<sum2)
			{ 	msum2=sum2;
				s2=i;
				e2=j;
			}
		}
	}

	for(int i=s1;i<=e1;i++)
	{
		if(s1==-1)
		{	cout<<"null\n";
			break;}
		cout<<F[i];
	}
		cout<<"\nMCSSS of father is "<<msum1<<endl;
	
	
	for(int i=s2;i<=e2;i++)
	{
			if(s2==-1)
			{cout<<"null\n";
			break;}
			cout<<S[i];
		}
		cout<<"\nMCSSS of son is "<<msum2<<endl;
	
	if((msum1-msum2)>=-10 && (msum1-msum2)<=10)
		cout<<"FATHER - SON TRUE!!!\n";
	else
		cout<<"DNA Mis-Matched\n";
				
}

int DNA::divideNConquerF(int beg,int end)
{
	if(beg==end)
	{
		if(Ftemp[beg]<0)
		return(0);
		else return(Ftemp[beg]);
	}
	int mid=(beg+end)/2;
	int Lsub=divideNConquerF(beg,mid);
	int Rsub=divideNConquerF(mid+1,end);
	int rsum=0,rosum=0,losum=0,lsum=0;
	for(int i=mid;i<size;i++)
	{
		rsum=rsum+Ftemp[i];
		if(rsum>rosum)
		{	
			E1=i;
			rosum=rsum;
		}
	}
	for(int i=mid-1;i>=beg;i--)
	{
		lsum=lsum+Ftemp[i];
		if(lsum>losum)
		{
			S1=i;
			losum=lsum;
		}
	}
	int msum=losum+rosum;
	
	if(Lsub>Rsub)
	{
		if(Lsub>msum)
		{	
			S1=beg;
			E1=mid;
			return(Lsub);
		}
		else
			return(msum);
	}
	
	else
	{
		if(Rsub>msum)
		{
			S1=mid+1;
			E1=end;
			return(Rsub);
		}
		else
			return(msum);
	}
	
	
	
}

int DNA::divideNConquerS(int beg,int end)
{
	if(beg==end)
	{
		if(Stemp[beg]<0)
		return(0);
		else return(Stemp[beg]);
	}
	int mid=(beg+end)/2;
	int Lsub=divideNConquerS(beg,mid);
	int Rsub=divideNConquerS(mid+1,end);
	int rsum=0,rosum=0,losum=0,lsum=0;
	for(int i=mid;i<size;i++)
	{
		rsum=rsum+Stemp[i];
		if(rsum>rosum)
		{	
			E2=i;	
			rosum=rsum;
		}
	}
	for(int i=mid-1;i>=beg;i--)
	{
		lsum=lsum+Stemp[i];
		if(lsum>losum)
		{	S2=i;
			losum=lsum;
		}
	}
	int msum=losum+rosum;
	
	if(Lsub>Rsub)
	{
		if(Lsub>msum)
		{	
			S2=beg;
			E2=mid;
			return(Lsub);
		}
		else
			return(msum);
	}
	
	else
	{
		if(Rsub>msum)
		{
			S2=mid+1;
			E2=end;
			return(Rsub);
		}
		else
			return(msum);
	}
	
	
}

void DNA::pruning()
{
	cout<<"\nPRUNING \n";
	int msum1=0,sum1=0,s1=-1,e1=-1; //FATHER
	int sum2=0,msum2=0,s2=-1,e2=-1;	//SON
	for(int i=0;i<size;i++)
	{
		sum1+=Ftemp[i];
		if(sum1<0)
		{	sum1=0;
			if(i!=size-1)
			{	s1=i+1;
				e1=i+1;
			}
		}
		if(msum1<sum1)
		{
			msum1=sum1;
			e1=i;
		}
	}
	for(int i=0;i<size;i++)
	{
		sum2+=Stemp[i];
		if(sum2<0)
		{	sum2=0;
			if(i!=size-1)
			{	s2=i+1;
				e2=i+1;
			}
		}
		if(msum2<sum2)
		{
			msum2=sum2;
			e2=i;
		}
	}
	for(int i=s1;i<=e1;i++)
	{
		if(s1==-1)
		{	cout<<"null\n";
			break;	}	
		cout<<F[i];}
		cout<<"\nMCSSS of father is "<<msum1<<endl;
	
	
	for(int i=s2;i<=e2;i++)
	{
		if(s2==-1)
		{	cout<<"null\n";
			break;}
		cout<<S[i];}
		cout<<"\nMCSSS of son is "<<msum2<<endl;
	
	
	if((msum1-msum2)>=-10 && (msum1-msum2)<=10)
		cout<<"FATHER - SON TRUE!!!\n";
	else
		cout<<"DNA Mis-Matched\n";
	
}

void DNA::print()
{
	for(int i=S1;i<=E1;i++)
	{
		if(S1==-1)
		{	cout<<"null\n";
			break;		}
		cout<<F[i];
	}
	cout<<endl;
	for(int i=S2;i<=E2;i++)
	{
		if(S2==-1)
		{	cout<<"null\n";
			break;}
			cout<<S[i];
	}
	cout<<endl;
}

int main()
{
	DNA d;
	d.read();
	d.BruteForce();
	d.IncDesign();
	d.pruning();
	cout<<"\nDIVIDE AND CONQUER \n";
	int max1=d.divideNConquerF(0,size-1);
	int max2=d.divideNConquerS(0,size-1);
	d.print();
	cout<<"\nMCSSS of father is "<<max1;
	cout<<"\nMCSSS of son is "<<max2<<endl;
	if((max1-max2)>=-10 && (max1-max2)<=10)
		cout<<"FATHER - SON TRUE!!!\n";
	else
		cout<<"DNA Mis-Matched\n";
		
	
		
return 0;
}



#include<iostream>
#include <string.h>
using namespace std;

int size,Rsiz,tem;   // Tem refers the number of FDs
int lindex[10];
int rigindex[10];

/*************  Class *****************************/

class FD
{
	private:
		char R[100];
		char Lfd[100][100];
		char Rfd[100][100];
		char posCK[100];
		int posCKsize;
		char prime[100];
		char nonprime[100];

	public:
		void read();
		void CandidateKey();
		int Closure();


};

/*************  Function Defn  ********************************/
 
void FD::read()
{
	cout<<"Enter the Attributes of the Parent Relation\n";
	cin>>R;

	Rsiz=strlen(R);

	cout<<"Enter the number of FDs\n";
	cin>>tem;
	cout<<"Enter the functional dependencies(To differentiate the RHS put a ' '\n";
	for(int i=0;i<tem;i++)
	{	cin>>Lfd[i];
		cin>>Rfd[i];
	}
}
/****************************************************/

void FD::CandidateKey()
{
	char Rcopy[100];
	strcpy(Rcopy,R);

	for(int i=0;i<tem;i++)
	{
		for(int j=0;j<strlen(Rfd[i]);j++)
		{
			for(int k=0;k<Rsiz;k++)
			{
				if(Rcopy[k]==Rfd[i][j])
				{
					Rcopy[k]='2';
					break;
				}
			}
		}
	}

	int k=0;
	for(int i=0;i<Rsiz;i++)
	{
		if(Rcopy[i]!='2')
		{
			posCK[k]=Rcopy[i];
			k++;
		}
	}

	posCK[k]='\0';
	k++;
	posCKsize=k;

	cout<<posCK<<endl;

}

int isSubstring(char s1[], char s2[])   //    s1 is a substring of s2 or not.
{
	int M = strlen(s1);
	int N = strlen(s2);

	for(int i=0;i<= N-M; i++)
	{
		int j;
		for(j=0; j< M;j++)
			if(s2[i+j] != s1[j])
				break;
		if(j == M)
			return i;

	}
	return -1;
}



int FD::Closure()
{
	char close[100],temp;
	strcpy(close,posCK);
	int check=0,index;
	for(int z=0;z<3;z++)
	{
		for(int i=0;i<tem;i++)
		{
			//for(int j=0;j<strlen(Lfd[i]);j++)
			//{
				check=isSubstring(Lfd[i],close);
				if(check>=0)
				{
					check=-1;
					for(int k=0;k<strlen(Rfd[i]);k++)
					{
						for(int l=0;l<strlen(close);l++)
						{
							if(Rfd[i][k]==close[l])
							{
								check=l;
								break;
							}
						}

						if(check<0)
						{	
							index=strlen(close);
							close[index]=Rfd[i][k];
							close[index+1]='\0';
							index+=2;
						}
					}
				}
			//}
		}
	}

	for(int i=0;i<strlen(close);i++)
		cout<<close[i];
	cout<<endl;
	int csize=strlen(close);
	if(csize==Rsiz)
	{
		for(int i=0;i<posCKsize;i++)
		{
			prime[i]=posCK[i];
		}
		for(int i=0;i<(Rsiz-posCKsize);i++)
		{
			int flag=0;
			for(int j=0;j<Rsiz;j++)
			{	for(int k=0;k<posCKsize;k++)
					if(R[j]==posCK[k])
					{
						flag=1;
					}
				if(flag==0)
				{
					nonprime[i]=R[j];
					break;
				}
			}
		}
	}

		return strlen(close);
}

void NF2()
{
	

}
int main()
{
	FD f;
	f.read();
	f.CandidateKey();
	int csize;
	csize=f.Closure();
	if(csize==Rsiz)
		cout<<"True\n";
	else
		cout<<"False\n";
	return 0;
}

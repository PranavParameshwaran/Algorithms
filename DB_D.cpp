#include<iostream>
#include<string.h>
using namespace std;

class Loss
{
	private:
		int m[200][200];
		char c[200][200];
		char p[200];
		char lfd[200][200];
		char rfd[200][200];
		int an;
		int cn[200];
		int noc;
		int fdn;

	public:
		int lossless;
		void Read();
		void MatrixBuild();
		int Search(char a[], char x);
		void Fill();
		int Check(char d1[]);
		void Update(char d2[]);
		void LossCheck();
		void print();
};


void Loss::Read()
{
	cout<<"Enter Parent relation: ";
	cin>>p;
	an = strlen(p);

	cout<<"Enter number of children relation: ";
	cin>>noc;

	for(int i=0;i<noc;i++)
	{
		cout<<"Enter THE CHILD "<<i+1<<": ";
		cin>>c[i];
		cn[i] = strlen(c[i]);
	}

	MatrixBuild();

	cout<<"Enter number of functional dependencies: ";
	cin>>fdn;

	cout<<"Enter dependencies(in format A B for A->B): \n";
	for(int i=0;i<fdn;i++)
	{
		cout<<"Enter dependency "<<i+1<<": ";
		cin>>lfd[i];
		cin>>rfd[i];
	}
}

void Loss::MatrixBuild()
{
	for(int i=0;i<noc;i++)
	{
		for(int j=0;j<an;j++)
		{
			char ct = (char)(j+65);
			m[i][j] = Search(c[i], ct);
		}
	}
}

int Loss::Search(char a[], char x)
{
	for(int i=0;i<strlen(a);i++)
	{
		if(a[i] == x)
		{
			return 1;
		}
	}
	return 0;
}


void Loss::Fill()
{

	char d1[200], d2[200];
	for(int i=0;i<fdn;i++)
	{
		int tcheck = Check(lfd[i]);
		if(tcheck == 1)
		{
			Update(rfd[i]);
		}
	}
}

int Loss::Check(char d1[])
{
	int flag = 1;

	for(int i=0;i<strlen(d1);i++)
	{
		int tn = (int)(d1[i]) - 65;
		for(int j=0;j<noc;j++)
		{
			if(m[j][tn] == 0)
			{
				flag = 0;
				break;
			}
		}
	}
	return flag;
}

void Loss::Update(char d2[])
{
	for(int i=0;i<strlen(d2);i++)
	{
		int tn = (int)(d2[i]) - 65;
		for(int j=0;j<noc;j++)
		{
			m[j][tn] = 1;
		}
	}
}

void Loss::LossCheck()
{
	int flag = 0;
	for(int i=0;i<noc;i++)
	{
		int tflag = 1;
		for(int j=0;j<an;j++)
		{
			if(m[i][j] == 0)
			{
				tflag = 0;
				break;
			}
		}
		if(tflag == 1)flag = 1;
	}
	if(flag == 1)lossless = 1;
	else lossless = 0;

}

void Loss::print()
{
	cout<<"\n";
	for(int i=0;i<noc;i++)
	{
		cout<<"R"<<i+1<<": ";
		for(int j=0;j<an;j++)
		{
			cout<<m[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"\n";
}

int main()
{
	
	Loss l;

	l.Read();
	l.print();
	l.Fill();
	l.print();
	l.LossCheck();
	if(l.lossless == 1)cout<<"\nIt is Lossless.\n";
	else if(l.lossless == 0)cout<<"\nIt is Lossy.\n";

	
	return 0;
}




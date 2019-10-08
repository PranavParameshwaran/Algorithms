#include<iostream>

using namespace std;

int NcR(int n,int r)
{
	int Mat[r+1][n+1];
	for(int i=0;i<=r;i++)
		for(int j=0;j<=n;j++)
		{
			if(i==0)
				Mat[i][j]=1;
			if(i==j)
				Mat[i][j]=1;
		}
	for(int i=1;i<=r;i++)
		for(int j=i+1;j<=n+i-1;j++)
			Mat[i][j]=Mat[i][j-1]+Mat[i-1][j-1];

	return(Mat[r][n]);
}

int main()
{
	int n,r;
	cout<<"n : ";
	cin>>n;
	cout<<"r : ";
	cin>>r;
	int Ans;
	Ans=NcR(n,r);
	cout<<"The NcR is "<<Ans<<endl;
}
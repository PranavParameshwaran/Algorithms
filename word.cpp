#include<iostream>
#include<string.h>
using namespace std;

int main()
{

	char w[10][100];
	int n;
	cout<<"enter the number of words\n";
	cin>>n;
	cout<<"Enter the words\n";
	for(int i=0;i<n;i++)
		cin>>w[i];
	char temp[100];
	cout<<"\n************\n";	
	for(int i=0;i<n;i++)
		cout<<w[i]<<endl;
	cout<<"************\n";	
	strcpy(temp,w[0]);
	strcpy(w[0],w[2]);
	strcpy(w[2],temp);
		
	for(int i=0;i<n;i++)
		cout<<w[i]<<endl;
}

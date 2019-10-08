#include<iostream>
#include<stdlib.h>

using namespace std;
struct node
{
	int val;
	int wei;
	struct node *nptr;
};

struct node *array[10];


//struct node *end=NULL;

int x;

void MakeGraph(int v1,int v2,int w,int ch)
{
	struct node *tempi = new node;
	tempi->val=v2;
	tempi->wei=w;
	tempi->nptr=array[v1];
	array[v1]=tempi;
		
	//LINK 2
	if(ch==2)
	{
		struct node *tempi1 = new node;
		tempi1->val=v1;
		tempi1->wei=w;
		tempi1->nptr=array[v2];
		array[v2]=tempi1;
	}	
	
}

void print()
{
	
	for(int i=1;i<=x;i++)
	{
		struct node *ptr=array[i];
		cout<<i<<" :";
		//The Error comes in the below code plz rectify
		while(ptr!=NULL)
		{
			cout<<ptr->val<<"("<<ptr->wei<<")"<<" ";
			ptr=ptr->nptr;
		}
		cout<<endl;
	}
}

int main()
{
	int v1,v2,choice,w;
	for(int i=0;i<10;i++)
		array[i]=NULL;
	cout<<"Enter number of nodes\n";
	cin>>x;
	cout<<"Enter directed or undirected graph (Choice = 1 for directed and 2 for undirected)\n";
	cin>>choice;
	
	cout<<"Enter the edges and weights (-666 -666 for breaking)\n";
	while(1)
	{
		cout<<"Edge : ";
		cin>>v1;
		cin>>v2;
		cout<<"Weight : ";
		cin>>w;
		cout<<endl;
		if(v1!=-666 && v2!=-666)
		{
			
			MakeGraph(v1,v2,w,choice);
		}
	
		else
			break;
	}
	
	print();
	return 0;
}

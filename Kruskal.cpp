#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<math.h>

using namespace std;

//****************  Struct Defn   *********************************
struct Comp
{
	int Index;
	int x;
	int y;
};

struct node
{
	int comp1;
	int comp2;
	float wei;
	//struct node *nptr;
};

//****************  Func Defn (not part of Class)  *********************************
bool Condition(node e1,node e2)
{
	return(e1.wei < e2.wei);
}

float distance(int x1,int x2,int y1,int y2)
{
	float ans;
	ans=sqrt(pow((x2-x1),2)+pow((y2-y1),2));
	return ans;	
}

//****************  Class Defn   *********************************
class Kruskal
{
	private:
		int Parent[100];
		node Gh[100];	//The Graph array is this.
		int noe;
		int Nnode;
	
	public:
		void read();
		void Final();
		int find(int u);
		void Union(int r1,int r2);
};

//****************  Func Defn.   ***********************************

void Kruskal::read()
{	
	Label:
	cout<<"Enter number of Comps.\n";
	cin>>Nnode;
	int nn=Nnode;
	if(nn==1)
	{
		cout<<"Please give more inputs coz it cant communicate with any other computer\n\n";
		goto Label;
	}
	
	Comp C[Nnode];
	cout<<"Enter Coordinates\n";
	for(int i=0;i<Nnode;i++)
	{
		cout<<"X and Y: ";
		cin>>C[i].x;
		cin>>C[i].y;
		C[i].Index=i+1;
	}
	noe=(Nnode*(Nnode-1))/2;
	
	for(int i=1;i<=noe;i++)
		Parent[i]=-1;		//Init Parent array with -1.
	
	
	int i=0;
	for(int j=0;j<nn;j++)	//check if -1 comes or not.
	{
		for(int k=j+1;k<nn;k++)
		{
			Gh[i].comp1=C[j].Index;
			Gh[i].comp2=C[k].Index;
			Gh[i].wei=distance(C[j].x,C[k].x,C[j].y,C[k].y);
			i++;
		}
	}
	sort(Gh,Gh+noe,Condition);
	                                              	
}

//********************************************************

void Kruskal::Final()
{
	 int j=0;	//sizeof(T);
	 int nn=Nnode;
	 node T[nn-1];
	 for(int i=0;i<noe;i++)
	 {
	 	if(j<nn)
	 	{
	 		int r1=find(Gh[i].comp1);
	 		int r2=find(Gh[i].comp2);
	 		if(r1!=r2)
	 		{
	 			Union(r1,r2);
	 			T[j].comp1=Gh[i].comp1;
	 			T[j].comp2=Gh[i].comp2;
	 			T[j].wei=Gh[i].wei;
	 			j++;
	 		}
	 	}
	 	else
	 		break;
	 }
	 
	 for(int i=0;i<nn-1;i++)
	 	cout<<T[i].comp1<<" ---"<<T[i].wei<<"--- "<<T[i].comp2<<endl;
}

//*******************************************************

int Kruskal::find(int u)
{
	while(Parent[u]>0)
		u=Parent[u];
	
	return u;
}

//*******************************************************

void Kruskal::Union(int r1,int r2)
{
	if(abs(Parent[r1])>abs(Parent[r2]))
	{
		Parent[r1]=Parent[r1]+Parent[r2];
		Parent[r2]=r1;
	}
	else 
	{
		Parent[r2]=Parent[r1]+Parent[r2];
		Parent[r1]=r2;
	}
}

//************  MAIN  ********************************

int main()
{
	Kruskal k;
	k.read();
	k.Final();
	
	
return 0;
}


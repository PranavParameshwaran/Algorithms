#include<iostream>
#include<limits>
#include<algorithm>

using namespace std;

float inf = numeric_limits<float>::infinity();
float RT1[100][100];
float RT2[100][100];

class SPath
{
	private:
		float C[100][100];
		
		int E;	//Number of Edges
	
	public:
		int V;	//Number of Vertices
		void Read();
		void Bellman(int s);
		void Dijkstra(int s);

};

void SPath::Read()
{
	cout<<"Enter the number of Vertices\n";
	cin>>V;

	for(int i=0;i<V;i++)
		for(int j=0;j<V;j++)
			C[i][j]= inf;
	
	int m,n,w;	
	cout<<"Enter the Edges and the Corresponding Weights (-666 -666 for stopping)[ Vertex 0]\n";
	while(1)
	{
		//cout<<"Edge :";
		cin>>m;
		cin>>n;
		//cout<<"Weight :";
		cin>>w;
		if(m==-666 && n==-666)
			break;
		else
		{
			C[m][n]=w;
			E++;
		}
	}
	
}


void SPath::Dijkstra(int s)
{
	int Mark[V];
	float Dist[V],temp[V];	// Dist is the distance of the node from source till that node.
	int z,j=0;
	
	for(int i=0;i<V;i++)
	{
		Mark[i]=0;
		Dist[i]=C[s][i];
	}
	Mark[s]=1;
	Dist[s]=0;
	
	for(int k=1;k<V;k++)		// V-1 iterations
	{
		j=0;
		for(int i=0;i<V;i++)
			if(Mark[i]==0)
			{
				temp[j]=Dist[i];
				j++;
			}
		sort(temp,temp+j);
		for(int i=0;i<V;i++)
			if(Dist[i]==temp[0] && Mark[i]==0)
			{	Mark[i]=1;
				z=i;
				break;
			}	
				
		for(int i=0;i<V;i++)
			if(Dist[i]>Dist[z]+C[z][i])
				Dist[i]=Dist[z]+C[z][i];
	}
	for(int i=0;i<V;i++)
		RT1[s][i]=Dist[i];


} 

void SPath::Bellman(int s)
{
	float Dist[V];
	for(int i=0;i<V;i++)
	{
		Dist[i]=inf;
	}
	Dist[s]=0;
	int flag=0;
	
	for(int i=0;i<V;i++)
	{
		for(int j=0;j<V;j++)
		{
			for(int k=0;k<V;k++)
			{
				if(i==V-1)
				{	if(Dist[k]>Dist[j]+C[j][k])
						flag++;
				}
				else if(Dist[k]>Dist[j]+C[j][k])
					Dist[k]=Dist[j]+C[j][k];
			}
		}
	}
	if(flag!=0)
	{
		cout<<"NO Shortest path available\n";
		
	}
	else
	{
		for(int i=0;i<V;i++)
		RT2[s][i]=Dist[i];
	}

}

int main()
{
	SPath s;
	s.Read();
	

	
	for(int i=0;i<s.V;i++)
	{
		s.Dijkstra(i);
		s.Bellman(i);
	}
	cout<<"--------------------------DiJkstra----------------------\n";
	for(int i=0;i<s.V;i++)
	{	for(int j=0;j<s.V;j++)
			cout<<RT1[i][j]<<"  ";
		cout<<endl;
	}
	cout<<"--------------------------BELLMAN----------------------\n";
	for(int i=0;i<s.V;i++)
	{	for(int j=0;j<s.V;j++)
			cout<<RT2[i][j]<<"  ";
		cout<<endl;
	}
	return 0;

}

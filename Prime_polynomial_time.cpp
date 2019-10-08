#include<iostream>

using namespace std;

long long c[100];

void coef(int n)
{
	c[0] = 1; 
    for (int i = 0; i < n; c[0] = -c[0], i++)
    { 
        c[1 + i] = 1; 
  
        for (int j = i; j > 0; j--) 
            c[j] = c[j - 1] - c[j]; 
    } 

    for(int i=0;i<n;i++)
    	cout<<c[i]<<" ";
    cout<<endl;

}

bool Prime(int n)
{
	coef(n);
	c[0]++, c[n]--; 
	int i = n; 
    while (i-- && c[i] % n == 0);

    return i < 0;

}

int main() 
{ 
    int n;
    cout<<"Enter number\n";
    cin>>n;
    if (Prime(n)) 
        cout << "Prime" << endl; 
    else
        cout << "Not Prime" << endl; 
    return 0; 
} 